/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:00:44 by sneo              #+#    #+#             */
/*   Updated: 2023/09/12 16:00:46 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	s;

	s = ft_strlen(src);
	if (s + 1 < size)
		ft_memmove(dst, src, s + 1);
	else if (size > 0)
	{
		ft_memmove(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (ft_strlen(src));
}
