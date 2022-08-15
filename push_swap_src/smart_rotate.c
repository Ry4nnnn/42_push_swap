/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:19:02 by welim             #+#    #+#             */
/*   Updated: 2022/08/15 14:02:35 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_rotate(t_data *data, int index)
{
	int		min;
	int		diff;
	int		idx_a;

	diff = data->len_b - index;
	idx_a = get_index_a(data, index);
	min = get_minmax(data->stack_a, data->len_a, 1);
	if (index == 0)
		return (0);
	else if (index <= data->len_b / 2)
	{
		if (idx_a <= data->len_a / 2)
			if (idx_a > -1)
				return (count_moves(index, idx_a));
		if (find_asc(data) == min && idx_a < 0)
			return (count_moves(index, min));
	}
	else if (index > data->len_b / 2)
	{
		if (idx_a > data->len_a / 2)
			return (count_moves(diff, data->len_a - idx_a));
		if (find_asc(data) == data->len_a - min && idx_a < 0)
			return (count_moves(diff, data->len_a - min));
	}
	return (0);
}

static void	check_smartrotate(t_data *data)
{
	int		i;
	int		total;

	i = 0;
	while (i < data->len_b)
	{
		total = get_moves(data, i, 2) + get_moves(data, i, 1) + 1;
		if (check_rotate(data, i))
			total = total - check_rotate(data, i);
		if (data->best_idx < 0 || total < data->total_move)
		{
			data->best_idx = i;
			data->total_move = total;
		}
		else if (total == data->total_move)
		{
			if (data->stack_b[data->best_idx] < data->stack_b[i])
			{
				data->best_idx = i;
				data->total_move = total;
			}
		}
		i++;
	}
}

/* 1 = rb rrb, 2 = ra rra */
static void	rotate_remainder(t_data *data, int a, int b, int type)
{
	if (type == 1)
	{
		if (a <= data->len_b / 2)
			rotate_multi_b(data, a, 1);
		else if (b > data->len_b / 2)
			rotate_multi_b(data, data->len_b - b, 2);
	}
	else
	{
		if (a <= data->len_a / 2)
			rotate_multi(data, a, 1);
		else if (b > data->len_a / 2)
			rotate_multi(data, data->len_a - b, 2);
	}
}

static void	smartrotate(t_data *data)
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;

	data->rt_both = check_rotate(data, data->best_idx);
	rb = data->best_idx;
	rrb = data->best_idx;
	ra = get_index_a(data, data->best_idx);
	rra = get_index_a(data, data->best_idx);
	if (check_rotate(data, data->best_idx))
	{
		if (data->best_idx <= data->len_b / 2)
			addmoves(data, &ra, &rb, 1);
		else
			addmoves(data, &rra, &rrb, 2);
	}
	if (ra < 0)
		sort_asc(data);
	rotate_remainder(data, rb, rrb, 1);
	rotate_remainder(data, ra, rra, 2);
}

void	push_to_a(t_data *data)
{
	int		i;
	int		size;

	i = 2;
	size = data->len_b;
	push_a(data);
	push_a(data);
	while (i < size)
	{
		data->best_idx = -1;
		data->total_move = -1;
		check_smartrotate(data);
		smartrotate(data);
		push_a(data);
		i++;
	}
	sort_asc(data);
}
