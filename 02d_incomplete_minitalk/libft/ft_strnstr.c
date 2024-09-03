/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:58:05 by sneo              #+#    #+#             */
/*   Updated: 2023/09/19 14:58:05 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	s;
	size_t	t;

	s = 0;
	if (*to_find == '\0')
		return ((char *)str);
	if (*str == '\0' || str == NULL)
		return (NULL);
	while (str[s] && s < n)
	{
		t = 0;
		while (to_find[t] && str[s + t] == to_find[t] && s + t < n)
			t++;
		if (to_find[t] == '\0')
			return ((char *)&str[s]);
		s++;
	}
	return (NULL);
}
