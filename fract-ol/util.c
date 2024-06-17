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

int	inv(double a, double max, t_data *d, char x_or_y)
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
	return ((int)((a - low) / range * max));
}

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
	return (a / max * range + low);
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
		if (zr * zr + zi * zi > 4)
			break ;
		temp = zr;
		zr = zr * zr - zi * zi + cr;
		zi = 2 * temp * zi + ci;
		n++;
	}
	if (n == MAX_ITER)
		pixel_put(d, inv(cr, W, d, 'x'), inv(ci, H, d, 'y'), 0x00000000);
	else
		pixel_put(d, inv(cr, W, d, 'x'), inv(ci, H, d, 'y'), (int)(n * 16));
}

void	julia(t_data *d, double zr, double zi, char **argv)
{
	int		n;	
	double	temp;
	double	zr0;
	double	zi0;

	n = 0;
	zr0 = zr;
	zi0 = zi;
	while (n < MAX_ITER)
	{
		if (zr * zr + zi * zi > 4)
			break ;
		temp = zr;
		zr = zr * zr - zi * zi + (double)ft_atoi(argv[2]) / 100000;
		zi = 2 * temp * zi + (double)ft_atoi(argv[3]) / 100000;
		n++;
	}
	if (n == MAX_ITER)
		pixel_put(d, inv(zr0, W, d, 'x'), inv(zi0, H, d, 'y'), 0x00000000);
	else
		pixel_put(d, inv(zr0, W, d, 'x'), inv(zi0, H, d, 'y'), (int)(n * 16));
}

void	draw(t_data *d, char **argv)
{
	int		x;
	int		y;
	double	x_txfed;
	double	y_txfed;

	d->argv = argv;
	mlx_clear_window(d->mlx, d->win);
	x = 0;
	while (x < W)
	{
		y = 0;
		while (y < H)
		{
			x_txfed = txf((double)x, (double)W, d, 'x');
			y_txfed = txf((double)y, (double)H, d, 'y');
			if (d->frac == MANDELBROT)
				mandelbrot(d, x_txfed, y_txfed);
			else if (d->frac == JULIA)
				julia(d, x_txfed, y_txfed, d->argv);
			y++;
		}
		x++;
	}
	return ;
}
