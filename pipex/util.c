/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 08:57:22 by sneo              #+#    #+#             */
/*   Updated: 2024/05/23 08:57:27 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_many(char *arr1, char **arr2, char **arr3)
{
	char	**temp;

	if (arr1)
		free(arr1);
	if (arr2)
	{
		temp = arr2;
		while (*arr2)
			free(*arr2++);
		free(temp);
	}
	if (arr3)
	{
		temp = arr3;
		while (*arr3)
			free(*arr3++);
		free(temp);
	}
}

int	check_argc(int argc, char **poss_paths, t_p p)
{
	if (argc != 5)
	{
		free_p_and_many(p, NULL, poss_paths, NULL);
		return (write(1, "Number of arguments should be 4.\n", 33));
	}
	return (0);
}

int	close_pipe_return(int *pipefd)
{
	close(pipefd[0]);
	close(pipefd[1]);
	return (0);
}

t_p	construct(void)
{
	t_p	p;

	p = ft_calloc(1, sizeof(t_s));
	p->io = ft_calloc(2, sizeof(int));
	p->pf = ft_calloc(2, sizeof(int));
	if (!p || !(p->io) || !(p->pf))
		return (0);
	return (p);
}

void	free_p_and_many(t_p a, char *arr1, char **arr2, char **arr3)
{
	if (a)
	{
		free(a->io);
		a->io = NULL;
		free(a->pf);
		a->pf = NULL;
		free(a);
		a = NULL;
	}
	free_many(arr1, arr2, arr3);
}
