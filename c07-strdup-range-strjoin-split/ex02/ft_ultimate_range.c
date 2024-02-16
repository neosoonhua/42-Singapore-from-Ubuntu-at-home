/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:05:05 by sneo              #+#    #+#             */
/*   Updated: 2023/08/14 19:05:07 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*arr;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	arr = (int *)malloc(sizeof(int) * (max - min));
	if (arr == NULL)
		return (-1);
	i = 0;
	while (i < (max - min))
	{
		arr[i] = min + i;
		i++;
	}
	*range = arr;
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
	int	*a = 0;
	int	size;
	int	min = 7;
	int	max = 11;

	size = ft_ultimate_range(&a, min, max);
	if (a != NULL)
	{
		for (int i = 0; i < size; i++)
			printf("%d\n", a[i]);
		free(a);
	}
	else
		printf("Memory allocation failed or invalid range.\n");
}*/
