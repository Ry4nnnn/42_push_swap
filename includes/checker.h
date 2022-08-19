/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:27:44 by welim             #+#    #+#             */
/*   Updated: 2022/08/19 12:27:10 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include <limits.h>
# include <stdio.h>
# include "push_swap.h"

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
	int		argc;
	char	**argv;
}	t_stack;

//checker.c
void	input_stack(t_stack *stack);
void	input_instr(char *input, t_stack *stack);

//checker_utils.c
int		ft_isnum(char *s);
void	check_dup(t_stack *stack);
int		ft_strcmp(char *s1, char *s2);
int		check_sort(t_stack *stack);
t_stack	*input_struct(t_stack *stack, int argc, char **argv);

//instr
void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	r_r(t_stack *stack, int type);
void	r(t_stack *stack, int type);
void	swap(t_stack *stack, int type);

#endif