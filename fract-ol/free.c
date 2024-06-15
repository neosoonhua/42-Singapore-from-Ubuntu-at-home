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
