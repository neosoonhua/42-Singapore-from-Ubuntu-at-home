/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions-reverse_rotate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:40:14 by sneo              #+#    #+#             */
/*   Updated: 2024/01/15 13:40:17 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_down_helper(t_stp c)
{
	int	len;

	len = c->len;
	c->s[len] = c->s[len + 1];
	if (c->s[len + 1] - 1 < c->s[len + 2])
		c->s[len + 1] = c->s[len + 3];
	else
		(c->s[len + 1])--;
}

void	rr_down(t_stp a, t_stp b)
{
	if (a && z(a) > 1 && b && z(b) > 1)
	{
		rr_down_helper(a);
		rr_down_helper(b);
		ft_printf("rrr\n");
	}
	else if (a && z(a) > 1)
	{
		rr_down_helper(a);
		ft_printf("rra\n");
	}
	else if (b && z(b) > 1)
	{
		rr_down_helper(b);
		ft_printf("rrb\n");
	}
}

void	rr_down_many(t_stp a, t_stp b, int how_many)
{
	while (--how_many > -1)
		rr_down(a, b);
}
