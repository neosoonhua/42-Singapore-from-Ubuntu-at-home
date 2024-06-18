/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 01:20:15 by sneo              #+#    #+#             */
/*   Updated: 2024/06/16 01:20:19 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put(t_data *d, int x, int y, int color)
{
	char	*dst;

	dst = d->ad + (y * d->line_sz + x * (d->bpp / 8));
	*(unsigned int *)dst = color;
}

int	mandelbrot(double cr, double ci)
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
	return (n);
}

int	julia(t_data *d, double zr, double zi)
{
	int		n;	
	double	temp;
	
	n = 0;
	while (n < MAX_ITER)
	{
		if (zr * zr + zi * zi > 4)
			break ;
		temp = zr;
		zr = zr * zr - zi * zi + (double)mod_atoi(d->argv[2], d) / 100000;
		zi = 2 * temp * zi + (double)mod_atoi(d->argv[3], d) / 100000;
		n++;
	}
	return (n);
}

int	iterate_fractal(t_data *d, int x, int y)
{
	double	x_txfed;
	double	y_txfed;

	x_txfed = txf((double)x, (double)W, d, 'x');
	y_txfed = txf((double)y, (double)H, d, 'y');
	if (d->frac == MANDELBROT)
		return (mandelbrot(x_txfed, y_txfed));
	else if (d->frac == JULIA)
		return (julia(d, x_txfed, y_txfed));
	return (0);
}

void	draw(t_data *d)
{
	int		x;
	int		y;
	int		n;

	mlx_clear_window(d->mlx, d->win);
	x = 0;
	while (x < W)
	{
		y = 0;
		while (y < H)
		{
			n = iterate_fractal(d, x, y);
			if (n == MAX_ITER)
				pixel_put(d, x, y, 0x00000000);
			else
				pixel_put(d, x, y, (int)(n * 16));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	return ;
}
