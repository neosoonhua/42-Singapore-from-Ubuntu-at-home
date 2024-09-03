/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:49:16 by sneo              #+#    #+#             */
/*   Updated: 2023/12/09 15:49:16 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sw_helper(t_stp c)
{
	int	temp;

	temp = *e(c, 0);
	*(e(c, 0)) = *e(c, 1);
	*e(c, 1) = temp;
}

void	sw(t_stp a, t_stp b)
{
	if (a && z(a) > 1 && b && z(b) > 1)
	{
		sw_helper(a);
		sw_helper(b);
		ft_printf("ss\n");
	}
	else if (a && z(a) > 1)
	{
		sw_helper(a);
		ft_printf("sa\n");
	}
	else if (b && z(b) > 1)
	{
		sw_helper(b);
		ft_printf("sb\n");
	}
}

void	pu_helper(t_stp fr, t_stp to)
{
	if (to->s[to->len + 1] != to->len - 1)
		to->s[to->len + 1]--;
	to->s[to->len + 2]--;
	if (fr->s[fr->len + 1] < fr->s[fr->len])
		fr->s[fr->len + 1]++;
	if (fr->s[fr->len] != fr->len - 1)
		fr->s[fr->len]++;
	else
		fr->s[fr->len] = fr->s[fr->len + 2] + 1;
	fr->s[fr->len + 2]++;
}

void	pu(t_stp fr, t_stp to, char to_stack)
{
	int	i;
	int	j;

	if (z(fr) < 1)
		return ;
	j = to->s[to->len + 2] - 1;
	while (++j < to->s[to->len])
		to->s[j - 1] = to->s[j];
	j--;
	to->s[j] = fr->s[fr->s[fr->len]];
	i = fr->s[fr->len];
	while (--i > fr->s[fr->len + 2] - 1)
		fr->s[i + 1] = fr->s[i];
	fr->s[i + 1] = 0;
	to->s[to->len]--;
	pu_helper(fr, to);
	ft_printf("p%c\n", to_stack);
}
