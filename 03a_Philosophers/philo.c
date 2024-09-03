/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 22:58:19 by sneo              #+#    #+#             */
/*   Updated: 2024/09/03 20:17:34 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_help(void)
{
	printf("How to use:\n");
	printf("-------------------------------------------\n");
	printf("./philo number_of_philosophers time_to_die time_to_eat ");
	printf("time_to_sleep ");
	printf("[(optional) number_of_times_each_philosopher_must_eat]\n");
	return (0);
}

void	values_init(t_d *d, int argc, char **argv)
{
	d->num_p = ft_atoi(argv[1]);
	d->ttdie = ft_atoi(argv[2]);
	d->tteat = ft_atoi(argv[3]);
	d->ttsleep = ft_atoi(argv[4]);
	if (argc == 6)
		d->musteat = ft_atoi(argv[5]);
	else
		d->musteat = -1;
	printf("num_p: %d\n", d->num_p);
	printf("ttdie: %d\n", d->ttdie);
	printf("tteat: %d\n", d->tteat);
	printf("ttsleep: %d\n", d->ttsleep);
	printf("musteat: %d\n", d->musteat);
}

void	philos_init(t_d *d)
{
	int	i;

	i = 0;
	while (i < d->num_p)
	{
		d->p[i].id = i + 1;
		d->p[i].lf = &d->forks[i];
		d->p[i].rf = &d->forks[(i + 1) % d->num_p];
		d->p[i].d = d;
		d->p[i].last_meal_time = 0;
		d->one_died = 0;
		pthread_mutex_init(&d->forks[i], NULL);
		i++;
	}
}

void	start(t_d *d)
{
	int	i;

	i = 0;
	while (i < d->num_p)
	{
		if (pthread_create(&d->threads[i], NULL, eatsleepthink, &d->p[i]) != 0)
			error(d, "pthread_create failed");
		i++;
	}

	i = 0;
	while (i < d->num_p)
	{
		pthread_join(d->threads[i], NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_d	d;

	if (argc < 5 || argc > 6)
		return (print_help());
	values_init(&d, argc, argv);
	d.p = malloc(d.num_p * sizeof(t_p));
	d.forks = malloc(d.num_p * sizeof(pthread_mutex_t));
	d.threads = malloc(d.num_p * sizeof(pthread_t));
	if (d.p == NULL || d.forks == NULL || d.threads == NULL)
		error(&d, "malloc");
	philos_init(&d);
	start(&d);
	clean(&d);
	return (0);
}
