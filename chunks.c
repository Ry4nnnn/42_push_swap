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
	int i;

	i = 0;
	while (i < data->len_a)
	{
		
	}
}