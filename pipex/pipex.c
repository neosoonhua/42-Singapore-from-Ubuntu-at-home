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

int	main(int argc, char **argv)
{
	int		fd[2];
	int		in_out[2];
	pid_t	pid;
	char	*path;
	char	**args;

	// ft_printf(1, "agrc: %i\n", argc);
	pipe(fd);
	// if (pipe(fd) == -1)
	// {
	// 	perror("pipe error");
	// 	exit(EXIT_FAILURE);
	// }
	pid = fork();
	if (pid == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		ft_printf(1, "Child\n");
		in_out[0] = open(argv[1], O_RDONLY, 0777);
		dup2(in_out[0], 0);
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		args = ft_split(argv[2], ' ');
		path = ft_strjoin("/usr/bin/", args[0]);
		close(in_out[0]);
		if (execve((const char *)path, args, NULL) == -1)
			write(1, "Could not execute child execve\n", 31);	
		exit(EXIT_SUCCESS);	
	}
	else
	{
		waitpid(pid, NULL, 0);
		ft_printf(1, "Parent\n");
		in_out[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		dup2(fd[0], 0);
		dup2(in_out[1], 1);
		close(fd[0]);
		close(fd[1]);
		args = ft_split(argv[3], ' ');
		path = ft_strjoin("/usr/bin/", args[0]);
		close(in_out[1]);
		if (execve((const char *)path, args, NULL) == -1)
			write(1, "Could not execute parent execve\n", 32);	
		exit(EXIT_SUCCESS);
	}
	close(fd[0]);
	close(fd[1]);
	return (0);
}
