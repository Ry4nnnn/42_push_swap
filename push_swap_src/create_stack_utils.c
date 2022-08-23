/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:16:50 by welim             #+#    #+#             */
/*   Updated: 2022/08/23 20:46:44 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_isnum(char *s)
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
void	check_duplicate(t_data *data)
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
