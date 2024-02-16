/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:57:40 by sneo              #+#    #+#             */
/*   Updated: 2023/08/08 16:57:44 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_strlen("jkl"));
	printf("%d\n", ft_strlen(""));
	printf("%d\n", ft_strlen("jklmn"));
}*/
