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

void	pixel_put(t_data *d, int x, int y, int color)
{
	char	*dst;

	dst = d->ad + (y * d->line_sz + x * (d->bpp / 8));
	*(unsigned int *)dst = color;
}

int	rev(double a, double max)
{
	double	mid;

	mid = max / 2;
	return ((int)((a * (max - mid) + mid)));
}

void	mandelbrot(t_data *d, double cr, double ci)
{
	int		n;	
	double	zr;
	double	zi;
	double	temp;

	n = 0;
	zr = 0;
	zi = 0;
	while (n < MAX_ITER)
	{
		if (zr * zr + zi * zi > 680)
			break ;
		temp = zr;
		zr = zr * zr - zi * zi + cr;
		zi = 2 * temp * zi + ci;
		n++;
	}
	if (n == MAX_ITER)
		pixel_put(d, rev(cr, W), rev(ci, H), 0x00000000);
	else
		pixel_put(d, rev(cr, W), rev(ci, H), (int)(n * 16));
}

double	txf(double a, double max)
{
	double	mid;

	mid = max / 2;
	return ((double)((a - mid) / (max - mid)));
}

void	draw(t_data *d)
{
	int		x;
	int		y;
	double	x_txfed;
	double	y_txfed;

	mlx_clear_window(d->mlx, d->win);
	x = 0;
	while (x < W)
	{
		y = 0;
		while (y < H)
		{
			x_txfed = txf((double)x, (double)W);
			y_txfed = txf((double)y, (double)H);
			mandelbrot(d, x_txfed, y_txfed);
			y++;
		}
		x++;
	}
	return ;
}
