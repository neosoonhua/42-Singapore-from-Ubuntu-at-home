/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_calloc_and_close.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:26:57 by sneo              #+#    #+#             */
/*   Updated: 2024/10/19 13:26:59 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	free_many(char *arr1, char **arr2, char **arr3)
{
	char	**temp2;
	char	**temp3;

    if (arr1) {
        free(arr1);
        arr1 = NULL; // Set to NULL after freeing
    }
    if (arr2) {
        temp2 = arr2;
        while (*arr2) {
            free(*arr2);
            *arr2++ = NULL; // Set to NULL after freeing each element
        }
        free(temp2);
        arr2 = NULL; // Set arr2 to NULL after freeing array
    }
    if (arr3) {
        temp3 = arr3;
        while (*arr3) {
            free(*arr3);
            *arr3++ = NULL; // Set to NULL after freeing each element
        }
        free(temp3);
        arr3 = NULL; // Set arr3 to NULL after freeing array
    }
    return 0;
}

int free_p_and_many(t_p p, char *arr1, char **arr2, char **arr3) {
    char **temp;

    if (p) {
        if (p->io) {
            free(p->io);
            p->io = NULL; // Set to NULL after freeing
        }
        if (p->pf) {
            free(p->pf);
            p->pf = NULL; // Set to NULL after freeing
        }
        if (p->env) {
            temp = p->env;
            while (*p->env) {
                free(*p->env);
                *p->env++ = NULL; // Set to NULL after freeing each element
            }
            free(temp);
            p->env = NULL; // Set to NULL after freeing env array
        }
        free(p);
        p = NULL; // Set `p` to NULL after freeing
    }
	// Free other optional arguments
	free_many(arr1, arr2, arr3);
	return (0);
}

void	close_pipe_close_file_return(t_p p)
{
	close(p->pf[0]);
	close(p->pf[1]);
	close(p->io[0]);
	close(p->io[1]);
	return ;
}

t_p	calloc_p(char **my_env)
{
	t_p	p;
	
	p = ft_calloc(1, sizeof(t_s));
	p->io = ft_calloc(2, sizeof(int));
	p->pf = ft_calloc(2, sizeof(int));
	p->env = dupli(my_env);
	if (!p || !(p->io) || !(p->pf) || !(p->env))
		return (0);
	return (p);
}
