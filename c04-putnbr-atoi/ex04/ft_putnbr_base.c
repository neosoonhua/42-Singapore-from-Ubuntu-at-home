/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:36:01 by sneo              #+#    #+#             */
/*   Updated: 2023/08/10 15:36:06 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((s1[i] - s2[i]) != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	set_base(char *base)
{
	if (ft_strcmp("0123456789", base) == 0)
		return (10);
	else if (ft_strcmp("01", base) == 0)
		return (2);
	else if (ft_strcmp("0123456789ABCDEF", base) == 0)
		return (16);
	else if (ft_strcmp("poneyvif", base) == 0)
		return (8);
	return (0);
}

int	ft_div_mod(int *x, int y)
{
	int	hold_x;

	if (*x > 0)
	{
		hold_x = *x;
		*x = hold_x / y;
		return (hold_x % y);
	}
	else
	{
		hold_x = *x;
		*x = -(hold_x / y);
		return (-(hold_x % y));
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	digits[100];
	int		i;
	int		b;
	int		rem;

	b = set_base(base);
	if (nbr == 0)
		write(1, "0", 1);
	else if (b != 0)
	{
		if (nbr < 0)
			write(1, "-", 1);
		i = 0;
		while (nbr != 0)
		{
			rem = ft_div_mod(&nbr, b);
			digits[i] = rem + '0';
			if (rem > 9 || rem < -9)
				digits[i] += 7;
			i++;
		}
		while (i != 0)
			write(1, &digits[--i], 1);
	}
}
/*
#include <stdio.h>

int	main(void)
{	
	char	*base;

	base = "poneyvif";
	printf("base: %s\n", base);
	ft_putnbr_base(2147483647, base);
	printf("\n");
	ft_putnbr_base(-2147483648, base);
	printf("\n");
	ft_putnbr_base(21, base);
	printf("\n");
	ft_putnbr_base(-12, base);
	printf("\n");
	ft_putnbr_base(0, base);
	printf("\n*************************************\n");
	base = "0123456789ABCDEF";
	printf("base: %s\n", base);
	ft_putnbr_base(2147483647, base);
	printf("\n");
	ft_putnbr_base(-2147483648, base);
	printf("\n");
	ft_putnbr_base(21, base);
	printf("\n");
	ft_putnbr_base(-12, base);
	printf("\n");
	ft_putnbr_base(0, base);
	printf("\n*************************************\n");
	base = "0";
	printf("base: %s\n", base);
	ft_putnbr_base(2147483647, base);
	printf("\n");
	ft_putnbr_base(-2147483648, base);
	printf("\n");
	ft_putnbr_base(21, base);
	printf("\n");
	ft_putnbr_base(-12, base);
	printf("\n");
	ft_putnbr_base(0, base);
	printf("\n*************************************\n");
	base = "01";
	printf("base: %s\n", base);
	ft_putnbr_base(2147483647, base);
	printf("\n");
	ft_putnbr_base(-2147483648, base);
	printf("\n");
	ft_putnbr_base(21, base);
	printf("\n");
	ft_putnbr_base(-12, base);
	printf("\n");
	ft_putnbr_base(0, base);
	printf("\n*************************************\n");
	printf("%d\n", -19 / 10);
	printf("%d\n", -19 % 10);
	printf("\n*************************************\n");
	base = "0123456789";
	printf("base: %s\n", base);
	ft_putnbr_base(2147483647, base);
	printf("\n");
	ft_putnbr_base(-2147483648, base);
	printf("\n");
	ft_putnbr_base(5080, base);
	printf("\n");
	ft_putnbr_base(-1357, base);
	printf("\n");
	ft_putnbr_base(0, base);
	printf("\n");
}*/
