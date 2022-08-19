/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:24:53 by welim             #+#    #+#             */
/*   Updated: 2022/08/19 12:25:04 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
void	r(t_stack *stack, int type)
{
	if (type == 1 || type == 3)
		shift_up(stack->a, stack->size_a);
	if (type == 2 || type == 3)
		shift_up(stack->b, stack->size_b);
}
