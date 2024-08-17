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

static void *ph_start(void *arg)
{
	struct ph_info *tinfo = arg;
	char *uargv;

	printf("ph %d: top of stack near %p; argv_string=%s\n",
			  tinfo->ph_num, tinfo, tinfo->argv_string);

	uargv = strdup(tinfo->argv_string);
	if (uargv == NULL)
		 handle_error("strdup");

	for (char *p = uargv; *p != '\0'; p++)
		 *p = toupper(*p);

	return uargv;
}

int	print_help(void)
{
	ft_printf("How to use:\n");
	ft_printf("-------------------------------------------\n");
	ft_printf("./philo number_of_philosophers time_to_die time_to_eat ");
	ft_printf("time_to_sleep ");
	ft_printf("[(optional) number_of_times_each_philosopher_must_eat]\n");
	return (0);
}

void	values_init(t_da *d, char **argv)
{
	da.num_ph = ft_atoi(argv[1]);
	da.tt_die = ft_atoi(argv[2]);
	da.tt_eat = ft_atoi(argv[3]);
	da.tt_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		da.must_eat = ft_atoi(argv[5]);
	else
		da.must_eat = -1;
}

int	main(int argc, char **argv)
{
	t_da	da;
	pthread_attr_t attr;
	size_t stack_size;
	void *res;

	values_init(argv);
	//Stopped here
	/* Allocate memory for pthread_create() arguments */

	struct ph_info *tinfo = calloc(num_ph, sizeof(*tinfo));
	if (tinfo == NULL)
		 handle_error("calloc");

	/* Create one thread for each command-line argument */

	for (int tnum = 0; tnum < num_ph; tnum++) {
		 tinfo[tnum].ph_num = tnum + 1;
		 tinfo[tnum].argv_string = argv[optind + tnum];

		 /* The pthread_create() call stores the ph ID into
			 corresponding element of tinfo[] */

		 s = pthread_create(&tinfo[tnum].ph_id, &attr,
								  &ph_start, &tinfo[tnum]);
		 if (s != 0)
			  handle_error_en(s, "pthread_create");
	}

	/* Destroy the thread attributes object, since it is no
		longer needed */

	s = pthread_attr_destroy(&attr);
	if (s != 0)
		 handle_error_en(s, "pthread_attr_destroy");

	/* Now join with each thread, and display its returned value */

	for (int tnum = 0; tnum < num_ph; tnum++) {
		 s = pthread_join(tinfo[tnum].ph_id, &res);
		 if (s != 0)
			  handle_error_en(s, "pthread_join");

		 printf("Joined with thread %d; returned value was %s\n",
					tinfo[tnum].ph_num, (char *) res);
		 free(res);		/* Free memory allocated by thread */
	}

	free(tinfo);
	exit(EXIT_SUCCESS);
}
