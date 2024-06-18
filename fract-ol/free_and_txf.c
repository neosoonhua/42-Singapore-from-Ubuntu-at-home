/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:27:47 by sneo              #+#    #+#             */
/*   Updated: 2024/06/13 18:27:53 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	txf(double a, double max, t_data *d, char x_or_y)
{
	double	range;
	double	low;
	double	high;

	if (x_or_y == 'x')
	{
		low = d->xl;
		high = d->xh;
	}
	else if (x_or_y == 'y')
	{
		low = d->yl;
		high = d->yh;
	}
	range = high - low;
	return (a * range / max + low);
}

void	free_t_data(t_data *d)
{
	if (d)
	{
		free(d->mlx);
		d->mlx = NULL;
		free(d);
		d = NULL;
	}
}

int	destroy_and_free(t_data *d)
{
	mlx_destroy_image(d->mlx, d->img);
	mlx_destroy_window(d->mlx, d->win);
	mlx_destroy_display(d->mlx);
	free_t_data(d);
	exit (0);
	return (1);
}
