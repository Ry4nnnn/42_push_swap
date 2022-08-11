#include "push_swap.h"

int	get_index_a(t_data *data, int index)
{
	int i;
	int temp;
	int size;

	i = 0;
	temp = -1;
	size = data->len_a;
	while (i < size)
	{
		if (data->stack_a[i] > data->stack_b[index])
		{
			if (temp == -1)
				temp = i;
			else if (data->stack_a[temp] > data->stack_a[i])
				temp = i;
		}
		i++;
	}
	if (temp == -1)
		return (-1);
	else
		return (temp);
}

int	get_moves(t_data *data, int index, int type)
{
	// int	i;
	// int	size;
	int	moves_a;
	int	moves_b;

	// i = 0;
	// size = data->len_a;
	if (index <= data->len_b / 2)
		moves_b = index;
	else
		moves_b = data->len_b - index;
	if (get_index_a(data, index) < 0)
		moves_a = find_asc(data);
	else if (get_index_a(data, index) <= data->len_a / 2)
		moves_a = get_index_a(data, index);
	else
		moves_a = data->len_a - get_index_a(data, index);
	if (type == 1)
		return (moves_b);
	else
		return (moves_a);
}


//check_rotate
int	count_moves(int i, int j)
{
	if (i < j)
		return (i);
	else if (j < i)
		return (j);
	else
		return (i);
}

int	find_asc(t_data *data)
{
	int	min;

	min = get_minmax(data->stack_a, data->len_a, 1);
	if (min <= data->len_a / 2)
		return (min);
	else
		return (data->len_a - min);
}

void	sort_asc(t_data *data)
{
	int	min;

	min = get_minmax(data->stack_a, data->len_a, 1);
	if (min < data->len_a / 2)
		rotate_multi(data, min, 1);
	else if (min >= data->len_a / 2)
		rotate_multi(data, data->len_a - min, 2);
}

/* 1 = rotate_up, 2 = rotate_down */
void	rotate_multi(t_data *data, int amount, int type)
{
	int	i;

	i = 0;
	if (type == 1)
	{
		while (i < amount)
		{
			rotate(data, 1);
			i++;
		}
	}
	else
	{
		while (i < amount)
		{
			rev_rotate(data, 1);
			i++;
		}
	}
}

/* 1 = rotate_up, 2 = rotate_down */
void	rotate_multi_b(t_data *data, int amount, int type)
{
	int	i;

	i = 0;
	if (type == 1)
	{
		while (i < amount)
		{
			rotate(data, 2);
			i++;
		}
	}
	else
	{
		while (i < amount)
		{
			rev_rotate(data, 2);
			i++;
		}
	}
}

/* 1 = rotate_up, 2 = rotate_down */
void	rotate_both(t_data *data, int amount, int type)
{
	int	i;

	i = 0;
	if (type == 1)
	{
		while (i < amount)
		{
			rotate(data, 3);
			i++;
		}
	}
	else
	{
		while (i < amount)
		{
			rev_rotate(data, 3);
			i++;
		}
	}
}

void	addmoves(t_data *data, int *a, int *b, int type)
{
	if (type == 1)
	{
		rotate_both(data, data->rt_both, 1);
		*a = *a - data->rt_both;
		*b = *b - data->rt_both;
	}
	else
	{
		rotate_both(data, data->rt_both, 2);
		*a = *a + data->rt_both;
		*b = *b + data->rt_both;
	}
}