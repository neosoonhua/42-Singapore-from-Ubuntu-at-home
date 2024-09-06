/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 22:58:37 by sneo              #+#    #+#             */
/*   Updated: 2024/09/03 20:37:01 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <ctype.h>
# include <limits.h>
# include <sys/time.h>

struct	s_d;

typedef struct s_p {
	int					id;
	pthread_mutex_t		*lf;
	pthread_mutex_t		*rf;
	long long			last_meal_time;
	int					meals_eaten;
	struct s_d			*d;
}	t_p;

typedef struct s_d {
	int				num_p;
	int				ttdie;
	int				tteat;
	int				ttsleep;
	int				musteat;
	int				one_died;
	pthread_mutex_t	death_lock;
	t_p				*p;
	pthread_mutex_t	*forks;
	pthread_t		*threads;
	long long		st;
}	t_d;

void		*check_all_dbh(void *arg_d);
void		*eatsleepthink(void *arg_p);
void		clean(t_d *d);
long long	mstime(void);
void		error(t_d *d, char *msg);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
#endif
