/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:40:30 by sneo              #+#    #+#             */
/*   Updated: 2024/09/03 22:19:23 by sneo             ###   ########.fr       */
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
		printf("%lld\t%d has taken Fork %d\n", tfs(d), p->id, p->id % p->d->num_p);
	else if (a == 'r')
		printf("%lld\t%d has taken Fork %d\n", tfs(d), p->id, (p->id + 1) % p->d->num_p);
	else if (a == 'f')
		printf("%lld\t%d has taken a fork\n", tfs(d), p->id);
	else if (a == 't')
		printf("%lld\t%d is thinking\n", tfs(d), p->id);
	else if (a == 's')
		printf("%lld\t%d is sleeping\n", tfs(d), p->id);
	else if (a == 'e')
		printf("%lld\t%d is eating\n", tfs(d), p->id);
	else if (a == 'd')
		printf("%lld\t%d died\n", tfs(d), p->id);
	return ;
}

int	clmt(t_p *p)
{
	t_d	*d;

	d = p->d;
	if (tfs(d) - p->last_meal_time >= d->ttdie)
	{
		d->one_died = 1;
		prints(p, 'd');
	}
	return (0);
}

void	*eatsleepthink(void *arg)
{
	t_p	*p;

	p = (t_p *)arg;
	while (p->d->one_died == 0)
	{
		clmt(p);
		if (p->id % 2 == 1)
		{
			pthread_mutex_lock(p->lf);
			prints(p, 'f');
			if (p->d->num_p == 1)
			{
				usleep(p->d->ttdie * 1000);
				prints(p, 'd');
				p->d->one_died = 1;
				return (NULL);
			}
			pthread_mutex_lock(p->rf);
			prints(p, 'f');
		}
		else
		{
			pthread_mutex_lock(p->rf);
			prints(p, 'f');
			pthread_mutex_lock(p->lf);
			prints(p, 'f');
		}
		clmt(p);
		p->last_meal_time = tfs(p->d);
		prints(p, 'e');
		p->meals_eaten++;
		usleep(p->d->tteat * 1000);
		clmt(p);
		pthread_mutex_unlock(p->lf);
		pthread_mutex_unlock(p->rf);
		prints(p, 's');
		usleep(p->d->ttsleep * 1000);
		clmt(p);
		prints(p, 't');
		clmt(p);
	}
	return (NULL);
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
