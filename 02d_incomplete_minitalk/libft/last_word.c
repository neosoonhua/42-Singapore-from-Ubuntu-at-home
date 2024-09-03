/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 01:56:10 by sneo              #+#    #+#             */
/*   Updated: 2024/05/30 01:56:12 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*last_word(const char *str, char sep)
{
	int	s;

	s = ft_strlen(str) - 2;
	if (*str == '\0' || str == NULL)
		return (NULL);
	while (s >= 0)
	{
		if (str[s] == sep)
			return ((char *)&str[s] + 1);
		s--;
	}
	return (NULL);
}
