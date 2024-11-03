/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbinte-z <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:54:58 by nbinte-z          #+#    #+#             */
/*   Updated: 2024/10/08 19:27:15 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	skip_token_new(char **ptr)
{
	char	*str;

	str = *ptr;
	if (*str)
	{
		if (*str == ' ')
			str++;
		if (*str == '|')
			str++;
		if (*str == ' ')
			str++;
	}
	*ptr = str;
}

int	find_num_pipe(char *str)
{
	int		i;
	int		count;
	char	quote;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			quote = str[i++];
			while (str[i] && str[i] != quote)
				i++;
		}
		if (str[i] == '|')
			count++;
		i++;
	}
	// printf("num of pipes: %d\n", count);
	return (count);
}

int	find_len_pipe(char *str)
{
	int		i;
	int		count;
	char 	quote;

	i = 0;
	count = 0;
	while (str[i] && str[i] != '|')
	{
		if (str[i] == '\'' || str[i] == '"')
		{
			quote = str[i++];
			count += 2;
			while (str[i] && str[i] != quote)
			{
				i++;
				count++;
			}
		}
		else
			count++;
		i++;
	}
	if (str[i] == '|' && str[i - 1] == ' ')
		count -= 1;
	// printf("len of pipe: %d\n", count);
	return (count);
}

char	**sep_by_pipe(char *str)
{
	char	**new;
	int		len;
	int		x;
	int		y;

	if (!str || *str == '\0')
		return (NULL);
	new = calloc(find_num_pipe(str) + 1, sizeof(char *));
	if (!new)
		return (NULL);
	x = 0;
	len = 0;
	while (*str)
	{
		y = 0;
		skip_token_new(&str);
		len = find_len_pipe(str);
		if (len < 0)
		{
			free_many(NULL, new, NULL);
			return (NULL);
		} //error & free // can just make free_many() return an char **
		new[x] = calloc(len + 1, sizeof(char));
		if (!new[x])
		{
			free_many(NULL, new, NULL);
			return (NULL);
		}
		while (len-- > 0)
			new[x][y++] = *str++; //should not cp pipe
		new[x][y] = '\0';
		x++;
	}
	new[x] = NULL;
	return (new);
}
