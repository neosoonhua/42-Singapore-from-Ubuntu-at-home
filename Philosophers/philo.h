/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 22:58:37 by sneo              #+#    #+#             */
/*   Updated: 2024/08/17 22:58:42 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

#define handle_error_en(en, msg) \
	do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

#define handle_error(msg) \
	do { perror(msg); exit(EXIT_FAILURE); } while (0)

typedef struct s_ph {	/* Used as argument to ph_start() */
   pthread_t ph_id;	 /* ID returned by pthread_create() */
   int	 ph_num;	/* Application-defined thread # */
}	  t_ph;

typedef struct s_da {	/* Used as argument to ph_start() */
	int	num_ph;
	int	tt_die;
	int	tt_eat;
	int	tt_sleep;
	int	must_eat;
}	  t_da;

#endif
