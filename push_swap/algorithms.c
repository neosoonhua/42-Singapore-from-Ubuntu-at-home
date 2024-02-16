/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:47:25 by sneo              #+#    #+#             */
/*   Updated: 2023/12/14 14:47:25 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_or_3(t_stp a)
{
	if (z(a) == 2)
	{
		if (*e(a, 1) < *e(a, 0))
			sw(a, NULL);
	}
	if (z(a) == 3)
	{
		if (*e(a, 0) < *e(a, 2) && *e(a, 2) < *e(a, 1))
		{
			rr_down(a, NULL);
			sw(a, NULL);
		}
		if (*e(a, 1) < *e(a, 0) && *e(a, 0) < *e(a, 2))
			sw(a, NULL);
		if (*e(a, 2) < *e(a, 0) && *e(a, 0) < *e(a, 1))
			rr_down(a, NULL);
		if (*e(a, 1) < *e(a, 2) && *e(a, 2) < *e(a, 0))
			r_up(a, NULL);
		if (*e(a, 2) < *e(a, 1) && *e(a, 1) < *e(a, 0))
		{
			sw(a, NULL);
			rr_down(a, NULL);
		}
	}
}

void	sort_more_than_3(t_stp a, t_stp b, int num_groups)
{
	to_b(a, b, num_groups);
	sort_2_or_3(a);
	back_to_a(a, b);
}

int	in(t_stp a, int i, int g, int n)
{
	int	l;

	l = a->len;
	if (*e(a, i) > l * (g - 1) / n && *e(a, i) <= l * g / n)
		return (1);
	return (0);
}

void	to_b(t_stp a, t_stp b, int n)
{
	int	i;
	int	j;
	int	gp;

	gp = 1;
	while (gp <= n)
	{
		i = -1;
		j = z(a);
		while (++i < j && z(a) > 3)
		{
			if (in(a, 0, gp + 1, n) && !in(a, 1, gp + 1, n) && !in(a, 1, gp, n))
			{
				pb_rr(a, b);
				i++;
			}
			else if (in(a, 0, gp, n) || (gp == n))
				pu(a, b, 'b');
			else if (in(a, 0, gp + 1, n))
				pb_rb(a, b);
			else
				r_up(a, NULL);
		}
		gp += 2;
	}
}

void	up_or_down_stack_a(t_stp a, int i)
{
	int	how_far;

	if (i >= z(a))
		return ;
	if (i >= z(a) - i)
	{
		how_far = z(a) - i;
		while (how_far-- > 0)
			rr_down(a, NULL);
	}
	else
	{
		how_far = i;
		while (how_far-- > 0)
			r_up(a, NULL);
	}
}
