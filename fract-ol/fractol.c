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
#include <stdio.h> //To delete

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

int	mouse(int key, int x, int y, t_data *d)
{
	char	**split;

	if (key == MOUSE_BTN)
	{
		mlx_clear_window(d->mlx, d->win);
		split = ft_split("./fractol julia -0.65 1.02", ' ');
		draw(d, split); //Not working.
		free_many(NULL, split, NULL);
		mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	}
	return (0);
}

int	print_help(void)
{
	ft_printf("How to use:\n");
	ft_printf("-------------------------------------------\n");
	ft_printf("./fractol mandelbrot\n");
	ft_printf("or\n");
	ft_printf("anything julia -0.3 0.7\n");
	ft_printf("where '-0.3' and '0.7' can be replaced by any numbers between 10 and -10 and up to 5 decimal places.\n");
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
	// mlx_hook(d.win, 17, 0, end_fractol, &d);
	mlx_key_hook(d.win, key, &d);
	mlx_mouse_hook(d.win, mouse, &d);
	mlx_loop(d.mlx);
	// mlx_destroy_window(d.mlx, d.win);
	// mlx_destroy_display(d.mlx);
	// free(d.mlx);
	return (1);
}
