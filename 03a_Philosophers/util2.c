/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 23:46:47 by sneo              #+#    #+#             */
/*   Updated: 2024/09/03 23:46:52 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
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
			perror("Not digit");
		result = result * 10 + str[i++] - '0';
	}
	if (count_neg % 2 == 1)
		result *= -1;
	if (result > (long)INT_MAX || result < (long)INT_MIN)
		perror("Not between INT_MAX and INT_MIN");
	return (result);
}

long long	mstime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	error(t_d *d, char *msg)
{
	printf("%s\n", msg);
	clean(d);
	return ;
}
