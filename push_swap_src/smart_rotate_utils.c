/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rotate_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:15:19 by welim             #+#    #+#             */
/*   Updated: 2022/08/15 14:14:39 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//type 1 == find idx of smallest num
//type 2 == find idx of largest num
int	get_minmax(int *stack, int size, int type)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	if (type == 1)
	{
		while (i < size)
		{
			if (i > 0 && stack[i] < stack[res])
				res = i;
			i++;
		}
	}
	else
	{
		while (i < size)
		{
			if (i > 0 && stack[i] > stack[res])
				res = i;
			i++;
		}
	}
	return (res);
}

int	get_index_a(t_data *data, int index)
{
	int		i;
	int		temp;
	int		size;

	i = 0;
	temp = -1;
	size = data->len_a;
	while (i < size)
	{
		if (data->stack_a[i] > data->stack_b[index])
		{
			if (temp == -1)
				temp = i;
			else if (data->stack_a[temp] > data->stack_a[i])
				temp = i;
		}
		i++;
	}
	if (temp == -1)
		return (-1);
	else
		return (temp);
}

int	get_moves(t_data *data, int index, int type)
{
	int	moves_a;
	int	moves_b;

	if (index <= data->len_b / 2)
		moves_b = index;
	else
		moves_b = data->len_b - index;
	if (get_index_a(data, index) < 0)
		moves_a = find_asc(data);
	else if (get_index_a(data, index) <= data->len_a / 2)
		moves_a = get_index_a(data, index);
	else
		moves_a = data->len_a - get_index_a(data, index);
	if (type == 1)
		return (moves_b);
	else
		return (moves_a);
}

int	find_asc(t_data *data)
{
	int	min;

	min = get_minmax(data->stack_a, data->len_a, 1);
	if (min <= data->len_a / 2)
		return (min);
	else
		return (data->len_a - min);
}

void	sort_asc(t_data *data)
{
	int	min;

	min = get_minmax(data->stack_a, data->len_a, 1);
	if (min < data->len_a / 2)
		rotate_multi(data, min, 1);
	else if (min >= data->len_a / 2)
		rotate_multi(data, data->len_a - min, 2);
}
