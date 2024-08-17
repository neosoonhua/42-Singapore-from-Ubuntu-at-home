/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 22:58:19 by sneo              #+#    #+#             */
/*   Updated: 2024/08/17 22:58:28 by sneo             ###   ########.fr       */
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
			perror("ft_isdigit");
		result = result * 10 + str[i++] - '0';
	}
	if (count_neg % 2 == 1)
		result *= -1;
	if (result > (long)INT_MAX || result < (long)INT_MIN)
		perror("Not between INT_MAX and INT_MIN");
	return (result);
}

void *p_start(void *arg)
{
	t_p *p = arg;
	printf("p %d: top of stack near %p;\n",
			  p->p_num, p);
	return (NULL);
}

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
	d->tt_die = ft_atoi(argv[2]);
	d->tt_eat = ft_atoi(argv[3]);
	d->tt_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		d->must_eat = ft_atoi(argv[5]);
	else
		d->must_eat = -1;
}

int	main(int argc, char **argv)
{
	t_d	d;
	t_p *p;
	void *res;
	int	i;
	int	s;

	values_init(&d, argc, argv);
	/* Allocate memory for pthread_create() arguments */
	p = malloc(d.num_p * sizeof(*p));
	if (p == NULL)
		 handle_error("malloc");
	/* Create one thread for each command-line argument */
	i = 0;
	while (i < d.num_p)
	{
		p[i].p_num = i + 1;
		/* The pthread_create() call stores the p ID into
			 corresponding element of p[] */
		s = pthread_create(&p[i].p_id, NULL, &p_start, &p[i]);
		if (s != 0)
			handle_error_en(s, "pthread_create");
	}
	/* Now join with each thread, and display its returned value */
	i = 0;
	while (i < d.num_p)
	{
		s = pthread_join(p[i].p_id, &res);
		if (s != 0)
			handle_error_en(s, "pthread_join");
		printf("Joined with thread %d; returned value was %s\n",
		 p[i].p_num, (char *) res);
		free(res);		/* Free memory allocated by thread */
	}
	free(p);
	exit(EXIT_SUCCESS);
}
