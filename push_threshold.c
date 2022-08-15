/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_threshold.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 22:06:56 by welim             #+#    #+#             */
/*   Updated: 2022/08/15 13:57:31 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_threshold_min(t_data *data, int type)
{
	int		i;

	if (type == 1)
	{
		i = 0;
		while (i < data->len_a)
		{
			if (data->stack_a[i] >= data->low_threshold)
				if (data->stack_a[i] <= data->up_threshold)
					return (i);
			i++;
		}
	}
	else
	{
		i = data->len_a - 1;
		while (i > -1)
		{
			if (data->stack_a[i] >= data->low_threshold)
				if (data->stack_a[i] <= data->up_threshold)
					return (i);
			i--;
		}
	}
	return (-1);
}

static void	rotate_over(t_data *data, int hold_a, int hold_b)
{
	if (hold_a == hold_b)
	{
		if (hold_a <= data->len_a / 2)
			rotate_multi(data, hold_a, 1);
		else
			rotate_multi(data, data->len_a - hold_a, 2);
	}
	else
	{
		if (hold_a <= data->len_a - hold_b)
			rotate_multi(data, hold_a, 1);
		else
			rotate_multi(data, data->len_a - hold_b, 2);
	}
}

int	push_threshold(t_data *data)
{
	int		hold_a;
	int		hold_b;

	hold_a = get_threshold_min(data, 1);
	hold_b = get_threshold_min(data, 2);
	if (hold_a == -1)
		return (0);
	else
	{
		rotate_over(data, hold_a, hold_b);
		push_b(data);
		return (1);
	}
}
