/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:05:11 by sneo              #+#    #+#             */
/*   Updated: 2023/12/25 18:05:11 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	z(t_stp c)
{
	return (c->s[c->len + 3] - c->s[c->len + 2] + 1);
}

int	*e(t_stp c, int idx)
{
	int	len;
	int	*s;

	len = c->len;
	s = c->s;
	if (z(c) < 1)
		return (NULL);
	if (idx + s[len] <= s[len + 3])
		return (&(s[(idx + s[len])]));
	else
		return (&(s[(idx + s[len] - s[len + 3] - 1 + s[len + 2])]));
}

int	sorted(t_stp a, t_stp b)
{
	int	i;
	int	a_z;

	if (z(b) > 0)
		return (0);
	i = 0;
	a_z = z(a);
	while (i < a_z)
	{
		if (*e(a, i) != i + 1)
			return (0);
		i++;
	}
	return (1);
}

int	min(t_stp c)
{
	int	mini;
	int	i;

	if (z(c) < 1)
		return (-1);
	mini = INT_MAX;
	i = -1;
	while (++i < z(c))
	{
		if (*e(c, i) < mini)
			mini = *e(c, i);
	}
	return (mini);
}

t_stp	t_stp_cpy(t_stp dest, const t_stp src)
{
	t_stp	d;
	t_stp	sr;
	int		n;

	d = dest;
	sr = src;
	if (!dest && !src)
		return (0);
	d->len = sr->len;
	n = d->len + 4;
	while (--n > -1)
		d->s[n] = sr->s[n];
	return (dest);
}
