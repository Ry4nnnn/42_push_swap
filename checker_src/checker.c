/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 22:19:19 by welim             #+#    #+#             */
/*   Updated: 2022/08/18 22:23:27 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static t_stack	*input_struct(t_stack *stack, int argc, char **argv)
{
	stack->a = 0;
	stack->b = 0;
	stack->size_a = 0;
	stack->size_b = 0;
	stack->argv = argv;
	stack->argc = argc;
	return (stack);
}

static void	input_stack2(t_stack *stack)
{
	int i;
	char **res;

	i = 0;
	res = ft_split(stack->argv[1], ' ');
	while (res[i])
		i++;
	stack->a = ft_calloc(i, sizeof(int));
	stack->b = ft_calloc(i, sizeof(int));
	i = 0;
	while (res[i])
	{
		if (!(ft_isnum(res[i])))
		{
			ft_putstr_fd("Error!\n", 1);
			exit(0);
		}
		stack->a[i] = ft_atoi(res[i]);
		free(res[i]);
		i++;
	}
	free (res);
	stack->size_a = i;
}

void	input_stack(t_stack *stack)
{
	int		i;

	i = 0;
	if (stack->argc == 1)
		exit (0);
	else if (stack->argc == 2)
		input_stack2(stack);
	else
	{
		stack->a = ft_calloc(stack->argc - 1, sizeof(int));
		stack->b = ft_calloc(stack->argc - 1, sizeof(int));
		while (i < stack->argc - 1)
		{
			stack->a[i] = ft_atoi(stack->argv[i + 1]);
			i++;
		}
		stack->size_a = i;
	}
	check_dup(stack);
}

void	input_instr(char *input, t_stack *stack)
{
	if (ft_strcmp("pb\n", input))
		pb(stack);
	else if (ft_strcmp("pa\n", input))
		pa(stack);
	else if (ft_strcmp("rra\n", input))
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

int main(int argc, char **argv)
{
	t_stack *stack;
	char *input;

	stack = ft_calloc(1, sizeof(t_stack));
	input_struct(stack, argc, argv);
	input_stack(stack);
	while (1)
	{
		input = get_next_line(0);
		if (input == NULL)
		{
			if (check_sorted(stack))
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
	// system("leaks checker");
	return (0);
}