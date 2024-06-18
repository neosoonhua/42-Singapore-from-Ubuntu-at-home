/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 01:20:15 by sneo              #+#    #+#             */
/*   Updated: 2024/06/16 01:20:19 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_t_data(t_data *d)
{
	if (d)
	{
		free(d->mlx);
		d->mlx = NULL;
		free(d);
		d = NULL;
	}
}

void destroy_and_free(t_data *d)
{
	mlx_destroy_image(d->mlx, d->img);
	mlx_destroy_window(d->mlx, d->win);
	mlx_destroy_display(d->mlx);
	free_t_data(d);
	exit(0);
}
