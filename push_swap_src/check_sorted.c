/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:25:59 by welim             #+#    #+#             */
/*   Updated: 2022/08/11 21:26:04 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//this function is to check whether array is sorted
//sorted  = 1;
//not sorted = 0;
int	check_sorted(t_data *data)
{
	int		i;
	int		res;

	i = 1;
	res = 1;
	while (i < data->len_a)
	{
		if (data->stack_a[i - 1] > data->stack_a[i])
		{
			res = 0;
			break ;
		}
		i++;
	}
	if (res == 1)
		return (1);
	else
		return (0);
}
