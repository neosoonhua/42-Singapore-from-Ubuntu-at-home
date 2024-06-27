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

int	free_many(char *arr1, char **arr2, char **arr3)
{
	char	**temp2;
	char	**temp3;

	if (arr1)
		free(arr1);
	if (arr2)
	{
		temp2 = arr2;
		while (*arr2)
			free(*arr2++);
		free(temp2);
	}
	if (arr3)
	{
		temp3 = arr3;
		while (*arr3)
			free(*arr3++);
		free(temp3);
	}
	return (0);
}

int	check_argc(int argc)
{
	if (argc != 5)
	{
		return (write(1, "Number of arguments should be 4.\n", 33));
	}
	return (0);
}

void	close_pipe_return(int *pipefd)
{
	close(pipefd[0]);
	close(pipefd[1]);
	return ;
}

t_p	calloc_p(void)
{
	t_p	p;

	p = ft_calloc(1, sizeof(t_s));
	p->io = ft_calloc(2, sizeof(int));
	p->pf = ft_calloc(2, sizeof(int));
	if (!p || !(p->io) || !(p->pf))
		return (0);
	return (p);
}

int	free_p_and_many(t_p p, char *arr1, char **arr2, char **arr3)
{
	if (p)
	{
		free(p->io);
		p->io = NULL;
		free(p->pf);
		p->pf = NULL;
		free(p);
		p = NULL;
	}
	free_many(arr1, arr2, arr3);
	return (0);
}
