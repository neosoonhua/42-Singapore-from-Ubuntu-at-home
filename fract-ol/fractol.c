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

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (!mlx)
	{
		//Handle the error.
		return (1);
	}
	win = mlx_new_window(mlx, 400, 300, "First window");
	mlx_key_hook(win, handle_input, NULL);
	mlx_loop(mlx);
	mlx_destroy_display(mlx);
	free(mlx);
	return (0);
}