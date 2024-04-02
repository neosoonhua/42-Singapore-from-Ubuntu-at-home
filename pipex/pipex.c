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

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	int		in_out[2];
	pid_t	pid[2];
	char	*path;
	char	**args;

	// printf("%s", getenv("USER"));
	path = "/usr/bin/";
	if (argc != 5)
		return (write(1, "Number of arguments should be 5.", 32));
	// ft_printf(1, "agrc: %i\n", argc);
	in_out[0] = open(argv[1], O_RDONLY);
	in_out[1] = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	pipe(pipefd);
	pid[0] = fork();
	if (pid[0] < 0)
		return (0);//perror("fork_0 error"));
	if (!pid[0])
	{
		dup2(in_out[0], 0);
		dup2(pipefd[1], 1);
		close(pipefd[0]);
		args = ft_split(argv[2], ' ');
		path = ft_strjoin("/usr/bin/", args[0]);
		if (execve((const char *)path, args, NULL) != -1)
		{
			write(1, "Could not execute child_0 execve\n", 33);	
			exit(EXIT_SUCCESS);	
		}
		exit(EXIT_FAILURE);
	}
	pid[1] = fork();
	if (pid[1] < 0)
		return (0);//perror("fork_1 error"));
	if (!pid[1])
	{
		dup2(in_out[1], 1);
		dup2(pipefd[0], 0);
		close(pipefd[1]);
		args = ft_split(argv[3], ' ');
		path = ft_strjoin("/usr/bin/", args[0]);
		if (execve((const char *)path, args, NULL) != -1)
		{
			write(1, "Could not execute child_1 execve\n", 33);	
			exit(EXIT_SUCCESS);	
		}
		exit(EXIT_FAILURE);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(-1, NULL, 0);
	return (1);
}
