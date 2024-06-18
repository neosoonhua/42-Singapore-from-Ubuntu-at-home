/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:08:29 by sneo              #+#    #+#             */
/*   Updated: 2024/06/18 11:08:32 by sneo             ###   ########.fr       */
/*            #include "fractol.h"
                                                                */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h> //To delete

int	key(int key, t_data *d)
{
	if (key == XK_Escape)
	{
		ft_printf("%d key (ESC) pressed.\n", key);
		destroy_and_free(d);
	}
	return (0);
}

int	cross_on_window_frame(t_data *d)
{
	ft_printf("Cross on window frame clicked on.\n");
	destroy_and_free(d);
	return (0);
}

void	zoom(t_data *d, double factor, int x_cent, int y_cent)
{
	double	x_range_halved_factor;
	double	y_range_halved_factor;
	double	halved_factor;
	double	x_cent_txfed;
	double	y_cent_txfed;

	printf("xl: %lf\n", d->xl);
	printf("xh: %lf\n", d->xh);
	printf("yl: %lf\n", d->yl);
	printf("yh: %lf\n", d->yh);
	x_cent_txfed = txf((double)x_cent, (double)W, d, 'x');
	y_cent_txfed = txf((double)y_cent, (double)H, d, 'y');
	halved_factor = factor * 0.5;
	x_range_halved_factor = (d->xh - d->xl) * halved_factor;
	y_range_halved_factor = (d->yh - d->yl) * halved_factor;
	d->xl = x_cent_txfed - x_range_halved_factor;
	d->xh = x_cent_txfed + x_range_halved_factor;
	d->yl = y_cent_txfed - y_range_halved_factor;
	d->yh = y_cent_txfed + y_range_halved_factor;
	draw(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}

int	mouse(int key, int x, int y, t_data *d)
{
	ft_printf("mouse\n");
	if (key == MOUSE_WHEEL_UP)
	{
		ft_printf("zoom in\n");
		zoom(d, 0.75, x, y);
	}
	if (key == MOUSE_WHEEL_DOWN)
	{
		ft_printf("zoom out\n");
		zoom(d, 1.6, x, y);
	}
	return (0);
}
