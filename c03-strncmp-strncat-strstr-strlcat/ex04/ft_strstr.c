/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:10:13 by sneo              #+#    #+#             */
/*   Updated: 2023/08/04 16:10:15 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	s;
	int	t;

	s = 0;
	t = 0;
	if (to_find[t] == '\0')
		return (str);
	while (str[s])
	{
		while (to_find[t] && str[s + t] == to_find[t])
			t++;
		if (to_find[t] == '\0')
			return (&str[s]);
		s++;
		t = 0;
	}
	return ('\0');
}

#include <stdio.h>

int	main(void)
{
	char str[] = "Hey.llo Hello.";
	char to_find[] = "Hello";
	printf("Pointer of haystack: %p\n", &str[8]);
	printf("Pointer of returned value: %p\n", ft_strstr(str, to_find));
}
