/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:50:46 by sneo              #+#    #+#             */
/*   Updated: 2023/09/23 20:50:46 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*void	touppercase(unsigned int i, char *c)
{
	i++;
	i--;
	if (*c >= 97 && *c <= 122)
		*c -= 32;
}

#include <stdio.h>

int main(void)
{
	char	str[] = "a x Y, . !"; //char	*str caused SIGSEGV (Address boundary error)
	ft_striteri(str, touppercase);
	printf("%s\n", str);

	return (0);
}*/