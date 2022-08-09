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
	int min_num;
	int max_num;
	int total_chunk;
	int chunk_size;
	int chunk_remainder;
	int threshold;
	int up_threshold;
	int low_threshold;
	int best_idx;
	int total_move;
	int rt_both;
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

void	insertion_sort(t_data *data, int size);
void	chunk_init_a(t_data *data, int size);
int get_minmax(int *stack, int size, int type);

//push_threshold
int push_threshold(t_data *data);

//smart_rotate
int	check_rotate(t_data *data, int index);
void	check_smartrotate(t_data *data);
void	rotate_remainder(t_data *data, int a, int b, int type);
void	smartrotate(t_data *data);
void	push_to_a(t_data *data);


//smart_rotate_utils
int	get_index_a(t_data *data, int index);
int	get_moves(t_data *data, int index, int type);
int	count_moves(int i, int j);
int	find_asc(t_data *data);
void	sort_asc(t_data *data);
void	rotate_both(t_data *data, int amount, int type);
void	rotate_multi(t_data *data, int amount, int type);
void	rotate_multi_b(t_data *data, int amount, int type);
void	addmoves(t_data *data, int *a, int *b, int type);


#endif
