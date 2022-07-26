#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_data
{
	int *stack_a;
	int *stack_b;
	int size_a;
	int size_b;
}	t_data;

//check.c
void	check_error(int argc, char **argv);
int		check_sorted(t_data *data);

//utils
int	ft_isnum(char *s);

//moves
void	swap_top(t_data *data, int type);
void	top2bot(t_data *data, int type);
void	bot2top(t_data *data, int type);
void	push_top(t_data *data, int type);

#endif