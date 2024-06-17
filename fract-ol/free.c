/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 01:20:15 by sneo              #+#    #+#             */
/*   Updated: 2024/06/16 01:20:19 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_t_data(t_data *a)
{
	if (a)
	{
		free(a);
		a = NULL;
	}
}

int	free_many(char *arr1, char *arr2, char **arr3, char *arr4)
{
	char	**temp3;

	if (arr1)
		free(arr1);
	if (arr2)
		free(arr2);
	if (arr3)
	{
		temp3 = arr3;
		while (*arr3)
			free(*arr3++);
		free(temp3);
	}
	if (arr4)
		free(arr4);
	return (0);
}
