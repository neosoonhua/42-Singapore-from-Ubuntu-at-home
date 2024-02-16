/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:52:02 by sneo              #+#    #+#             */
/*   Updated: 2023/08/03 16:52:10 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
int	main(void)
{
	char	d[5] = "efghi";
	char	s[] = "abc12345";
	printf("%s\n", d);
	printf("%s\n", s);
	printf("%s\n", ft_strncpy(d, s, 4));
	printf("%s\n", s);
}*/
