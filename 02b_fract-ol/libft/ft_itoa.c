/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:35:57 by sneo              #+#    #+#             */
/*   Updated: 2023/09/23 16:35:57 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(int n)
{
	int			len;
	long long	x;

	len = 0;
	if (n == 0)
		len++;
	x = (long long)n;
	if (x < 0)
	{
		x *= -1;
		len++;
	}
	while (x != 0)
	{
		x /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*result;
	int			len;
	long long	x;

	len = count_len(n);
	result = ft_calloc(sizeof(char) * len + 1, 1);
	if (!result)
		return (NULL);
	x = (long long)n;
	if (x < 0)
		x *= -1;
	result[len--] = '\0';
	if (x == 0)
		result[len--] = '0';
	while (x != 0)
	{
		result[len--] = x % 10 + '0';
		x /= 10;
	}
	if (n < 0)
		result[len] = '-';
	return (result);
}
