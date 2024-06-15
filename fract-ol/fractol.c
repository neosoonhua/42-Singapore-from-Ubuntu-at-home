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

int	handle_input(int key, t_data *d)
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
	ft_printf("%d key (ESC) pressed.", key);
	return (0);
}

int	print_help(void)
{
	ft_printf("How to use:\n");
	ft_printf("-------------------------------------------\n");
	ft_printf("./fractol mandelbrot\n");
	ft_printf("or\n");
	ft_printf("./fractol julia -0.3 0.7\n");
	ft_printf("where '-0.3' and '0.7' can be replaced by any numbers between 10 and -10 and up to 5 decimal places.\n");
	return (0);
}

int	end_fractol(t_data *mlx)
{
	free(mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	d;

	if (!(argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)))
		if (!(argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
			return (print_help());
	// if (!ft_strncmp(argv[1], "julia", 5))
	// 	printf("%lf\n", ft_atod(argv[2])); //To delete
	// 	printf("%lf\n", ft_atod(argv[3])); //To delete
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
	// pixel_put(&d, 5, 18, 0x00ff0000);
	mlx_put_image_to_window(d.mlx, d.win, d.img, 0, 0);
	// mlx_hook(d.win, 17, 0, end_fractol, &d);
	mlx_key_hook(d.win, handle_input, &d);
	mlx_loop(d.mlx);
	// mlx_destroy_window(d.mlx, d.win);
	// mlx_destroy_display(d.mlx);
	// free(d.mlx);
	return (1);
}
