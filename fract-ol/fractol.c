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

int	key(int key, t_data *d)
{
	if (key == XK_Escape)
	{
		ft_printf("%d key (ESC) pressed.", key);
		mlx_destroy_image(d->mlx, d->img);
		mlx_destroy_window(d->mlx, d->win);
		// mlx_loop_end(d->mlx);
		mlx_destroy_display(d->mlx);
		free(d->mlx);
		exit(1);
	}
	return (0);
}

// void zoom(t_data *d, double factor)
// {
// 	cent;
// }

int	mouse(int key, int x, int y, t_data *d)
{
	// if (key == MOUSE_WHEEL_UP)
	// {
	// 	zoom(d, 0.5);
	// }
	// return (0);
}

int	print_help(void)
{
	ft_printf("How to use:\n");
	ft_printf("-------------------------------------------\n");
	ft_printf("./fractol mandelbrot\n");
	ft_printf("or\n");
	ft_printf("./fractol julia -3 17\n");
	ft_printf("where '-3' and '17' can be replaced by any integers");
	ft_printf(" between 200000 and -200000.\n");
	return (0);
}

// int	end_fractol(t_data *mlx)
// {
// 	free(mlx);
// 	return (0);
// }

int	main(int argc, char **argv)
{
	t_data	d;

	if (!(argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)))
		if (!(argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
			return (print_help());
	d.mlx = mlx_init();
	if (!d.mlx)
		return (1);
	d.win = mlx_new_window(d.mlx, W, H, "First window");
	if (!d.win)
	{
		mlx_destroy_display(d.mlx);
		free(d.mlx);
		return (1);
	}
	d.img = mlx_new_image(d.mlx, W, H);
	if (!d.img)
	{
		mlx_destroy_display(d.mlx);
		mlx_destroy_window(d.mlx, d.win);
		free(d.mlx);
		return (1);
	}
	d.ad = mlx_get_data_addr(d.img, &d.bpp, &d.line_sz, &d.endi);
	draw(&d, argv);
	mlx_put_image_to_window(d.mlx, d.win, d.img, 0, 0);
	// mlx_hook(d.win, 17, 0, end_fractol, &d);
	mlx_key_hook(d.win, key, &d);
	mlx_mouse_hook(d.win, mouse, &d);
	mlx_loop(d.mlx);
	// mlx_destroy_window(d.mlx, d.win);
	// mlx_destroy_display(d.mlx);
	// free(d.mlx);
	return (1);
}
