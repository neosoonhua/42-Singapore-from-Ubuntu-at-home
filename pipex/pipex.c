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

	while (*poss_paths)
	{
		path = ft_strjoin(*poss_paths, "/");
		path = ft_strjoin(path, args[0]);
		if (access(path, X_OK) != -1)
			return (path);
		**(poss_paths)++;
	}
	return (NULL);
}

void	child_0(int *in_out, int *pipefd, char **args, char **poss_paths, char **argv)
{
	char	*path;

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

void	child_1(int *in_out, int *pipefd, char **args, char **poss_paths, char **argv)
{
	char	*path;

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
	while (*envp)
	{
		if (ft_strnstr(*envp, "PATH=", 5))
			return (ft_split(ft_substr(*envp, 5, ft_strlen(*envp) - 5), ':'));
		**(envp)++;
	}
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	int		in_out[2];
	int		pipefd[2];
	pid_t	pid[2];
	char	**poss_paths;
	char	**args;

	poss_paths = get_poss_paths(envp);
	if (argc != 5)
		return (write(1, "Number of arguments should be 5.", 32));
	in_out[0] = open(argv[1], O_RDONLY);
	in_out[1] = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	pipe(pipefd);
	pid[0] = fork();
	if (pid[0] < 0)
		return (0);//perror("fork_0 error"));
	if (!pid[0])
		child_0(in_out, pipefd, args, poss_paths, argv);
	pid[1] = fork();
	if (pid[1] < 0)
		return (0);//perror("fork_1 error"));
	if (!pid[1])
		child_1(in_out, pipefd, args, poss_paths, argv);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(-1, NULL, 0);
	return (1);
}
