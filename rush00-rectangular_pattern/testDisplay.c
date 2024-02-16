/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testDisplay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:32:39 by sthiagar          #+#    #+#             */
/*   Updated: 2023/07/29 14:03:46 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int	x;
	int	y;
	int	i;
	int	j;
	char	c1;
	char	c2;
	char	c3;

	x = 4;
	y = 4;
	i = 0;
	j = 0;

	while (i < y) 		//rowise set char 
	{
		if(i == 0) 		// 1st row
		{
			c1 = 'A';
		        c2 = 'B';
			c3 = 'C';	
		}
		else if(i == y-1) 	// last row
		{			
			c1 = 'C';
			c2 = 'B';
			c3 = 'A';	
		}
		else 			// middle row
		{

			c1 = 'B';
			c2 = ' ';
			c3 = 'B';
		}

		while (j < x) 	//columnwise write
		{
			if(j == 0)	// 1st col 
			{
				write(1, &c1, 1);
			} 
			else if(j == x-1)// last col
			{
				write(1, &c3, 1);
			}
			else		// middle col
			{
				write(1, &c2, 1);
			}

			++j;
		}

		j = 0;
		write(1, "\n",1);
		++i;
	}
}
