/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:28:20 by sneo              #+#    #+#             */
/*   Updated: 2024/01/18 19:28:28 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_input(int key, void *param)
{
	// Handle the input based on the keycode.
	key++;
	param++;
	return (0);
}

void	pixel_put(t_data *d, int x, int y, int color)
{
	char	*dst;

	dst = d->a + (y * d->l + x * (d->b / 8));
	*(unsigned int*)dst = color;
}

void	draw_straight_line(t_data *data_p, int x_max, int y_max)
{
	int	x;
	int	y;

	x = 0;
	while (x <= x_max)
	{
		y = 0;
		while (y <= y_max)
		{
			if (x + y == 50)
				pixel_put(data_p, x, y, 0x00ff0000);
			y++;
		}
		x++;
	}
	return ;
}

int	main(void)
{
	void	*mlx;
	void	*win;
	t_data	im;

	mlx = mlx_init();
	// if (!mlx)
	// {
	// 	//Handle the error.
	// 	return (1);
	// }
	win = mlx_new_window(mlx, 800, 400, "First window");
	im.i = mlx_new_image(mlx, 800, 400);
	im.a = mlx_get_data_addr(im.i, &im.b, &im.l, &im.e);
	draw_straight_line(&im, 90, 90);
	mlx_put_image_to_window(mlx, win, im.i, 0, 0);
	mlx_loop(mlx);
	// mlx_key_hook(win, handle_input, NULL);
	// mlx_destroy_display(mlx);
	// free(mlx);
	return (0);
}