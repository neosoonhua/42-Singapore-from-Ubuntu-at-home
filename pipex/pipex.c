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

char	*get_path(char **args, char **poss_paths)
{
	char	*path;
	int		i;

	i = 0;
	while (poss_paths[i])
	{
		path = ft_strjoin(poss_paths[i], "/");
		path = ft_strjoin(path, args[0]);
		if (access(path, X_OK) != -1)
			return (path);
		i++;
	}
	return (NULL);
}

void	child_0(int *in_out, int *pipefd, char **poss_paths, char **argv)
{
	char	*path;
	char	**args;

	dup2(in_out[0], 0);
	dup2(pipefd[1], 1);
	close(pipefd[0]);
	args = ft_split(argv[2], ' ');
	path = get_path(args, poss_paths);
	if (execve((const char *)path, args, NULL) == -1)
	{
		write(1, "Could not execute child_0 execve\n", 33);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}

void	child_1(int *in_out, int *pipefd, char **poss_paths, char **argv)
{
	char	*path;
	char	**args;

	dup2(in_out[1], 1);
	dup2(pipefd[0], 0);
	close(pipefd[1]);
	args = ft_split(argv[3], ' ');
	path = get_path(args, poss_paths);
	if (execve((const char *)path, args, NULL) == -1)
	{
		write(1, "Could not execute child_1 execve\n", 33);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}

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
			substr = NULL;
			return (split);
		}
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	int		in_out[2];
	int		pipefd[2];
	pid_t	pid[2];
	char	**poss_paths;

	poss_paths = get_poss_paths(envp);
	if (argc != 5)
	{
		free_2d_array(poss_paths);
		return (write(1, "Number of arguments should be 4.", 32));
	}
	in_out[0] = open(argv[1], O_RDONLY);
	in_out[1] = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	pipe(pipefd);
	pid[0] = fork();
	if (pid[0] < 0)
		return (0);
	if (!pid[0])
		child_0(in_out, pipefd, poss_paths, argv);
	pid[1] = fork();
	if (pid[1] < 0)
		return (0);
	if (!pid[1])
		child_1(in_out, pipefd, poss_paths, argv);
	close(pipefd[0]);
	close(pipefd[1]);
	free_2d_array(poss_paths);
	return (1);
}
