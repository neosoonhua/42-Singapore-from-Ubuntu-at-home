/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:40:30 by sneo              #+#    #+#             */
/*   Updated: 2024/09/02 04:10:25 by sneo             ###   ########.fr       */
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
	int	i;
	int	count_neg;
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

long long	tfs(t_d *d)
{
	return (mstime() - d->st);
}

void	prints(t_p *p, char a)
{
	t_d	*d;

	d = p->d;
	if (a == 'l')
		printf("%lld\tPhilo %d takes Fork %d\n", tfs(d), p->id, p->id % p->d->num_p);
	else if (a == 'r')
		printf("%lld\tPhilo %d takes Fork %d\n", tfs(d), p->id, (p->id + 1) % p->d->num_p);
	else if (a == 't')
		printf("%lld\tPhilo %d thinks\n", tfs(d), p->id);
	else if (a == 's')
		printf("%lld\tPhilo %d sleeps\n", tfs(d), p->id);
	else if (a == 'e')
		printf("%lld\tPhilo %d eats\n", tfs(d), p->id);
	return ;
}

void	*thinksleepeat(void *arg)
{
	t_p	*p;

	p = (t_p *)arg;
	while (1)
	{
		prints(p, 't');
		usleep(1000 * 1000);
		if (p->id % 2 == 1)
		{
			pthread_mutex_lock(p->lf);
			prints(p, 'l');
			pthread_mutex_lock(p->rf);
			prints(p, 'r');
		}
		else
		{
			pthread_mutex_lock(p->rf);
			prints(p, 'r');
			pthread_mutex_lock(p->lf);
			prints(p, 'l');
		}
		p->last_meal_time = mstime();
		prints(p, 'e');
		p->meals_eaten++;
		usleep(1000 * 1000);
		pthread_mutex_unlock(p->lf);
		pthread_mutex_unlock(p->rf);
		prints(p, 's');
		usleep(1000 * 1000);
	}
	return (NULL);
}

void	monitor(t_d *d)
{
	if (tfs(d) > 9000)
		return (clean(d)) ;
}

void	clean(t_d *d)
{
	int	i;

	i = 0;
	while (i < d->num_p)
		pthread_mutex_destroy(&d->forks[i++]);
	free(d->p);
	free(d->forks);
	free(d->threads);
	return ;
}
