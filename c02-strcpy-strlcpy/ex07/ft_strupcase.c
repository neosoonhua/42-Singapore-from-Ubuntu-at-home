/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:19:09 by sneo              #+#    #+#             */
/*   Updated: 2023/08/03 18:19:12 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	char str[] = "bc5 AZ";
	printf("%s\n", ft_strupcase(str));
	printf("%s\n", ft_strupcase(""));
	//One or more of the following 5 lines caused an error.
	//printf("%s\n", ft_strupcase("bc5 AZ"));
	//printf("%s\n", ft_strupcase("a~z"));
	//printf("%s\n", ft_strupcase("AZ"));
	//printf("%s\n", ft_strupcase("azc"));
	//printf("%s\n", ft_strupcase("abc"));
}*/
