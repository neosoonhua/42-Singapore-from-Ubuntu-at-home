/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 12:39:13 by sneo              #+#    #+#             */
/*   Updated: 2023/08/17 12:39:16 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

int	total_length(int size, char **strs, char *sep)
{
	int	j;
	int	k;
	int	total;

	j = 0;
	total = 0;
	while (j < size)
	{
		k = 0;
		while (strs[j][k])
			k++;
		total += k;
		k = 0;
		while (sep[k] && j != size - 1)
			k++;
		total += k;
		j++;
	}
	total++;
	return (total);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		j;
	int		k;
	int		m;
	char	*s;

	s = (char *)malloc(sizeof(char) * total_length(size, strs, sep));
	if (s == NULL)
		return (NULL);
	j = 0;
	m = 0;
	while (j < size)
	{
		k = 0;
		while (strs[j][k])
			s[m++] = strs[j][k++];
		k = 0;
		while (sep[k] && j != size - 1)
			s[m++] = sep[k++];
		j++;
	}
	s[m] = '\0';
	return (s);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*t[3];

	t[0] = "jkl mn7";
	t[1] = "a  b";
	t[2] = "c/d";
	printf("%s\n", ft_strjoin(3, t, "*# "));
	printf("%s\n", ft_strjoin(0, t, "*# "));
}*/
