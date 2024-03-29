/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions-double.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 04:03:09 by sneo              #+#    #+#             */
/*   Updated: 2024/01/09 04:03:09 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb_rr(t_stp a, t_stp b)
{
	pu(a, b, 'b');
	r_up(a, b);
}

void	pb_rb(t_stp a, t_stp b)
{
	pu(a, b, 'b');
	r_up(NULL, b);
}
