/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:28:20 by sneo              #+#    #+#             */
/*   Updated: 2024/01/18 19:28:28 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_poss_paths(char **envp)
{
	char	*substr;
	char	**split;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			substr = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
			split = ft_split(substr, ':');
			free(substr);
			return (split);
		}
		i++;
	}
	return (NULL);
}

char	*get_path(char **args, char **poss_paths)
{
	char	*temp_path;
	char	*path;

	if (access(args[0], X_OK) != -1)
		return (ft_strjoin("", args[0]));
	else
	{
		while (*poss_paths)
		{
			temp_path = ft_strjoin(*poss_paths++, "/");
			path = ft_strjoin(temp_path, args[0]);
			free(temp_path);
			if (access(path, X_OK) != -1)
				return (path);
			else
				free(path);
		}
	}
	return (NULL);
}

int	child_0(t_p p, char **poss_paths, char **argv, char **envp)
{
	char	*path;
	char	**args;

	args = ft_split(argv[2], ' ');
	path = get_path(args, poss_paths);
	if (!path)
	{
		ft_printf(1, "%s: command not found\n", args[0]);
		free_many(path, args, NULL);
		return (0);
	}
	dup2(p->io[0], 0);
	dup2(p->pf[1], 1);
	close(p->pf[0]);
	if (execve((const char *)path, args, envp) == -1)
	{
		free_many(path, args, NULL);
		write(1, "Could not execute child_0 execve\n", 33);
		return (0);
	}
	free_many(path, args, NULL);
	return (1);
}

int	child_1(t_p p, char **poss_paths, char **argv, char **envp)
{
	char	*path;
	char	**args;

	args = ft_split(argv[3], ' ');
	path = get_path(args, poss_paths);
	if (!path)
	{
		ft_printf(1, "%s: command not found\n", args[0]);
		free_many(path, args, NULL);
		return (0);
	}
	dup2(p->io[1], 1);
	dup2(p->pf[0], 0);
	close(p->pf[1]);
	if (execve((const char *)path, args, envp) == -1)
	{
		free_many(path, args, NULL);
		write(1, "Could not execute child_1 execve\n", 33);
		return (0);
	}
	free_many(path, args, NULL);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_p		p;
	pid_t	pid[2];
	char	**poss_paths;

	p = construct();
	poss_paths = get_poss_paths(envp);
	if (check_argc(argc, poss_paths, p))
		return (0);
	p->io[0] = open(argv[1], O_RDONLY);
	p->io[1] = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	pipe(p->pf);
	pid[0] = fork();
	if (pid[0] < 0)
		return (0);
	if (!pid[0] && !child_0(p, poss_paths, argv, envp))
		close_pipe_return(p->pf);
	pid[1] = fork();
	if (pid[1] < 0)
		return (0);
	if (!pid[1] && !child_1(p, poss_paths, argv, envp))
		close_pipe_return(p->pf);
	close_pipe_return(p->pf);
	free_p_many(p, NULL, poss_paths, NULL);
}
