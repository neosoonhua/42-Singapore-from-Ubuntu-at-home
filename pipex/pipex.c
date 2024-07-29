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

	if (access(args[0], F_OK) != -1 && access(args[0], X_OK) != -1)
		return (args[0]);
	else
	{
		while (*poss_paths)
		{
			temp_path = ft_strjoin(*poss_paths++, "/");
			path = ft_strjoin(temp_path, args[0]);
			free(temp_path);
			if (access(path, F_OK) != -1 && access(path, X_OK) != -1)
				return (path);
			else
				free(path);
		}
	}
	return (NULL);
}

void	print_2d_char_arr(char **arr)
{
	while (*arr)
		ft_printf(1, "%s\n", *arr++);
}

int	child_0(t_p p, char **poss_paths, char **argv, char **envp)
{
	char	*path;
	char	**args;

	args = split_cmd(argv[2]);
	ft_printf(1, "child_0\n");
	print_2d_char_arr(args);
	ft_printf(1, "End of args for child_0\n");
	path = get_path(args, poss_paths);
	if (!path)
	{
		ft_printf(2, "%s: ", get_shell(envp));
		if (ft_strnstr(argv[2], "/", ft_strlen(argv[2])))
			ft_printf(2, "no such file or directory: %s\n", args[0]);
		else
			ft_printf(2, "command not found: %s\n", args[0]);
		free_p_and_many(p, path, args, poss_paths);
		exit (0);
	}
	dup2(p->io[0], 0);
	dup2(p->pf[1], 1);
	close(p->pf[0]);
	if (execve((const char *)path, args, envp) == -1)
	{
		free_p_and_many(p, path, args, poss_paths);
		write(2, "Could not execute child_0 execve\n", 33);
		exit (0);
	}
	return (1);
}

int	child_1(t_p p, char **poss_paths, char **argv, char **envp)
{
	char	*path;
	char	**args;

	args = split_cmd(argv[3]);
	ft_printf(1, "child_1\n");
	print_2d_char_arr(args);
	ft_printf(1, "End of args for child_1\n");
	path = get_path(args, poss_paths);
	if (!path)
	{
		ft_printf(2, "%s: ", get_shell(envp));
		if (ft_strnstr(argv[3], "/", ft_strlen(argv[3])))
			ft_printf(2, "no such file or directory: %s\n", args[0]);
		else
			ft_printf(2, "command not found: %s\n", args[0]);
		free_p_and_many(p, path, args, poss_paths);
		exit (0);
	}
	dup2(p->io[1], 1);
	dup2(p->pf[0], 0);
	close(p->pf[1]);
	if (execve((const char *)path, args, envp) == -1)
	{
		free_p_and_many(p, path, args, poss_paths);
		write(2, "Could not execute child_1 execve\n", 33);
		exit (0);
	}
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_p		p;
	pid_t	pid[2];
	char	**poss_paths;
	int		status;

	if (check_argc(argc))
		return (0);
	p = calloc_p();
	in_out(p, argv, envp);
	poss_paths = get_poss_paths(envp);
	pipe(p->pf);
	pid[0] = fork();
	if (pid[0] < 0)
		return (free_p_and_many(p, NULL, poss_paths, NULL));
	if (!pid[0] && !child_0(p, poss_paths, argv, envp))
		close_pipe_close_file_return(p);
	waitpid(-1, &status, 0);
	pid[1] = fork();
	if (pid[1] < 0)
		return (free_p_and_many(p, NULL, poss_paths, NULL));
	if (!pid[1] && !child_1(p, poss_paths, argv, envp))
		close_pipe_close_file_return(p);
	close_pipe_close_file_return(p);
	waitpid(-1, &status, 0);
	return (free_p_and_many(p, NULL, poss_paths, NULL));
}
