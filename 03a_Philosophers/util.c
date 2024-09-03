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

long long	tfs(t_d *d)
{
	return (mstime() - d->st);
}

void	prints(t_p *p, char a)
{
	t_d	*d;

	d = p->d;
	if (a == 'f')
		printf("%lld\t%d has taken a fork\n", tfs(d), p->id);
	else if (a == 't')
		printf("%lld\t%d is thinking\n", tfs(d), p->id);
	else if (a == 's')
		printf("%lld\t%d is sleeping\n", tfs(d), p->id);
	else if (a == 'e')
		printf("%lld\t%d is eating\n", tfs(d), p->id);
	else if (a == 'd')
		printf("%lld\t%d died\n", tfs(d), p->id);
}

int	dbh(t_p *p)
{
	t_d	*d;

	d = p->d;
	if (tfs(d) - p->last_meal_time >= d->ttdie)
	{
		d->one_died = 1;
		prints(p, 'd');
		return (1);
	}
	return (0);
}

void	*eatsleepthink(void *arg)
{
	t_p	*p;

	p = (t_p *)arg;
	while (!p->d->one_died)
	{
		if (!dbh(p))
		{
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
		}
		if (!dbh(p))
		{
			p->last_meal_time = tfs(p->d);
			prints(p, 'e');
			p->meals_eaten++;
			usleep(p->d->tteat * 1000);
		}
		if (!dbh(p))
		{
			pthread_mutex_unlock(p->lf);
			pthread_mutex_unlock(p->rf);
			prints(p, 's');
			usleep(p->d->ttsleep * 1000);
		}
		if (!dbh(p))
			prints(p, 't');
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
}
