/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:44:37 by sneo              #+#    #+#             */
/*   Updated: 2023/07/31 17:49:20 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
#include <stdio.h>

int	main(void)
{
	int	c;
	int	d;
	int	e;
	int	f;

	c = 107;
	d = 25;
	printf("%d\n", c);
	printf("%d\n", d);
	ft_div_mod(c, d, &e, &f);
	printf("%d\n", c);
	printf("%d\n", d);
	printf("%d\n", e);
	printf("%d\n", f);
}*/
