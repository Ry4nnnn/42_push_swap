#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_data
{
	int *stack_a;
	int *stack_b;
	int len_a;
	int len_b;
	int argc;
}	t_data;

//check.c
void	create_stack(t_data *data, char **argv);
int		check_sorted(t_data *data);
void	check_dup(t_data *data);

//utils
int	ft_isnum(char *s);

//moves
void	swap_top(t_data *data, int type);
void	rotate(t_data *data, int type);
void	rev_rotate(t_data *data, int type);
void	push_a(t_data *data);
void	push_b(t_data *data);

//sort_small_num
void	sort_3(t_data *data);
void	sort_5(t_data *data);

void	print_stack(t_data *data);
int	find_chunks(t_data *data);

#endif