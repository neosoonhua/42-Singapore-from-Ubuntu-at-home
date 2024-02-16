/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:10:13 by sneo              #+#    #+#             */
/*   Updated: 2023/08/04 16:10:15 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	d;
	int	s;

	d = 0;
	s = 0;
	while (dest[d])
		d++;
	while (src[s])
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
	char d[] = "Hello";
	char s[] = " Evaluator";
	printf("%s\n", ft_strcat(d, s));
}*/
