/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:26:18 by welim             #+#    #+#             */
/*   Updated: 2022/08/19 12:29:25 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isnum(char *s)
{
	int		i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

//check for duplicate numbers
static void	check_dup(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (data->stack_a[i])
	{
		j = 0;
		while (data->stack_a[++j])
		{
			if (data->stack_a[i] == data->stack_a[j] && i != j)
			{
				ft_putstr_fd("Error!\n", 1);
				exit(0);
			}
		}
		i++;
	}
}

static void	create_stack2(t_data *data, char **argv)
{
	int		i;
	char	**res;

	i = 0;
	res = ft_split(argv[1], ' ');
	while (res[i])
		i++;
	data->stack_a = ft_calloc(i, sizeof(int));
	data->stack_b = ft_calloc(i, sizeof(int));
	i = 0;
	while (res[i])
	{
		if (!(ft_isnum(res[i])))
		{
			ft_putstr_fd("Error!\n", 2);
			exit(0);
		}
		data->stack_a[i] = ft_atoi(res[i]);
		free (res[i]);
		i++;
	}
	free(res);
	data->len_a = i;
}

void	create_stack(t_data *data, char **argv)
{
	int		i;

	i = 0;
	if (data->argc == 1)
		exit(0);
	else if (data->argc == 2)
		create_stack2(data, argv);
	else
	{
		data->stack_a = ft_calloc(data->argc - 1, sizeof(int));
		data->stack_b = ft_calloc(data->argc - 1, sizeof(int));
		while (i < data->argc - 1)
		{
			data->stack_a[i] = ft_atoi(argv[i + 1]);
			i++;
		}
		data->len_a = i;
	}
	check_dup(data);
}
