/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:22:26 by welim             #+#    #+#             */
/*   Updated: 2022/09/01 21:28:23 by welim            ###   ########.fr       */
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

static	int	find_after(t_data *data, int size)
{
	int	i;
	int	temp;
	int	updated;

	i = 0;
	temp = 0;
	updated = 0;
	while (i < size)
	{
		if (data->stack_a[i] > data->stack_b[0])
		{
			if (updated == 0)
			{
				temp = i;
				updated = 1;
			}
			else if (data->stack_a[i] < data->stack_a[temp])
				temp = i;
		}
		i++;
	}
	if (updated == 0)
		return (-1);
	else
		return (temp);
}

static	void	push_back(t_data *data, int size)
{
	int	i;

	i = find_after(data, size);
	if (i > -1)
	{
		if (i == 1)
			rotate(data, 1);
		else if ((i == 2 && size == 3) || i == 3)
			rev_rotate(data, 1);
		else if (i == 2 && size == 4)
		{
			rotate(data, 1);
			rotate(data, 1);
		}
		push_a(data);
	}
	else
	{
		sort_asc(data);
		push_a(data);
		rotate(data, 1);
	}
}

static	void	sort_5(t_data *data)
{
	push_b(data);
	push_b(data);
	sort_3(data);
	push_back(data, 3);
	push_back(data, 4);
	sort_asc(data);
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
			sort_5(data);
	}
	else if (data->len_a <= 250)
		insertion_sort(data, 2);
	else
		insertion_sort(data, 4);
}
