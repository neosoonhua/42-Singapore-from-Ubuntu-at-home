/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:19:09 by sneo              #+#    #+#             */
/*   Updated: 2023/08/03 18:19:12 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	char str[] = "bc5 AZ";
	printf("%s\n", ft_strlowcase(str));
	printf("%s\n", ft_strlowcase(""));
	//One or more of the following 5 lines caused an error.
	//printf("%s\n", ft_strlowcase("bc5 AZ"));
	//printf("%s\n", ft_strlowcase("a~z"));
	//printf("%s\n", ft_strlowcase("AZ"));
	//printf("%s\n", ft_strlowcase("azc"));
	//printf("%s\n", ft_strlowcase("abc"));
}*/
