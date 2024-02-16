/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:44:37 by sneo              #+#    #+#             */
/*   Updated: 2023/08/01 13:49:09 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	hold_a;

	hold_a = *a;
	*a = *a / *b;
	*b = hold_a % *b;
}
/*
#include <stdio.h>

int	main(void)
{
	int	c;
	int	d;

	c = 107;
	d = 25;
	printf("%d\n", c);
	printf("%d\n", d);
	ft_ultimate_div_mod(&c, &d);
	printf("%d\n", c);
	printf("%d\n", d);
}*/
