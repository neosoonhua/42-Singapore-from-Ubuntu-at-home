/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:30:40 by sneo              #+#    #+#             */
/*   Updated: 2023/09/20 15:30:40 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char delimiter)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == delimiter)
			s++;
		if (*s)
			count++;
		while (*s && *s != delimiter)
			s++;
	}
	return (count);
}

static void	*free_mem(char **s, int i)
{
	while (--i >= 0)
		free(s[i]);
	free(s);
	return (0);
}

static int	get_word(char **strs, char *s, char c)
{
	int	len;
	int	i;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	*strs = malloc(sizeof(char) * (len + 1));
	if (!*strs)
		return (0);
	i = -1;
	while (++i < len)
		strs[0][i] = s[i];
	strs[0][i] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	*str;
	char	**result;

	if (!s)
		return (NULL);
	str = (char *)s;
	i = 0;
	result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && !get_word(&result[i++], str, c))
			return (free_mem(result, i));
		while (*str && *str != c)
			str++;
	}
	result[i] = NULL;
	return (result);
}
