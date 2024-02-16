/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:10:13 by sneo              #+#    #+#             */
/*   Updated: 2023/08/04 16:10:15 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	d;
	unsigned int	s;

	d = 0;
	s = 0;
	while (dest[d])
		d++;
	while (src[s] && s < nb)
	{
		dest[d] = src[s];
		s++;
		d++;
	}
	dest[d] = '\0';
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	//Don't know why the following 2 lines cause "stack smashing".
	//char d[] = "123456";
	//char s[] = "7 89";
	char d[] = "12345";
	char s[] = "7 89.a";
	printf("%s\n", ft_strncat(d, s, 3));
}*/
