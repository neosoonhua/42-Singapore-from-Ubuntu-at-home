/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:39:02 by sneo              #+#    #+#             */
/*   Updated: 2023/07/31 17:31:23 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/*
int	main(void)
{
	int	c;
	int	d;

	c = 25;
	d = 78;
	printf("%d", c);
	printf("%d", d);
	ft_swap(&c, &d);
	printf("%d", c);
	printf("%d", d);
}
*/
