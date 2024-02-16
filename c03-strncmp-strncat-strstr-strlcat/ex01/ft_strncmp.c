/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:42:34 by sneo              #+#    #+#             */
/*   Updated: 2023/08/04 15:42:40 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
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
	printf("%d\n", ft_strncmp("ABC", "ABC", 3)); //0
	printf("%d\n", ft_strncmp("ABC", "AB", 2)); //0
	printf("%d\n", ft_strncmp("ABA", "ABZ", 3)); //-25
	printf("%d\n", ft_strncmp("ABJ", "ABC", 3)); //7
	//Next line: Copied from manual for strncmp. Different result here.
	printf("%d\n", ft_strncmp("\201", "A", 1)); //64. 
	printf("%d\n", 0201); //129. 0201 (i.e. zero 201) is "octal 201"
	//printf("%d\n", "A"); //65. Different result here.
}*/
