/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:19:09 by sneo              #+#    #+#             */
/*   Updated: 2023/08/03 18:19:12 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < ' ' || str[i] > '~')
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
	printf("%d\n", ft_str_is_printable("bc5 AZ"));
	printf("%d\n", ft_str_is_printable("a~z"));
	printf("%d\n", ft_str_is_printable("AZ"));
	printf("%d\n", ft_str_is_printable("az\0c"));
	printf("%d\n", ft_str_is_printable("\nab\0c"));
	printf("%d\n", ft_str_is_printable(""));
}*/
