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
# define H 400
# define W 800

typedef struct s_data {
	void	*img;
	char	*ad;
	int		bpp;
	int		line_sz;
	int		endi;
	void	*mlx;
	void	*win;
}	t_data;

typedef struct s_complex {
	double	r;
	double	i;
}	t_com;

double	ft_atod(const char *str);
void	draw(t_data *data_p, char **argv);

#endif
