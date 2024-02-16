/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:37:11 by sneo              #+#    #+#             */
/*   Updated: 2023/09/08 12:37:16 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
// #include <bsd/string.h> //Does not work

int	main(void)
{
	printf("ft_printf *********************************\n");
	printf("c *********************************\n");
	char	c = 'm';
	int		count;
	count = printf("c: %c. Testing!\n", c);
	printf("count: %d\n", count);
	count = ft_printf("c: %c. Testing!\n", c);
	printf("count: %d\n", count);
	printf("s *********************************\n");
	char	*s = "jk xyz, abc - defghi234";
	count = printf("s: %s. Testing!\n", s);
	printf("count: %d\n", count);
	count = ft_printf("s: %s. Testing!\n", s);
	printf("count: %d\n", count);
	printf("p *********************************\n");
	count = printf("&s: %p. Testing!\n", &s);
	printf("count: %d\n", count);
	count = ft_printf("&s: %p. Testing!\n", &s);
	printf("count: %d\n", count);
	printf("d *********************************\n");
	int	d = INT_MIN;
	count = printf("%d. Testing!\n", d);
	printf("count: %d\n", count);
	count = ft_printf("%d. Testing!\n", d);
	printf("count: %d\n", count);
	d = INT_MAX;
	count = printf("%d. Testing!\n", d);
	printf("count: %d\n", count);
	count = ft_printf("%d. Testing!\n", d);
	printf("count: %d\n", count);
	d = 0;
	count = printf("%d. Testing!\n", d);
	printf("count: %d\n", count);
	count = ft_printf("%d. Testing!\n", d);
	printf("count: %d\n", count);
	printf("i *********************************\n");
	d = INT_MIN;
	count = printf("%i. Testing!\n", d);
	printf("count: %i\n", count);
	count = ft_printf("%i. Testing!\n", d);
	printf("count: %i\n", count);
	d = INT_MAX;
	count = printf("%i. Testing!\n", d);
	printf("count: %i\n", count);
	count = ft_printf("%i. Testing!\n", d);
	printf("count: %i\n", count);
	printf("u *********************************\n");
	unsigned int	u = UINT_MAX;
	count = printf("%u. Testing!\n", u);
	printf("count: %i\n", count);
	count = ft_printf("%u. Testing!\n", u);
	printf("count: %i\n", count);
	printf("x *********************************\n");
	count = printf("%x. Testing!\n", u/235);
	printf("count: %i\n", count);
	count = ft_printf("%x. Testing!\n", u/235);
	printf("count: %i\n", count);
	printf("X *********************************\n");
	count = printf("%X. Testing!\n", u/56);
	printf("count: %i\n", count);
	count = ft_printf("%X. Testing!\n", u/56);
	printf("count: %i\n", count);
	printf("%% *********************************\n");
	count = printf("%%. Testing!\n");
	printf("count: %i\n", count);
	count = ft_printf("%%. Testing!\n");
	printf("count: %i\n", count);
}
