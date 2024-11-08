/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 02:06:07 by sneo              #+#    #+#             */
/*   Updated: 2024/07/15 02:37:25 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ascii9to13(char c)
{
	if (c >= 9 && c <= 13)
		return (1);
	return (0);
}

static int	count_words2(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && (*s == c || ascii9to13(*s)))
			s++;
		if (*s)
			count++;
		while (*s && *s != c && !ascii9to13(*s))
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
	while (s[len] && s[len] != c && !ascii9to13(s[len]))
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

char	**split_cmd(char const *s, char c)
{
	int		i;
	char	*str;
	char	**result;

	if (!s)
		return (NULL);
	str = (char *)s;
	i = 0;
	result = (char **)malloc(sizeof(char *) * (count_words2(s, c) + 1));
	if (!result)
		return (NULL);
	while (*str)
	{
		while (*str && (*str == c || ascii9to13(*str)))
			str++;
		if (*str && !get_word(&result[i++], str, c))
			return (free_mem(result, i));
		while (*str && *str != c && !ascii9to13(*str))
			str++;
	}
	result[i] = NULL;
	return (result);
}
