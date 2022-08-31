/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:24:24 by welim             #+#    #+#             */
/*   Updated: 2022/08/11 21:24:26 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	replace_num_b(t_data *data, int *temp, int type)
{
	int	i;

	i = 0;
	if (type == 1)
	{
		while (i < data->len_b)
		{
			temp[i + 1] = data->stack_b[i];
			i++;
		}
	}
	else
	{
		while (i < data->len_b)
		{
			data->stack_b[i] = temp[i];
			i++;
		}
	}
}

void	push_b(t_data *data)
{
	int	i;
	int	*temp;

	i = 1;
	temp = ft_calloc(data->len_b + 1, sizeof(int));
	temp[0] = data->stack_a[0];
	while (i < data->len_a)
	{
		data->stack_a[i - 1] = data->stack_a[i];
		data->stack_a[i++] = 0;
	}
	data->len_a -= 1;
	replace_num_b(data, temp, 1);
	data->len_b += 1;
	replace_num_b(data, temp, 2);
	free(temp);
	ft_putstr_fd("pb\n", 1);
}
