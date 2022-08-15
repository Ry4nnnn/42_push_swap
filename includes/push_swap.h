/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:19:06 by welim             #+#    #+#             */
/*   Updated: 2022/08/15 14:20:26 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_data
{
	int		*stack_a;
	int		*stack_b;
	int		len_a;
	int		len_b;
	int		argc;
	int		min_num;
	int		max_num;
	int		total_chunk;
	int		chunk_size;
	int		chunk_remainder;
	int		threshold;
	int		up_threshold;
	int		low_threshold;
	int		best_idx;
	int		total_move;
	int		rt_both;
}	t_data;

//moves
void	push_a(t_data *data);
void	push_b(t_data *data);
void	rev_rotate(t_data *data, int type);
void	rotate(t_data *data, int type);
void	swap_top(t_data *data, int type);

//check_sorted.c
int		check_sorted(t_data *data);

//create_stack.c
void	create_stack(t_data *data, char **argv);

//insertion_sort.c
void	insertion_sort(t_data *data, int size);

//optimize_numbers
void	optimize_numbers(t_data *data);

//push_threshold.c
int		push_threshold(t_data *data);

//smart_rotate_utils.c
int		get_minmax(int *stack, int size, int type);
int		get_index_a(t_data *data, int index);
int		get_moves(t_data *data, int index, int type);
int		find_asc(t_data *data);
void	sort_asc(t_data *data);

//smart_rotate_utils2.c
int		count_moves(int i, int j);
void	rotate_multi(t_data *data, int amount, int type);
void	rotate_multi_b(t_data *data, int amount, int type);
void	rotate_both(t_data *data, int amount, int type);
void	addmoves(t_data *data, int *a, int *b, int type);

//smart_rotate.c
void	push_to_a(t_data *data);

//sort_small_num
void	sort_stack(t_data *data);

#endif
