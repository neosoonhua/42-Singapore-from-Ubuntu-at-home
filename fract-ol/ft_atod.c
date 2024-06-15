/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 12:11:41 by sneo              #+#    #+#             */
/*   Updated: 2023/08/10 12:16:45 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atod(const char *str)
{
	int		i;
	int		count_neg;
	double	result;
	int		dec_pt_at;

	i = 0;
	count_neg = 0;
	result = 0;
	dec_pt_at = -1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			count_neg++;
	}
	while (str[i])
	{
		// ft_printf("i: %d\n", i);
		// ft_printf("dec_pt_at: %d\n", dec_pt_at);
		if (!ft_isdigit(str[i]) && str[i] != '.')
			error();
		else if (str[i] == '.')
		{
			dec_pt_at = i++;
			// ft_printf("dec_pt_at is changed to: %d\n", dec_pt_at);
		}
		else if (dec_pt_at == -1)
			result = result * 10 + str[i++] - '0';
		else if (dec_pt_at != -1)
			result = result + pow(10, dec_pt_at - i) * (str[i++] - '0');
	}
	if (count_neg % 2 == 1)
		result *= -1;
	if (result > 2 || result < -2)
		error();
	return (result);
}
