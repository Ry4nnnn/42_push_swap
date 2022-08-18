/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:24:24 by welim             #+#    #+#             */
/*   Updated: 2022/08/18 20:50:17 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static	void	replace_num_b(t_stack *stack, int *temp, int type)
{
	int	i;

	i = 0;
	if (type == 1)
	{
		while (i < stack->size_b)
		{
			temp[i + 1] = stack->b[i];
			i++;
		}
	}
	else
	{
		while (i < stack->size_b)
		{
			stack->b[i] = temp[i];
			i++;
		}
	}
}

void	pb(t_stack *stack)
{
	int	i;
	int	*temp;

	i = 1;
	temp = ft_calloc(stack->size_b + 1, sizeof(int));
	temp[0] = stack->a[0];
	while (i < stack->size_a)
	{
		stack->a[i - 1] = stack->a[i];
		stack->a[i++] = 0;
	}
	stack->size_a -= 1;
	replace_num_b(stack, temp, 1);
	stack->size_b += 1;
	replace_num_b(stack, temp, 2);
	free(temp);
	// ft_putstr_fd("pb\n", 1);
}
