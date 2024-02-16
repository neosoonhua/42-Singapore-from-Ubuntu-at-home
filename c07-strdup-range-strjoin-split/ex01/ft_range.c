/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:26:25 by sneo              #+#    #+#             */
/*   Updated: 2023/08/14 16:26:31 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	if (min >= max)
		return (NULL);
	arr = (int *)malloc(sizeof(int) * (max - min));
	i = 0;
	while (i < (max - min))
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}
/*
#include <stdio.h>

int	main(void)
{
	int	*a;

	a = ft_range(7, 11);
	for (int i = 0; i < 4; i++)
		printf("%d\n", a[i]);
}*/
