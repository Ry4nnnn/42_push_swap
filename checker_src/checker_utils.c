/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:24:08 by welim             #+#    #+#             */
/*   Updated: 2022/08/24 19:34:45 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"	

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
void	check_dup(t_stack *stack)
{
	int		i;
	int		j;

	i = 0;
	while (stack->size_a > i)
	{
		j = 1;
		while (stack->size_a > j)
		{
			if (stack->a[i] == stack->a[j] && i != j)
			{
				ft_putstr_fd("Error!\n", 1);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

//this function is to check whether array is sorted
//sorted  = 1;
//not sorted = 0;
int	check_sort(t_stack *stack)
{
	int		i;
	int		res;

	i = 1;
	res = 1;
	while (i < stack->size_a)
	{
		if (stack->a[i - 1] > stack->a[i])
		{
			res = 0;
			break ;
		}
		i++;
	}
	if (res == 1)
		return (1);
	else
		return (0);
}
