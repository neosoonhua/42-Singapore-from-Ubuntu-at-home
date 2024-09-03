/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:29:47 by sneo              #+#    #+#             */
/*   Updated: 2023/09/26 12:29:47 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	type_handler2(char type, va_list ptr)
{
	unsigned int		u;
	unsigned long		p;

	if (type == 'p')
	{
		p = va_arg(ptr, unsigned long);
		if (p == 0)
		{
			write(1, "(nil)", 5);
			return (5);
		}
		ft_putstr_fd("0x", 1);
		return (2 + ft_putunsigned(p, 16, 'x'));
	}
	if (ft_strchr("uxX", type))
	{
		u = va_arg(ptr, unsigned int);
		if (type == 'u')
			return (ft_putunsigned(u, 10, type));
		if (ft_strchr("xX", type))
			return (ft_putunsigned(u, 16, type));
	}
	if (type == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

static int	type_handler(char type, va_list ptr)
{
	char				*st;
	int					d;

	if (ft_strchr("puxX%", type))
		return (type_handler2(type, ptr));
	if (type == 'c')
		return (ft_putchar_fd(va_arg(ptr, int), 1));
	if (type == 's')
	{
		st = va_arg(ptr, char *);
		return (ft_putstr_fd(st, 1));
	}
	if (type == 'd' || type == 'i')
	{
		d = va_arg(ptr, int);
		return (ft_putnbr_fd(d, 1));
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	ptr;
	int		num_char;

	num_char = 0;
	va_start(ptr, s);
	while (*s)
	{
		if (*s == '%')
		{
			num_char += type_handler(*(s + 1), ptr);
			s += 2;
		}
		else
		{
			ft_putchar_fd(*(s++), 1);
			num_char++;
		}
	}
	va_end(ptr);
	return (num_char);
}
