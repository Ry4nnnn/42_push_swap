/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 22:36:32 by welim             #+#    #+#             */
/*   Updated: 2022/08/31 22:37:13 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	input_stack2_utils(char **res, int j)
{
	if (!(ft_isnum(res[j])))
	{
		ft_putstr_fd("Error!\n", 2);
		exit(0);
	}
	if (res[j][0] == '-')
	{
		if (!(res[j][1] >= '0' && res[j][1] <= '9'))
		{
			ft_putstr_fd("Error!\n", 2);
			exit(0);
		}
	}
	if (ft_atoi(res[j]) >= INT_MAX || ft_atoi(res[j]) <= INT_MIN)
	{
		ft_putstr_fd("Error!\n", 2);
		exit (0);
	}
}

static void	input_stack2(t_stack *stack, char **argv)
{
	int		j;
	char	**res;

	j = 0;
	res = ft_split(argv[1], ' ');
	while (res[j])
		j++;
	stack->a = ft_calloc(j, sizeof(int));
	stack->b = ft_calloc(j, sizeof(int));
	j = 0;
	while (res[j])
	{
		input_stack2_utils(res, j);
		stack->a[j] = ft_atoi(res[j]);
		free (res[j]);
		j++;
	}
	free(res);
	stack->size_a = j;
}

static void	input_stack3_utils(char **argv, int i)
{
	if (!(ft_isnum(argv[i])))
	{
		ft_putstr_fd("Error!\n", 2);
		exit(0);
	}
	if (argv[i][0] == '-')
	{
		if (!(argv[i][1] >= '0' && argv[i][1] <= '9'))
		{
			ft_putstr_fd("Error!\n", 2);
			exit (0);
		}
	}
	if (ft_atoi(argv[i]) >= INT_MAX || ft_atoi(argv[i]) <= INT_MIN)
	{
		ft_putstr_fd("Error!\n", 2);
		exit (0);
	}
}

static void	input_stack3(t_stack *stack, char **argv)
{
	int		i;

	i = 1;
	stack->a = ft_calloc(stack->argc - 1, sizeof(int));
	stack->b = ft_calloc(stack->argc - 1, sizeof(int));
	while (i < stack->argc)
	{
		input_stack3_utils(argv, i);
		i++;
	}
	i = 0;
	while (i < stack->argc - 1)
	{
		stack->a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	stack->size_a = i;
}

void	input_stack(t_stack *stack, char **argv)
{
	if (stack->argc == 1)
		exit(0);
	else if (stack->argc == 2)
		input_stack2(stack, argv);
	else
		input_stack3(stack, argv);
	check_dup(stack);
}
