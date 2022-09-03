/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:26:18 by welim             #+#    #+#             */
/*   Updated: 2022/09/01 21:53:50 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	create_stack2_utils(char **res, int j)
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

static void	create_stack2(t_data *data, char **argv)
{
	int		j;
	char	**res;

	j = 0;
	res = ft_split(argv[1], ' ');
	while (res[j])
		j++;
	data->stack_a = ft_calloc(j, sizeof(int));
	data->stack_b = ft_calloc(j, sizeof(int));
	j = 0;
	while (res[j])
	{
		create_stack2_utils(res, j);
		data->stack_a[j] = ft_atoi(res[j]);
		free (res[j]);
		j++;
	}
	free(res);
	data->len_a = j;
}

static void	create_stack3_utils(char **argv, int i)
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

static void	create_stack3(t_data *data, char **argv)
{
	int		i;

	i = 1;
	data->stack_a = ft_calloc(data->argc - 1, sizeof(int));
	data->stack_b = ft_calloc(data->argc - 1, sizeof(int));
	while (i < data->argc)
	{
		create_stack3_utils(argv, i);
		i++;
	}
	i = 0;
	while (i < data->argc - 1)
	{
		data->stack_a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	data->len_a = i;
}

void	create_stack(t_data *data, char **argv)
{
	if (data->argc == 1)
		exit(0);
	else if (data->argc == 2)
		create_stack2(data, argv);
	else
		create_stack3(data, argv);
	check_duplicate(data);
}
