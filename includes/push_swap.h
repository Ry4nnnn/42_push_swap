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

void	check_error(int argc, char **argv);
int		check_sorted(t_data *data);
// void	init_array(t_data *data, int argc, char **argv);

//utils
int	ft_isnum(char *s);

#endif