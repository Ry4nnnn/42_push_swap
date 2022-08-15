/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 22:04:50 by welim             #+#    #+#             */
/*   Updated: 2022/08/11 22:04:51 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static	void	selection_sort(int *stack, int size)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < size)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (stack[j] < stack[min])
				min = j;
			j++;
		}
		ft_swap(&stack[min], &stack[i]);
		i++;
	}
}

static	int	get_index(t_data *data, int index)
{
	int	i;
	int	*temp;

	i = 0;
	temp = ft_calloc(data->len_a, sizeof(int));
	while (i < data->len_a)
	{
		temp[i] = data->stack_a[i];
		i++;
	}
	selection_sort(temp, data->len_a);
	i = 0;
	while (i < data->len_a)
	{
		if (temp[i] == data->stack_a[index])
		{
			free(temp);
			return (i + 1);
		}
		i++;
	}
	free(temp);
	return (-1);
}

void	optimize_numbers(t_data *data)
{
	int	i;
	int	*temp;

	i = 0;
	temp = ft_calloc(data->len_a, sizeof(int));
	while (i < data->len_a)
	{
		temp[i] = get_index(data, i);
		i++;
	}
	i = 0;
	while (i < data->len_a)
	{
		data->stack_a[i] = temp[i];
		i++;
	}
	free(temp);
}
