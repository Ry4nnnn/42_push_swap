/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_rotate_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:18:47 by welim             #+#    #+#             */
/*   Updated: 2022/08/15 14:17:39 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//for check_rotate();
//return the smallest number 
int	count_moves(int i, int j)
{
	if (i < j)
		return (i);
	else if (j < i)
		return (j);
	else
		return (i);
}

/* 1 = rotate_up, 2 = rotate_down */
void	rotate_multi(t_data *data, int amount, int type)
{
	int		i;

	i = 0;
	if (type == 1)
	{
		while (i < amount)
		{
			rotate(data, 1);
			i++;
		}
	}
	else
	{
		while (i < amount)
		{
			rev_rotate(data, 1);
			i++;
		}
	}
}

/* 1 = rotate_up, 2 = rotate_down */
void	rotate_multi_b(t_data *data, int amount, int type)
{
	int	i;

	i = 0;
	if (type == 1)
	{
		while (i < amount)
		{
			rotate(data, 2);
			i++;
		}
	}
	else
	{
		while (i < amount)
		{
			rev_rotate(data, 2);
			i++;
		}
	}
}

/* 1 = rotate_up, 2 = rotate_down */
void	rotate_both(t_data *data, int amount, int type)
{
	int	i;

	i = 0;
	if (type == 1)
	{
		while (i < amount)
		{
			rotate(data, 3);
			i++;
		}
	}
	else
	{
		while (i < amount)
		{
			rev_rotate(data, 3);
			i++;
		}
	}
}

void	addmoves(t_data *data, int *a, int *b, int type)
{
	if (type == 1)
	{
		rotate_both(data, data->rt_both, 1);
		*a = *a - data->rt_both;
		*b = *b - data->rt_both;
	}
	else
	{
		rotate_both(data, data->rt_both, 2);
		*a = *a + data->rt_both;
		*b = *b + data->rt_both;
	}
}
