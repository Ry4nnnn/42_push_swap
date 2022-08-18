/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:22:26 by welim             #+#    #+#             */
/*   Updated: 2022/08/11 21:22:58 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_data *data)
{
	int		a;
	int		b;
	int		c;

	a = data->stack_a[0];
	b = data->stack_a[1];
	c = data->stack_a[2];
	if (a > b && a < c)
		swap_top(data, 1);
	else if (a < b && a > c)
		rev_rotate(data, 1);
	else if (a > b && a > c && b < c)
		rotate(data, 1);
	else if (a > b && a > c && b > c)
	{
		swap_top(data, 1);
		rev_rotate(data, 1);
	}
	else if (a < b && a < c && b > c)
	{
		swap_top(data, 1);
		rotate(data, 1);
	}
}

static void	push_back2(t_data *data, int mask)
{
	if (mask > data->stack_a[1] && mask < data->stack_a[2])
	{
		rotate(data, 1);
		rotate(data, 1);
		push_a(data);
		rev_rotate(data, 1);
		rev_rotate(data, 1);
	}
	if (mask > data->stack_a[0] && mask < data->stack_a[1])
	{
		rotate(data, 1);
		push_a(data);
		rev_rotate(data, 1);
	}
	if (mask < data->stack_a[0])
		push_a(data);
}

static void	push_back(t_data *data)
{
	int		mask;

	mask = data->stack_b[0];
	if (mask > data->stack_a[data->len_a - 1])
	{
		push_a(data);
		rotate(data, 1);
	}
	if (data->len_a == 4)
	{
		if (mask > data->stack_a[2] && mask < data->stack_a[3])
		{
			rev_rotate(data, 1);
			push_a(data);
			rotate(data, 1);
			rotate(data, 1);
		}
	}
	push_back2(data, mask);
}

void	sort_stack(t_data *data)
{
	if (data->len_a == 2)
	{
		if (!check_sorted(data))
			swap_top(data, 1);
	}
	else if (data->len_a == 3)
	{
		if (!check_sorted(data))
			sort_3(data);
	}
	else if (data->len_a == 5)
	{
		if (!check_sorted(data))
		{
			push_b(data);
			push_b(data);
			sort_3(data);
			push_back(data);
			push_back(data);
		}
	}
	else if (data->len_a <= 250)
		insertion_sort(data, 2);
	else
		insertion_sort(data, 4);
}