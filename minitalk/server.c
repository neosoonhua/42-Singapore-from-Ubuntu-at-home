/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:19:59 by sneo              #+#    #+#             */
/*   Updated: 2024/06/25 13:20:02 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_sv	sv;

void	sv_hdlr(int num, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	(void)info;
	if (sv.flag == 1)
	{
		sv.ch = 0;
		sv.i = 0;
	}
	sv.ch = sv.ch << 1;
	if (num == SIGUSR1)
		sv.ch = sv.ch | 1;
	sv.i++;
	if (sv.i >= 8)
	{
		sv.i = 0;
		write(1, &sv.ch, 1);
	}

}

int	main(void)
{
	struct	sigaction	ac;

	ft_printf(1, "Server's PID: %d\n", getpid());
	sigemptyset(&ac.sa_mask);
	ac.sa_flags = SA_SIGINFO;
	ac.sa_sigaction = sv_hdlr;
	sigaction(SIGUSR1, &ac, NULL);
	sigaction(SIGUSR2, &ac, NULL);
	while (1)
		pause();
	return (0);
}
	