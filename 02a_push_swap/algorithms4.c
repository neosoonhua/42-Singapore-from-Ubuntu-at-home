/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:52:36 by sneo              #+#    #+#             */
/*   Updated: 2024/01/28 20:52:38 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find(t_stp c, int to_find)
{
	int	i;

	i = -1;
	while (++i < z(c))
	{
		if (*e(c, i) == to_find)
			break ;
	}
	return (i);
}

int	small(int x, int y)
{
	if (x < y)
		return (x);
	else
		return (y);
}
