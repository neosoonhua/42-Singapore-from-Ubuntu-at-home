/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:41:27 by sneo              #+#    #+#             */
/*   Updated: 2024/01/15 13:41:29 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_cost_up_or_down_a_and_b(t_stp a, t_stp b, t_stp ia_ib, t_stp cst)
{
	int	ia;
	int	ib;

	ia = ia_ib->s[0];
	ib = ia_ib->s[1];
	cst->len = 4;
	cst->s[0] = ia + ib - small(ia, ib);
	cst->s[1] = ia + z(b) + 1 - ib;
	cst->s[2] = z(a) + 1 - ia + ib;
	cst->s[3] = z(a) - ia + z(b) - ib - small(z(a) - ia, z(b) - ib);
	cst->s[4] = 0;
	cst->s[5] = 3;
	cst->s[6] = 0;
	cst->s[7] = 3;
}

void	cost_to_correct_pl(t_stp a, t_stp b, int ib, t_stp cst)
{
	int		i;
	t_stp	ia_ib;

	i = -1;
	ia_ib = ft_calloc(1, sizeof(t_stk));
	ia_ib->s = ft_calloc(2, sizeof(int));
	ia_ib->len = 2;
	ia_ib->s[0] = 0;
	while (++i < z(a))
	{
		if (*e(a, i) < *e(b, ib))
			ia_ib->s[0]++;
	}
	ia_ib->s[0] = (ia_ib->s[0] + find(a, min(a))) % z(a);
	ia_ib->s[1] = ib;
	min_cost_up_or_down_a_and_b(a, b, ia_ib, cst);
	free_all(ia_ib, NULL, NULL);
}

void	init_mincost_topush(t_stp mincosttopush)
{
	mincosttopush->s[0] = INT_MAX;
	mincosttopush->s[1] = -1;
	mincosttopush->s[2] = -1;
}

void	mincost_topush(t_stp ct, t_stp cst, int ib, t_stp mincosttopush)
{
	t_stp_cpy(ct, cst);
	mincosttopush->s[0] = min(ct);
	mincosttopush->s[1] = ib;
}

void	back_to_a(t_stp a, t_stp b)
{
	t_stp	mincosttopush;
	t_stp	cst;
	t_stp	ct;

	mincosttopush = ft_calloc(1, sizeof(t_stk));
	mincosttopush->s = ft_calloc(7, sizeof(int));
	cst = ft_calloc(1, sizeof(t_stk));
	cst->s = ft_calloc(8, sizeof(int));
	ct = ft_calloc(1, sizeof(t_stk));
	ct->s = ft_calloc(8, sizeof(int));
	while (z(b) > 0)
	{
		init_mincost_topush(mincosttopush);
		while (++(mincosttopush->s[2]) < z(b))
		{
			cost_to_correct_pl(a, b, mincosttopush->s[2], cst);
			if (min(cst) < mincosttopush->s[0])
				mincost_topush(ct, cst, mincosttopush->s[2], mincosttopush);
		}
		push_to_correct_pl(a, b, mincosttopush->s[1], find(ct, min(ct)));
	}
	up_or_down_stack_a(a, find(a, min(a)));
	free_all(cst, ct, NULL);
	free_all(mincosttopush, NULL, NULL);
}
