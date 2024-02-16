/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                   :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:51:24 by sneo              #+#    #+#             */
/*   Updated: 2023/08/02 16:30:52 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	j = 0;
	while (j < size - 1)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
				ft_swap(&tab[i], &tab[i + 1]);
			i++;
		}
		j++;
	}
}
/*
int	main(void)
{
	int	*a;
	int	num[6] = {6, 4, 5, 2, 3, 1};
	
	a = num;
	//a = {1, 2, 3}; //Does not work. Don't know why.
	for (int j = 0; j < 6; j++) //Need to match size of array
	{
		printf("%d\n", a[j]);
	}

	ft_sort_int_tab(a, 6); //Need to match size of array
	
	for (int j = 0; j < 6; j++) //Need to match size of array
	{
		printf("%d\n", a[j]);
	}
}*/
