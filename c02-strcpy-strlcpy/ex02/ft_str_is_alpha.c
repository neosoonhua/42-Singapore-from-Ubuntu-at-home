/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:23:10 by sneo              #+#    #+#             */
/*   Updated: 2023/08/03 17:29:43 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 'A' || str[i] > 'z')
		{
			return (0);
		}
		if (str[i] > 'Z' && str[i] < 'a')
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
	printf("%d\n", ft_str_is_alpha("abcAZ"));
	printf("%d\n", ft_str_is_alpha("93abc"));
	printf("%d\n", ft_str_is_alpha("ab\0c"));
	printf("%d\n", ft_str_is_alpha("\nab\0c"));
	printf("%d\n", ft_str_is_alpha(""));
}*/
