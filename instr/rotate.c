/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:24:53 by welim             #+#    #+#             */
/*   Updated: 2022/08/11 21:25:08 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	shift_up(int *stack, int size)
{
	int		i;
	int		*temp;

	i = 1;
	temp = ft_calloc(size, sizeof(int));
	while (i < size)
	{
		temp[i - 1] = stack[i];
		i++;
	}
	temp[i - 1] = stack[0];
	i = 0;
	while (i < size)
	{
		stack[i] = temp[i];
		i++;
	}
	free(temp);
}

//first top to the last one 123 -> 231
void	rotate(t_data *data, int type)
{
	if (type == 1 || type == 3)
		shift_up(data->stack_a, data->len_a);
	if (type == 2 || type == 3)
		shift_up(data->stack_b, data->len_b);
	if (type == 1)
		ft_putstr_fd("ra\n", 1);
	if (type == 2)
		ft_putstr_fd("rb\n", 1);
	if (type == 3)
		ft_putstr_fd("rr\n", 1);
}
