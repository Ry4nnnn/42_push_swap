/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 22:05:13 by welim             #+#    #+#             */
/*   Updated: 2022/09/01 21:56:48 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_data	*init_struct(t_data *data, int argc)
{
	data->argc = argc;
	data->len_a = 0;
	data->len_b = 0;
	data->threshold = 0;
	return (data);
}

int	main(int argc, char **argv)
{
	t_data		*data;

	data = ft_calloc(1, sizeof(t_data));
	init_struct(data, argc);
	create_stack(data, argv);
	optimize_numbers(data);
	if (check_sorted(data))
	{
		free(data->stack_a);
		free(data->stack_b);
		free(data);
		system("leaks push_swap");
		return (0);
	}
	sort_stack(data);
	free(data->stack_a);
	free(data->stack_b);
	free(data);
	system("leaks push_swap");
	return (0);
}
