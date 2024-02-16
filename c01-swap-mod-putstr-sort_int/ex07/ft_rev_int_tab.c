/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:51:24 by sneo              #+#    #+#             */
/*   Updated: 2023/08/02 16:30:52 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	i;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = temp;
		i++;
	}
}

/*void	ft_rev_int_tab(int *tab, int size)
{
	int	temp[size]; 
	int	i;

	i = 0;
	while (i < size)
	{
		temp[i] = tab[size - i - 1];
		i++;
	}
	i--;
	while (i >= 0)
	{
		tab[i] = temp[i];
		i--;
	}
}*/
/*
int	main(void)
{
	int	*a;
	int	num[6] = {1, 2, 3, 4, 5, 6};
	
	a = num;
	//a = {1, 2, 3}; //Does not work. Don't know why.
	for (int j = 0; j < 6; j++) //Need to match size of array
	{
		printf("%d\n", a[j]);
	}

	ft_rev_int_tab(a, 6); //Need to match size of array
	
	for (int j = 0; j < 6; j++) //Need to match size of array
	{
		printf("%d\n", a[j]);
	}
}*/
