/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 22:19:19 by welim             #+#    #+#             */
/*   Updated: 2022/08/31 23:50:45 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*input_struct(t_stack *stack, int argc)
{
	stack->a = 0;
	stack->b = 0;
	stack->size_a = 0;
	stack->size_b = 0;
	stack->argc = argc;
	return (stack);
}

static void	input_instr2(char *input, t_stack *stack)
{
	if (ft_strcmp("pb\n", input))
		pb(stack);
	else if (ft_strcmp("pa\n", input))
		pa(stack);
	else if (ft_strcmp("sa\n", input))
		swap(stack, 1);
	else if (ft_strcmp("sb\n", input))
		swap(stack, 2);
	else if (ft_strcmp("ss\n", input))
		swap(stack, 3);
	else
	{
		ft_putstr_fd("Error!\n", 1);
		exit(0);
	}
}

void	input_instr(char *input, t_stack *stack)
{
	if (ft_strcmp("rra\n", input))
		r_r(stack, 1);
	else if (ft_strcmp("rrb\n", input))
		r_r(stack, 2);
	else if (ft_strcmp("rrr\n", input))
		r_r(stack, 3);
	else if (ft_strcmp("ra\n", input))
		r(stack, 1);
	else if (ft_strcmp("rb\n", input))
		r(stack, 2);
	else if (ft_strcmp("rr\n", input))
		r(stack, 3);
	else
		input_instr2(input, stack);
}

int	main(int argc, char **argv)
{
	t_stack		*stack;
	char		*input;

	stack = ft_calloc(1, sizeof(t_stack));
	input_struct(stack, argc);
	input_stack(stack, argv);
	while (1)
	{
		input = get_next_line(0);
		if (input == NULL)
		{
			if (check_sort(stack) && stack->size_b == 0)
				ft_putstr_fd("OK\n", 1);
			else
				ft_putstr_fd("KO\n", 1);
			free (input);
			break ;
		}
		input_instr(input, stack);
		free(input);
	}
	free (stack->a);
	free (stack->b);
	free (stack);
	return (0);
}
