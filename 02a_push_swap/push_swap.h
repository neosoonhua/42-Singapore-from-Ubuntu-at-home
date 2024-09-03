/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:35:02 by sneo              #+#    #+#             */
/*   Updated: 2023/10/03 10:35:02 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>

typedef struct stack {
	int	*s;
	int	len;
}	t_stk;

typedef t_stk*	t_stp;

t_stp	t_stp_cpy(t_stp dest, const t_stp src);
void	free_all(t_stp a, t_stp b, int *arr);
int		*e(t_stp c, int element);
void	print_array(t_stp c);
int		z(t_stp c);
void	sw(t_stp a, t_stp b);
void	pu(t_stp from, t_stp to, char to_which_stack);
void	pb_rr(t_stp a, t_stp b);
void	pb_rb(t_stp a, t_stp b);
void	r_up(t_stp a, t_stp b);
void	r_up_many(t_stp a, t_stp b, int how_many);
void	rr_down(t_stp a, t_stp b);
void	rr_down_many(t_stp a, t_stp b, int how_many);
int		sorted(t_stp a, t_stp b);
void	sort_2_or_3(t_stp a);
void	sort_more_than_3(t_stp a, t_stp b, int num_groups);
int		in(t_stp a, int index, int gp, int num_gps);
void	to_b(t_stp a, t_stp b, int num_gps);
int		min(t_stp c);
int		find(t_stp c, int to_find);
int		small(int x, int y);
void	up_or_down_stack_a(t_stp a, int i);
void	push_to_correct_pl(t_stp a, t_stp b, int ib, int option);
void	back_to_a(t_stp a, t_stp b);

#endif