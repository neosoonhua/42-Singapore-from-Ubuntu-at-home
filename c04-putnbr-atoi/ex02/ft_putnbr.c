/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:11:38 by sneo              #+#    #+#             */
/*   Updated: 2023/08/08 17:11:41 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	digits[10];
	int		i;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb == 0)
		write(1, "0", 1);
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb *= -1;
		}
		i = 0;
		while (nb != 0)
		{
			digits[i++] = nb % 10 + '0';
			nb = nb / 10;
		}
		while (i != 0)
			write(1, &digits[--i], 1);
	}
}
/*
#include <stdio.h>

int	main(void)
{
	ft_putnbr(2147483647);
	printf("\n");
	ft_putnbr(-2147483648);
	printf("\n");
	ft_putnbr(5080);
	printf("\n");
	ft_putnbr(-1234);
	printf("\n");
	ft_putnbr(0);
}*/
