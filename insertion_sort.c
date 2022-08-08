#include "push_swap.h"

void	chunk_init_a(t_data *data, int size)
{
	// int	size_a;
	int diff;

	// size_a = data->len_a;
	data->min_num = data->stack_a[get_minmax(data, 1)];//index of the min number in the stack
	data->max_num = data->stack_a[get_minmax(data, 2)];//index of the max number in the stack
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

int get_minmax(t_data *data, int type)
{
	int i;
	int res;
	int *array;

	i = 0;
	res = 0;
	array = data->stack_a;
	if (type == 1)
	{
		while (i < data->len_a)
		{
			if (i > 0 && array[i] < array[res])
				res = i;
			i++;
		}
	}
	else
	{
		while (i < data->len_a)
		{
			if (i > 0 && array[i] > array[res])
				res = i;
			i++;
		}
	}
	return (res);
}

int get_threshold(t_data *data)
{
	int size;

	size  = data->chunk_size;
	if (data->threshold == 0)
	{
		data->low_threshold = data->min_num;
		data->up_threshold = data->low_threshold + size;
		if (data->chunk_remainder > 0)
			data->up_threshold = data->chunk_remainder + size + 1;
		data->chunk_remainder -= 1;
	}
	else if (data->threshold < data->total_chunk)
	{
		data->low_threshold = data->up_threshold + 1;
		data->up_threshold = data->low_threshold + size;
		if (data->chunk_remainder > 0)
			data->up_threshold = data->chunk_remainder + size + 1;
		data->chunk_remainder -= 1;
	}
	else
		return (0);
	data->threshold = data->threshold + 1;
	return (1);
}

int push_threshold(t_data *data)
{
	int a;
	int b;

	
}

void	insertion_sort(t_data *data, int size)
{
	int	i;
	int	check;
	int	temp;

	i = 0;
	chunk_init_a(data, size);
	// printf ("%d\n", data->chunk_size);
	check = get_threshold(data);
	// printf ("%d\n", check);
	while (i < size)
	{
		temp = push_threshold(data);
		while (temp == 0 && check > 0)
		{
			check = get_threshold(data);
			temp = push_threshold(data);
		}
		i++;
	}
	chunk_init_b(data, size);
	push_to_a(data);
}