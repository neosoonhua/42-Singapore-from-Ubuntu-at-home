/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:36:52 by sneo              #+#    #+#             */
/*   Updated: 2024/01/18 19:37:00 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./libft/libft.h"
# include <stdlib.h>
# include "./minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <math.h>

# define MAX_ITER 147
# define H 800
# define W 800

# define MOUSE_BTN 1
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define CROSS_CLICKED_ON 17

# define MANDELBROT 'm'
# define JULIA 'j'

typedef struct s_data {
	void	*img;
	char	*ad;
	int		bpp;
	int		line_sz;
	int		endi;
	void	*mlx;
	void	*win;
	int		frac;
	double	xl;
	double	xh;
	double	yl;
	double	yh;
	char	**argv;
}	t_data;

// void	pixel_put(t_data *d, int x, int y, int color);
int		mod_atoi(const char *str, t_data *d);
int		key(int key, t_data *d);
int		cross_on_window_frame(t_data *d);
int		mouse(int key, int x, int y, t_data *d);
void	free_t_data(t_data *a);
int		destroy_and_free(t_data *d);
double	txf(double a, double max, t_data *d, char x_or_y);
int		print_help(t_data *d);
void	draw(t_data *data_p);

#endif
