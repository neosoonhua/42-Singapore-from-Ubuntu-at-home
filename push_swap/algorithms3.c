/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:41:33 by sneo              #+#    #+#             */
/*   Updated: 2024/01/15 13:41:35 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	option_0(t_stp a, t_stp b, int ia, int ib)
{
	r_up_many(a, b, small(ia, ib));
	if (ia > ib)
		r_up_many(a, NULL, ia - ib);
	else
		r_up_many(NULL, b, ib - ia);
}

void	option_1(t_stp a, t_stp b, int ia, int ib)
{
	r_up_many(a, NULL, ia);
	rr_down_many(NULL, b, z(b) - ib);
}

void	option_2(t_stp a, t_stp b, int ia, int ib)
{
	rr_down_many(a, NULL, z(a) - ia);
	r_up_many(NULL, b, ib);
}

void	option_3(t_stp a, t_stp b, int ia, int ib)
{
	rr_down_many(a, b, small(z(a) - ia, z(b) - ib));
	if (z(a) - ia > z(b) - ib)
		rr_down_many(a, NULL, z(a) - ia - z(b) + ib);
	else
		rr_down_many(NULL, b, z(b) - ib - z(a) + ia);
}

void	push_to_correct_pl(t_stp a, t_stp b, int ib, int option)
{
	int	i;
	int	ia;

	i = -1;
	ia = 0;
	while (++i < z(a))
	{
		if (*e(a, i) < *e(b, ib))
			ia++;
	}
	ia = (ia + find(a, min(a))) % z(a);
	if (option == 0)
		option_0(a, b, ia, ib);
	else if (option == 1)
		option_1(a, b, ia, ib);
	else if (option == 2)
		option_2(a, b, ia, ib);
	else
		option_3(a, b, ia, ib);
	pu(b, a, 'a');
}
