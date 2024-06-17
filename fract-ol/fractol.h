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

# define MAX_ITER 47
# define H 800
# define W 800

// # define MOUSE_BTN 1
# define MOUSE_WHEEL_UP 4

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
}	t_data;

// typedef struct s_complex {
// 	double	r;
// 	double	i;
// }	t_com;

// void	pixel_put(t_data *d, int x, int y, int color);
double	txf(double a, double max, t_data *d, char x_or_y);
int		print_help();
int		free_many(char *arr1, char *arr2, char **arr3, char *arr4);
void	draw(t_data *data_p, char **argv);

#endif
