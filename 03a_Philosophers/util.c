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
	return ;
}

int	check_one_dbh(t_p *p)
{
	t_d	*d;

	d = p->d;
	if (tfs(d) - p->last_meal_time >= d->ttdie)
	{
		pthread_mutex_lock(&d->death_lock);
		d->one_died = 1;
		printf("d->one_died = 1");
		pthread_mutex_unlock(&d->death_lock);
		prints(p, 'd');
		return (1);
	}
	return (0);
}

void	*check_all_dbh(void *arg_d)
{
	int	i;
	t_d	*d;

	d = (t_d *)arg_d;
	pthread_mutex_lock(&d->death_lock);
	while (d->one_died == 0)
	{
		pthread_mutex_unlock(&d->death_lock);
		i = 0;
		while (i < d->num_p)
		{
			if (check_one_dbh(&d->p[i++]))
				break ;
		}
		usleep(1000);
	}
	return (NULL);
}

void	*eatsleepthink(void *arg_p)
{
	t_p	*p;

	p = (t_p *)arg_p;
	pthread_mutex_lock(&p->d->death_lock);
	while (p->d->one_died == 0)
	{
		pthread_mutex_unlock(&p->d->death_lock);
		if (p->id % 2 == 1)
		{
			pthread_mutex_lock(p->lf);
			prints(p, 'f');
			if (p->d->num_p == 1)
			{
				usleep(p->d->ttdie * 1000);
				prints(p, 'd');
				pthread_mutex_lock(&p->d->death_lock);
				p->d->one_died = 1;
				pthread_mutex_unlock(&p->d->death_lock);
				return (NULL);
			}
			pthread_mutex_lock(p->rf);
			prints(p, 'f');
		}
		else
		{
			pthread_mutex_unlock(&p->d->death_lock);
			pthread_mutex_lock(p->rf);
			prints(p, 'f');
			pthread_mutex_lock(p->lf);
			prints(p, 'f');
		}
		p->last_meal_time = tfs(p->d);
		prints(p, 'e');
		p->meals_eaten++;
		usleep(p->d->tteat * 1000);
		pthread_mutex_unlock(p->lf);
		pthread_mutex_unlock(p->rf);
		prints(p, 's');
		usleep(p->d->ttsleep * 1000);
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
	pthread_mutex_destroy(&d->death_lock);
	free(d->p);
	// free(&d->death_lock);
	free(d->forks);
	free(d->threads);
	return ;
}
