/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_r.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:24:42 by welim             #+#    #+#             */
/*   Updated: 2022/08/19 12:24:59 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static	void	shift_down(int *stack, int size)
{
	int	i;
	int	*temp;

	i = 1;
	temp = ft_calloc(size, sizeof(int));
	temp[0] = stack[size - 1];
	while (i < size)
	{
		temp[i] = stack[i - 1];
		i++;
	}
	i = 0;
	while (i < size)
	{
		stack[i] = temp[i];
		i++;
	}
	free(temp);
	return ;
}

//first last to the top one 123 -> 312
void	r_r(t_stack *stack, int type)
{
	if (type == 1 || type == 3)
		shift_down(stack->a, stack->size_a);
	if (type == 2 || type == 3)
		shift_down(stack->b, stack->size_b);
	return ;
}
