/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:33:32 by sneo              #+#    #+#             */
/*   Updated: 2023/09/23 22:33:32 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int		i;
	long	num;

	i = 0;
	num = (long)n;
	if (fd < 0)
		return (0);
	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
		i++;
	}
	if (num < 10)
	{
		ft_putchar_fd(num + (long) '0', fd);
		i++;
	}
	else
	{
		i += ft_putnbr_fd(num / 10, 1);
		i += ft_putnbr_fd(num % 10, 1);
	}
	return (i);
}
