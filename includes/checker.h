/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:27:44 by welim             #+#    #+#             */
/*   Updated: 2022/08/18 21:17:15 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdio.h>
# include "push_swap.h"

typedef struct s_stack
{
	int *a;
	int *b;
	int size_a;
	int size_b;
	int argc;
	char **argv;
}	t_stack;

// void	test(char *str);
void	input_stack(t_stack *stack);
void	input_instr(char *input, t_stack *stack);

void	pa(t_stack *stack);
void	pb(t_stack *stack);
void	r_r(t_stack *stack, int type);
void	r(t_stack *stack, int type);
void	swap(t_stack *stack, int type);

#endif