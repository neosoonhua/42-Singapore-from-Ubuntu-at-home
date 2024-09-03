/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions-rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:39:56 by sneo              #+#    #+#             */
/*   Updated: 2024/01/15 13:40:03 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_up_helper(t_stp c)
{
	int	len;

	len = c->len;
	c->s[len + 1] = c->s[len];
	if (c->s[len] + 1 > c->s[len + 3])
		c->s[len] = c->s[len + 2];
	else
		(c->s[len])++;
}

void	r_up(t_stp a, t_stp b)
{
	if (a && z(a) > 1 && b && z(b) > 1)
	{
		r_up_helper(a);
		r_up_helper(b);
		ft_printf("rr\n");
	}
	else if (a && z(a) > 1)
	{
		r_up_helper(a);
		ft_printf("ra\n");
	}
	else if (b && z(b) > 1)
	{
		r_up_helper(b);
		ft_printf("rb\n");
	}
}

void	r_up_many(t_stp a, t_stp b, int how_many)
{
	while (--how_many > -1)
		r_up(a, b);
}
