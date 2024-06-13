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
	key++;
	param++;
	return (0);
}

int	print_help(void)
{
	ft_printf("How to use:\n");
	ft_printf("-------------------------------------------\n");
	ft_printf("./fractol mandelbrot\n");
	ft_printf("or\n");
	ft_printf("./fractol julia 0.3 0.7\n");
	ft_printf("where '0.3' and '0.7' can be replaced by any numbers.\n");
	return (0);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	t_data	im;

	if (!(argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)))
		if (!(argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
			return (print_help());
	mlx = mlx_init();
	if (!mlx)
		return (1);
	win = mlx_new_window(mlx, W, H, "First window");
	if (!win)
	{
		mlx_destroy_display(mlx);
		free(mlx);
		return (1);
	}
	im.i = mlx_new_image(mlx, W, H);
	if (!im.a)
	{
		mlx_destroy_display(mlx);
		mlx_destroy_window(mlx, win);
		free(mlx);
		return (1);
	}
	im.a = mlx_get_data_addr(im.i, &im.b, &im.l, &im.e);
	draw(&im);
	mlx_put_image_to_window(mlx, win, im.i, 0, 0);
	mlx_loop(mlx);
	mlx_key_hook(win, handle_input, NULL);
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
	return (1);
}
