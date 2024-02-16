/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:19:09 by sneo              #+#    #+#             */
/*   Updated: 2023/08/03 18:19:12 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 'A' || str[i] > 'Z')
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
	printf("%d\n", ft_str_is_uppercase("bc5AZ"));
	printf("%d\n", ft_str_is_uppercase("az"));
	printf("%d\n", ft_str_is_uppercase("AZ"));
	printf("%d\n", ft_str_is_uppercase("az\0c"));
	printf("%d\n", ft_str_is_uppercase("\nab\0c"));
	printf("%d\n", ft_str_is_uppercase(""));
}*/
