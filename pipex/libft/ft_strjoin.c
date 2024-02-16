/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:10:13 by sneo              #+#    #+#             */
/*   Updated: 2023/08/04 16:10:15 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *dest, char const *src)
{
	char	*de;
	size_t	d;
	size_t	s;

	d = ft_strlen(dest);
	s = ft_strlen(src);
	de = malloc(sizeof(char) * (d + s + 1));
	if (!de)
		return (NULL);
	while (*dest)
		*de++ = *dest++;
	while (*src)
		*de++ = *src++;
	*de = '\0';
	return (de - d - s);
}
