#include "push_swap.h"

int find_small(t_data *data)
{
	int i;
	int mask;

	i = 0;
	mask = data->stack_a[0];
	while (i < data->len_a)
	{
		while (mask > data->stack_a[i])
		{
			mask = data->stack_a[i];
			i++;
		}
		i++;
	}
	return (mask);
}

void	find_chunks(t_data *data)
{
	int chunk_sz;
	int remainder;
	int i;

	i = 0;
	chunk_sz = data->len_a / 4;
	remainder = data->len_a % 4;
	while (chunk_sz--)
	{
		if (data->stack_a[i] == find_small(data))
		{
			push_b(data);
			i++;
		}
	}
}