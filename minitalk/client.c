/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:20:07 by sneo              #+#    #+#             */
/*   Updated: 2024/06/25 13:20:09 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_flag;

void	cli_handler(int num, siginfo_t *info, void *ucontext)
{
	(void)num;
	(void)info;
	(void)ucontext;
	g_flag = 0;
}

void	msg(char *str, int pid)
{
	int				i;
	unsigned char	c;
	int				bit;

	while (*str)
	{
		i = 1;
		c = (unsigned char)(*str);
		while (i <= 8)
		{
			bit = 1 & (c >> (8 - i++));
			if (bit == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(38);
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	ac;
	int					pid;

	if (argc != 3)
	{
		ft_printf(1, "To input: ./client <Server's PID> ");
		ft_printf(1, "\"Message client wants to send to server\"\n");
		exit(1);
	}
	sigemptyset(&ac.sa_mask);
	ac.sa_sigaction = cli_handler;
	ac.sa_flags = SA_SIGINFO;
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf(1, "Invalid PID\n");
		exit(1);
	}
	sigaction(SIGUSR1, &ac, NULL);
	sigaction(SIGUSR2, &ac, NULL);
	msg(argv[2], pid);
	return (0);
}
