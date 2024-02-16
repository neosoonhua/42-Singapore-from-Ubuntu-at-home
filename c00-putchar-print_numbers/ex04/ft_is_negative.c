/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:20:24 by sneo              #+#    #+#             */
/*   Updated: 2023/07/28 15:37:05 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	char_neg;
	char	char_pos;

	char_pos = 'P';
	char_neg = 'N';
	if (n < 0)
	{
		write(1, &char_neg, 1);
	}
	else
	{
		write(1, &char_pos, 1);
	}
}
/*
int	main(void)
{
	ft_is_negative(0);
}
*/
