/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:19:09 by sneo              #+#    #+#             */
/*   Updated: 2023/08/03 18:19:12 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 'a' || str[i] > 'z')
		{
			return (0);
		}
		i++;
	}
	return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_str_is_lowercase("bc5AZ"));
	printf("%d\n", ft_str_is_lowercase("az"));
	printf("%d\n", ft_str_is_lowercase("AZ"));
	printf("%d\n", ft_str_is_lowercase("az\0c"));
	printf("%d\n", ft_str_is_lowercase("\nab\0c"));
	printf("%d\n", ft_str_is_lowercase(""));
}*/
