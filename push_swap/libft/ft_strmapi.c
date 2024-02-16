/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:50:46 by sneo              #+#    #+#             */
/*   Updated: 2023/09/23 20:50:46 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	if (!s || !f)
		return (NULL);
	result = ft_strdup(s);
	if (!result)
		return (NULL);
	i = 0;
	while (result[i])
	{
		result[i] = f(i, result[i]);
		i++;
	}
	return (result);
}

/*char	touppercase(unsigned int i, char c)
{
	i++;
	if (c >= 97 && c <= 122)
	{
		c -= 32;
		return (c);
	}
	return (c);
}

#include <stdio.h>

int main(void)
{
	char	*str = "a x Y, . !";
	printf("%s\n", ft_strmapi(str, touppercase));

	return (0);
}*/