/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:03:09 by sneo              #+#    #+#             */
/*   Updated: 2023/10/13 20:03:09 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned long n, unsigned long base, char type)
{
	char	*digits;
	int		i;

	if (type == 'u')
		digits = "0123456789";
	else if (type == 'x')
		digits = "0123456789abcdef";
	else if (type == 'X')
		digits = "0123456789ABCDEF";
	i = 0;
	if (n < base)
	{
		ft_putchar_fd(digits[n], 1);
		i++;
	}
	else
	{
		i += ft_putunsigned(n / base, base, type);
		i += ft_putunsigned(n % base, base, type);
	}
	return (i);
}
