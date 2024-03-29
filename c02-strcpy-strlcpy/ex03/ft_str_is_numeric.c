/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:07:32 by sneo              #+#    #+#             */
/*   Updated: 2023/08/03 18:08:00 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
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
	printf("%d\n", ft_str_is_numeric("bc5AZ"));
	printf("%d\n", ft_str_is_numeric("93523"));
	printf("%d\n", ft_str_is_numeric("ab\0c"));
	printf("%d\n", ft_str_is_numeric("\nab\0c"));
	printf("%d\n", ft_str_is_numeric(""));
}*/
