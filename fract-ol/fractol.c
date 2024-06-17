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
		free_t_data(d);
		exit(1);
	}
	return (0);
}

static void zoom(t_data *d, double factor, char **argv)
{
	double	x_range;
	double	y_range;

	printf("zoom\n");
	printf("xl: %lf\n", d->xl);
	printf("xh: %lf\n", d->xh);
	printf("yl: %lf\n", d->yl);
	printf("yh: %lf\n", d->yh);
	x_range = d->xh - d->xl;
	y_range = d->yh - d->yl;
	if (factor < 1)
	{
		d->xl = d->xl + x_range * factor * 0.5;
		d->xh = d->xh - x_range * factor * 0.5;
		d->yl = d->yl + y_range * factor * 0.5;
		d->yh = d->yh - y_range * factor * 0.5;		
	}
	else if (factor > 1)
	{
		d->xl *= 2;
		d->xh *= 2;
		d->yl *= 2;
		d->yh *= 2;
	}
	mlx_clear_window(d->mlx, d->win);
	draw(d, argv);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
}

int	mouse(int key, int x, int y, t_data *d)
{
	printf("mouse\n");
	if (key == MOUSE_WHEEL_UP)
	{
		zoom(d, 0.5, d->argv);
	}
	if (key == MOUSE_WHEEL_DOWN)
	{
		zoom(d, 2, d->argv);
	}
	return (0);
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

void null_init(t_data *d)
{
	d->img = NULL;
	d->ad = NULL;
	d->bpp = 0;
	d->line_sz = 0;
	d->endi;
	d->mlx = NULL;
	d->win = NULL;
	d->frac = 0;
	d->xl = 0.0;
	d->xh = 0.0;
	d->yl = 0.0;
	d->yh = 0.0;
	d->argv = NULL;
}

void values_init(t_data *d, char **argv)
{
	if (!ft_strncmp(argv[1], "mande", 5))
	{
		d->frac = MANDELBROT;
		d->xl = -2;
		d->xh = 2;
		d->yl = -2;
		d->yh = 2;
	}
	else if (!ft_strncmp(argv[1], "julia", 5))
	{
		d->frac = JULIA;
		d->xl = -2;
		d->xh = 2;
		d->yl = -2;
		d->yh = 2;
	}
}

int	main(int argc, char **argv)
{
	t_data	*d;

	d = ft_calloc(1, sizeof(t_data));
	null_init(d);
	if (!(argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)))
		if (!(argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
			return (print_help());
	values_init(d, argv);
	d->mlx = mlx_init();
	if (!d->mlx)
		return (1);
	d->win = mlx_new_window(d->mlx, W, H, "First window");
	if (!d->win)
	{
		mlx_destroy_display(d->mlx);
		free(d->mlx);
		return (1);
	}
	d->img = mlx_new_image(d->mlx, W, H);
	if (!d->img)
	{
		mlx_destroy_display(d->mlx);
		mlx_destroy_window(d->mlx, d->win);
		free(d->mlx);
		return (1);
	}
	d->ad = mlx_get_data_addr(d->img, &d->bpp, &d->line_sz, &d->endi);
	draw(d, argv);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	// mlx_hook(d->win, 17, 0, end_fractol, d);
	mlx_key_hook(d->win, key, d);
	mlx_mouse_hook(d->win, mouse, d);
	mlx_loop(d->mlx);
	// mlx_destroy_window(d->mlx, d->win);
	// mlx_destroy_display(d->mlx);
	// free(d->mlx);
	return (1);
}
