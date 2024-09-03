/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 08:06:25 by sneo              #+#    #+#             */
/*   Updated: 2023/10/27 08:06:25 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		file;
	char	*next_line;

	file = 0;
	if (argc > 1)
	{
		file = open(argv[1], O_RDONLY);
		if (file == -1)
		{
			printf("Error opening the file");
			return (0);
		}
		while (1)
		{
			next_line = get_next_line(file);
			if (next_line == NULL)
				break ;
			printf("%s", next_line);
			free(next_line);
		}
	}
	close(file);
	return (1);
}
