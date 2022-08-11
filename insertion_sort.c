#include "push_swap.h"


//type 1 == find idx of smallest num
//type 2 == find idx of largest num
int get_minmax(int *stack, int size, int type)
{
	int i;
	int res;

	i = 0;
	res = 0;
	if (type == 1)
	{
		while (i < size)
		{
			if (i > 0 && stack[i] < stack[res])
				res = i;
			i++;
		}
	}
	else
	{
		while (i < size)
		{
			if (i > 0 && stack[i] > stack[res])
				res = i;
			i++;
		}
	}
	return (res);
}

void	chunk_init_a(t_data *data, int size)
{
	int	len_a;
	int diff;

	len_a = data->len_a;
	data->min_num = data->stack_a[get_minmax(data->stack_a, len_a, 1)];//index of the min number in the stack
	data->max_num = data->stack_a[get_minmax(data->stack_a, len_a, 2)];//index of the max number in the stack
	// int i = 0;
	// while (i < data->len_a)
	// {
	// 	printf (" %d |", data->stack_a[i]);
	// 	i++;
	// }
	data->total_chunk = size;
	diff = data->max_num - data->min_num + 1;
	// printf ("max:%d	|	min:%d\n", data->max_num, data->min_num);
	data->chunk_size = diff / size;
	data->chunk_remainder = (diff % size) - 1;
	if (data->chunk_size == 0)
	{
		data->total_chunk = 1;
		data->chunk_size = data->chunk_remainder - 1;
		data->chunk_remainder = 0;
	}
}

void	chunk_init_b(t_data *data, int size)
{
	int len_b;
	int diff;

	len_b = data->len_b;
	data->min_num = data->stack_b[get_minmax(data->stack_b, len_b, 1)];//index of the min number in the stack
	data->max_num = data->stack_b[get_minmax(data->stack_b, len_b, 2)];//index of the max number in the stack
	data->total_chunk = size;
	diff = data->max_num - data->min_num + 1;
	data->chunk_size = diff / size;
	data->chunk_remainder = (diff % size) - 1;
	if (data->chunk_size == 0)
	{
		data->total_chunk = 1;
		data->chunk_size = data->chunk_remainder - 1;
		data->chunk_remainder = 0;
	}

}

int get_threshold(t_data *data)
{
	int size;

	size  = data->chunk_size;
	// printf ("				gt_size: %d\n", size);
	if (data->threshold == 0)
	{
		data->low_threshold = data->min_num;
		data->up_threshold = data->low_threshold + size;
		if (data->chunk_remainder > 0)
			data->up_threshold = data->low_threshold + size + 1;
		data->chunk_remainder = data->chunk_remainder - 1;
	}
	else if (data->threshold < data->total_chunk)
	{
		data->low_threshold = data->up_threshold + 1;
		data->up_threshold = data->low_threshold + size;
		if (data->chunk_remainder > 0)
			data->up_threshold = data->low_threshold + size + 1;
		data->chunk_remainder = data->chunk_remainder - 1;
	}
	else
		return (0);
	data->threshold = data->threshold + 1;
	return (1);
}

void	insertion_sort(t_data *data, int size)
{
	int	i;
	int len_a;
	int	check;
	int	temp;

	i = 0;
	len_a = data->len_a;
	chunk_init_a(data, size);
	check = get_threshold(data);
	// printf ("len_a: %d\n", len_a);
	while (i < len_a)
	{
		temp = push_threshold(data);
		while (temp == 0 && check > 0)
		{
			// printf ("temp: %d | check: %d\n", temp, check);
			check = get_threshold(data);
			temp = push_threshold(data);
		}
		i++;
	}
	chunk_init_b(data, size);
	push_to_a(data);
}