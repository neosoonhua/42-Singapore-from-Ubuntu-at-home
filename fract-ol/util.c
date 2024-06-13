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

	dst = d->a + (y * d->l + x * (d->b / 8));
	*(int *)dst = color;
}

int	rev(double a, double max)
{
	double	mid;

	mid = max / 2;
	return ((int)((a * (max - mid) + mid)));
}

void	mandelbrot(t_data *data_p, double cr, double ci)
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
		pixel_put(data_p, rev(cr, W), rev(ci, H), 0x00000000);
	else
		pixel_put(data_p, rev(cr, W), rev(ci, H), (int)(n * 16));
}

double	offset(double a, double max)
{
	double	mid;

	mid = max / 2;
	return ((double)((a - mid) / (max - mid)));
}

void	draw(t_data *data_p)
{
	int		x;
	int		y;
	double	x_offseted;
	double	y_offseted;

	x = 0;
	while (x <= W)
	{
		y = 0;
		while (y <= H)
		{
			x_offseted = offset((double)x, (double)W);
			y_offseted = offset((double)y, (double)H);
			mandelbrot(data_p, x_offseted, y_offseted);
			y++;
		}
		x++;
	}
	return ;
}
