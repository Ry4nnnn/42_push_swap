/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:23:13 by welim             #+#    #+#             */
/*   Updated: 2022/08/11 21:23:49 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	replace_num_a(t_data *data, int *temp, int type)
{
	int	i;

	i = 0;
	if (type == 1)
	{
		while (i < data->len_a)
		{
			temp[i + 1] = data->stack_a[i];
			i++;
		}
	}
	else
	{
		while (i < data->len_a)
		{
			data->stack_a[i] = temp[i];
			i++;
		}
	}
}

void	push_a(t_data *data)
{
	int	i;
	int	*temp;

	i = 1;
	temp = ft_calloc(data->len_a + 1, sizeof(int));
	temp[0] = data->stack_b[0];
	while (i < data->len_b)
	{
		data->stack_b[i - 1] = data->stack_b[i];
		data->stack_b[i++] = 0;
	}
	data->len_b -= 1;
	replace_num_a(data, temp, 1);
	data->len_a += 1;
	replace_num_a(data, temp, 2);
	free(temp);
	ft_putstr_fd("pa\n", 1);
}
