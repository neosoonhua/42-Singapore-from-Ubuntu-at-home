/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:54:28 by sneo              #+#    #+#             */
/*   Updated: 2023/08/11 11:54:28 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stp a, t_stp b, int *arr)
{
	if (a)
	{
		free(a->s);
		a->s = NULL;
		free(a);
		a = NULL;
	}
	if (b)
	{
		free(b->s);
		b->s = NULL;
		free(b);
		b = NULL;
	}
	if (arr)
	{
		free(arr);
		arr = NULL;
	}
}

void	rank(t_stp c)
{
	int		i;
	int		j;
	int		rnk;
	int		*arr;

	arr = ft_calloc(c->len + 4, sizeof(int));
	if (!arr)
		return ;
	i = -1;
	while (++i < c->len)
	{
		rnk = 1;
		j = -1;
		while (++j < c->len)
		{
			if (c->s[i] > c->s[j])
				rnk++;
		}
		arr[i] = rnk;
	}
	i += 4;
	while (--i > -1)
		*(e(c, i)) = arr[i];
	free_all(NULL, NULL, arr);
}

int	checksum(t_stp c, int len)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i++ < z(c))
		sum += *e(c, i);
	if (sum != len * (len + 1) / 2)
		return (0);
	return (1);
}

int	initialise_stacks(int argc, char **argv, t_stp a, t_stp b)
{
	int		i;

	i = -1;
	while (++i < argc - 1)
		if (!ft_atoi(argv[i + 1], &(a->s[i])))
			return (0);
	a->len = argc - 1;
	a->s[argc - 1] = 0;
	a->s[argc] = argc - 2;
	a->s[argc + 1] = 0;
	a->s[argc + 2] = argc - 2;
	b->len = argc - 1;
	b->s[argc - 1] = argc - 1;
	b->s[argc] = argc - 2;
	b->s[argc + 1] = argc - 1;
	b->s[argc + 2] = argc - 2;
	rank(a);
	return (checksum(a, argc - 1));
}

int	main(int argc, char **argv)
{
	t_stp	a;
	t_stp	b;
	int		num_groups;

	if (argc < 2)
		return (0);
	num_groups = (int)ft_sqrt(ft_sqrt(argc - 1));
	a = ft_calloc(1, sizeof(t_stk));
	a->s = ft_calloc(argc + 3, sizeof(int));
	b = ft_calloc(1, sizeof(t_stk));
	b->s = ft_calloc(argc + 3, sizeof(int));
	if (!a || !(a->s) || !b || !(b->s))
		return (0);
	if (!initialise_stacks(argc, argv, a, b))
	{
		free_all(a, b, NULL);
		ft_printf("Error\n");
		return (0);
	}
	if (argc == 3 || argc == 4)
		sort_2_or_3(a);
	else if (!sorted(a, b))
		sort_more_than_3(a, b, num_groups);
	free_all(a, b, NULL);
	return (1);
}
