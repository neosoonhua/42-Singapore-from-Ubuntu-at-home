/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 06:20:03 by sneo              #+#    #+#             */
/*   Updated: 2024/05/31 06:20:06 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_shell(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "SHELL=", 6))
			return (last_word(envp[i], '/'));
		i++;
	}
	return (NULL);
}

void	infile(t_p p, char **argv, char **envp)
{
	p->io[0] = open(argv[1], O_RDONLY);
	if (p->io[0] < 0)
	{
		ft_printf(1, "%s: ", get_shell(envp));
		ft_printf(1, "no such file or directory: %s\n", argv[1]);
		free_p_and_many(p, NULL, NULL, NULL);
		exit (0);
	}
}

void	outfile(t_p p, char **argv)
{
	p->io[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (p->io[1] < 0)
	{
		perror(argv[4]);
		free_p_and_many(p, NULL, NULL, NULL);
		exit (0);
	}
}

void	in_out(t_p p, char **argv, char **envp)
{
	infile(p, argv, envp);
	outfile(p, argv);
}
