/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:27:47 by sneo              #+#    #+#             */
/*   Updated: 2024/06/13 18:27:53 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mod_atoi(const char *str, t_data *d)
{
	int		i;
	int		count_neg;
	long	result;

	i = 0;
	count_neg = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			count_neg++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (print_help_destroy_free(d));
		result = result * 10 + str[i++] - '0';
	}
	if (count_neg % 2 == 1)
		result *= -1;
	if (result > (long)INT_MAX || result < (long)INT_MIN)
		return (print_help_destroy_free(d));
	return (result);
}

double	txf(double a, double max, t_data *d, char x_or_y)
{
	double	range;
	double	low;
	double	high;

	low = 99999;
	high = -99999;
	if (x_or_y == 'x')
	{
		low = d->xl;
		high = d->xh;
	}
	else if (x_or_y == 'y')
	{
		low = d->yl;
		high = d->yh;
	}
	range = high - low;
	return (a * range / max + low);
}

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

int	destroy_and_free(t_data *d)
{
	mlx_destroy_image(d->mlx, d->img);
	mlx_destroy_window(d->mlx, d->win);
	mlx_destroy_display(d->mlx);
	free_t_data(d);
	exit (0);
	return (1);
}
