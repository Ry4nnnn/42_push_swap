#include "push_swap.h"

int	get_threshold_min(t_data *data, int type)
{
	int	i;

	if (type == 1)
	{
		i = 0;
		while (i < data->len_a)
		{
			if (data->stack_a[i] >= data->low_threshold)
				if (data->stack_a[i] <= data-> up_threshold)
					return (i);
			i++;
		}
	}
	else
	{
		i = data->len_a - 1;
		while (i > -1)
		{
			if (data->stack_a[i] >= data->low_threshold)
				if (data->stack_a[i] <= data->up_threshold)
					return (i);
			i--;
		}
	}
	return (-1);
}

void	rotate_multi(t_data *data, int size, int type)
{
	int i;

	i = 0;
	if  (type == 1)
	{
		while (i < size)
		{
			rotate(data, 1);
			i++;
		}
	}
	else
	{
		while (i < size)
		{
			rev_rotate(data, 1);
			i++;
		}
	}
}	

void rotate_over(t_data *data, int a, int b)
{
	if (a == b)
	{
		if (a <= data->len_a / 2)
			rotate_multi(data, a, 1);
		else
			rotate_multi(data, data->len_a - a, 2);
	}
	else
	{
		if (a <= data->len_a - b)
			rotate_multi(data, a, 1);
		else
			rotate_multi(data, data->len_a - b, 2);
	}
}

int push_threshold(t_data *data)
{
	int a;
	int b;

	a = get_threshold_min(data, 1);
	b = get_threshold_min(data, 2);
	if (a == -1)
		return (0);
	else
	{
		rotate_over(data, a, b);
		push_b(data);
		return (1);
	}
}
