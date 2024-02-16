/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:19:21 by sneo              #+#    #+#             */
/*   Updated: 2023/08/04 14:19:25 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((s1[i] - s2[i]) != 0)
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_strcmp("ABC", "ABC")); //0
	printf("%d\n", ft_strcmp("ABC", "AB")); //67
	printf("%d\n", ft_strcmp("ABA", "ABZ")); //-25
	printf("%d\n", ft_strcmp("ABJ", "ABC")); //7
	//Next line: Copied from manual for strcmp. Different result here.
	printf("%d\n", ft_strcmp("\201", "A")); //64.
	printf("%d\n", 0201); //129. 0201 (i.e. zero 201) is "octal 201"
	//printf("%d\n", "A"); //65. Different result here.
}*/
