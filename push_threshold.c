#include "push_swap.h"

int	get_threshold_min(t_data *data, int type)
{
	int	i;

	// printf ("lt:%d\n", data->low_threshold);
	// printf ("ut:%d\n", data->up_threshold);
	if (type == 1)
	{
		i = 0;
		while (i < data->len_a)
		{
			if (data->stack_a[i] >= data->low_threshold)
				if (data->stack_a[i] <= data->up_threshold)
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

void rotate_over(t_data *data, int hold_a, int hold_b)
{
	if (hold_a == hold_b)
	{
		if (hold_a <= data->len_a / 2)
			rotate_multi(data, hold_a, 1);
		else
			rotate_multi(data, data->len_a - hold_a, 2);
	}
	else
	{
		if (hold_a <= data->len_a - hold_b)
			rotate_multi(data, hold_a, 1);
		else
			rotate_multi(data, data->len_a - hold_b, 2);
	}
}

int push_threshold(t_data *data)
{
	int hold_a;
	int hold_b;

	hold_a = get_threshold_min(data, 1);
	hold_b = get_threshold_min(data, 2);
	// printf ("hold_a:%d | hold_b:%d\n", hold_a, hold_b);
	if (hold_a == -1)
		return (0);
	else
	{
		rotate_over(data, hold_a, hold_b);
		push_b(data);
		return (1);
	}
}
