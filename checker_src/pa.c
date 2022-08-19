/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:23:13 by welim             #+#    #+#             */
/*   Updated: 2022/08/19 12:24:49 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static	void	replace_num_a(t_stack *stack, int *temp, int type)
{
	int	i;

	i = 0;
	if (type == 1)
	{
		while (i < stack->size_a)
		{
			temp[i + 1] = stack->a[i];
			i++;
		}
	}
	else
	{
		while (i < stack->size_a)
		{
			stack->a[i] = temp[i];
			i++;
		}
	}
}

void	pa(t_stack *stack)
{
	int	i;
	int	*temp;

	i = 1;
	temp = ft_calloc(stack->size_a + 1, sizeof(int));
	temp[0] = stack->b[0];
	while (i < stack->size_b)
	{
		stack->b[i - 1] = stack->b[i];
		stack->b[i++] = 0;
	}
	stack->size_b -= 1;
	replace_num_a(stack, temp, 1);
	stack->size_a += 1;
	replace_num_a(stack, temp, 2);
	free(temp);
}
