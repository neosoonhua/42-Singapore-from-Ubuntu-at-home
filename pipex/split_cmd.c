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

int	blank(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

static int	handle_quote(const char **s)
{
	char	quote;

	quote = **s;
	(*s)++;
	while (**s && **s != quote)
		(*s)++;
	if (**s == quote)
	{
		(*s)++;
		return (1);
	}
	ft_printf(2, "Unmatched quote\n");
	return (0);
}

static int	count_words(const char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && blank(*s))
			s++;
		if (*s)
		{
			count++;
			if (*s == '"' || *s == '\'')
			{
				if (!handle_quote(&s))
					return (-1);
			}
			else
			{
				while (*s && !blank(*s) && *s != '"' && *s != '\'')
					s++;
			}
		}
	}
	return (count);
}

void	*free_mem(char **s, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(s[i++]);
	free(s);
	return (NULL);
}

static int	extract_word(char **strs, const char **s, int l, char quote)
{
	strs[0] = malloc(sizeof(char) * (l + 1));
	if (!strs[0])
		return (0);
	ft_strlcpy(strs[0], *s, l + 1);
	if (quote)
		*s += l + 1;
	else
		*s += l;
	return (1);
}

int	get_word(char **strs, const char **s)
{
	int		l;
	int		quote;

	l = 0;
	if (**s == '"' || **s == '\'')
	{
		quote = **s;
		(*s)++;
		while ((*s)[l] && (*s)[l] != quote)
			l++;
		if ((*s)[l] == quote)
			return (extract_word(strs, s, l, quote));
		else
		{
			ft_printf(2, "Unmatched quote\n");
			return (0);
		}
	}
	else
	{
		while ((*s)[l] && !blank((*s)[l]) && (*s)[l] != '"' && (*s)[l] != '\'')
			l++;
		return (extract_word(strs, s, l, 0));
	}
}

char	**split_cmd(const char *s)
{
	char	**result;
	int		word_count;
	int		i;

	if (!s)
		return (NULL);
	word_count = count_words(s);
	if (word_count == -1)
		return (NULL);
	result = malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && blank(*s))
			s++;
		if (*s && !get_word(&result[i++], &s))
			return (free_mem(result, i));
	}
	result[i] = NULL;
	return (result);
}
