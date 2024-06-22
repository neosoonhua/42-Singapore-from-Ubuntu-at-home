/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:36:52 by sneo              #+#    #+#             */
/*   Updated: 2024/01/18 19:37:00 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct stack {
	int		*io;
	int		*pf;
}	t_s;

typedef t_s*	t_p;

void	in_out(t_p p, char **argv, char **envp);
void	outfile(t_p p, char **argv);
void	infile(t_p p, char **argv, char **envp);
char	*get_shell(char **envp);
int		free_many(char *arr1, char **arr2, char **arr3);
int		check_argc(int argc);
void	close_pipe_return(int *pipefd);
t_p		construct(void);
int		free_p_and_many(t_p a, char *arr1, char **arr2, char **arr3);

#endif
