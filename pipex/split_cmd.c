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

#include "pipex.h"

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

char	quote_or_not(char *str, char c)
{
	if (*str == '\'')
		return ('\'');
	else if (*str == '"')
		return ('"');
	else
		return (c);
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
	result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	while (*str)
	{
		while (*str && *str == c)
			str++;
		c = quote_or_not(str++, c);
		if (*str && !get_word(&result[i++], str, c))
			return (free_mem(result, i));
		while (*str && *str != c)
			str++;
	}
	result[i] = NULL;
	return (result);
}
