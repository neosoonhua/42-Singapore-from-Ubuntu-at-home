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

#include "libft.h"

int	ft_putunsigned(unsigned long n, unsigned long base, char type, int fd)
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
		ft_putchar_fd(digits[n], fd);
		i++;
	}
	else
	{
		i += ft_putunsigned(n / base, base, type, fd);
		i += ft_putunsigned(n % base, base, type, fd);
	}
	return (i);
}

static int	type_handler2(char type, va_list ptr, int fd)
{
	unsigned int		u;
	unsigned long		p;

	if (type == 'p')
	{
		p = va_arg(ptr, unsigned long);
		if (p == 0)
		{
			write(fd, "(nil)", 5);
			return (5);
		}
		ft_putstr_fd("0x", fd);
		return (2 + ft_putunsigned(p, 16, 'x', fd));
	}
	if (ft_strchr("uxX", type))
	{
		u = va_arg(ptr, unsigned int);
		if (type == 'u')
			return (ft_putunsigned(u, 10, type, fd));
		if (ft_strchr("xX", type))
			return (ft_putunsigned(u, 16, type, fd));
	}
	if (type == '%')
		return (ft_putchar_fd('%', fd));
	return (0);
}

static int	type_handler(char type, va_list ptr, int fd)
{
	char				*st;
	int					d;

	if (ft_strchr("puxX%", type))
		return (type_handler2(type, ptr, fd));
	if (type == 'c')
		return (ft_putchar_fd(va_arg(ptr, int), fd));
	if (type == 's')
	{
		st = va_arg(ptr, char *);
		return (ft_putstr_fd(st, fd));
	}
	if (type == 'd' || type == 'i')
	{
		d = va_arg(ptr, int);
		return (ft_putnbr_fd(d, fd));
	}
	return (0);
}

int	ft_printf(int fd, const char *s, ...)
{
	va_list	ptr;
	int		num_char;

	num_char = 0;
	va_start(ptr, s);
	while (*s)
	{
		if (*s == '%')
		{
			num_char += type_handler(*(s + 1), ptr, fd);
			s += 2;
		}
		else
		{
			ft_putchar_fd(*(s++), fd);
			num_char++;
		}
	}
	va_end(ptr);
	return (num_char);
}
