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

static int	count_words(char const *s, char c)
{
	int	count;
	int	quote;

	count = 0;
	while (1)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break;
		if (*s == '"' || *s == '\'')
		{
			quote = *s++;
			while (*s && *s != quote)
				s++;
			if (*s == '\0')
				return (ft_printf(2, "Unmatched quote\n"));
			count++;
			s++;
			continue;
		}
		if (ft_isalnum(*s))
		{
			while (ft_isalnum(*s))
				s++;
			count++;
			continue;
		}
	}
	ft_printf(1, "count: %d\n", count);
	return (count);
}

static void	*free_mem(char **s, int i)
{
	while (--i >= 0)
		free(s[i]);
	free(s);
	return (0);
}

static int	get_word(char **strs, char *begin, char *end)
{
	int	i;
	int	len;

	len = end - begin;
	*strs = malloc(sizeof(char) * (len + 1));
	if (!*strs)
		return (0);
	i = -1;
	while (++i < len)
		strs[0][i] = begin[i];
	strs[0][i] = 0;
	return (1);
}

char	**split_cmd(char const *s, char c)
{
	int		i;
	char	*str;
	char	**result;
	int		quote;
	char	*begin;

	if (!s)
		return (NULL);
	str = (char *)s;
	i = 0;
	result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	while (1)
	{
		while (*str == c)
			str++;
		if (*str == '\0')
			break;
		if (*str == '"' || *str == '\'')
		{
			quote = *str++;
			begin = str;	
			while (*str && *str != quote)
				str++;
			if (*str == '\0')
			{
				ft_printf(2, "Unmatched quote\n");
				return (NULL);
			}
			if (*str && !get_word(&result[i++], begin, str))
				return (free_mem(result, i));
			str++;
			continue;
		}
		if (ft_isalnum(*str))
		{
			begin = str;
			while (ft_isalnum(*str))
				str++;
			if (*str && !get_word(&result[i++], begin, str))
				return (free_mem(result, i));
			continue;
		}
	}
	result[i] = NULL;
	return (result);
}