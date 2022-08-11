#include "push_swap.h"

static t_data *init_struct(t_data *data, int argc)
{
	data->argc = argc;
	data->len_a = 0;
	data->len_b = 0;
	data->threshold = 0;
	// data->stack_a = ft_calloc(data->len_a, sizeof(int));
	// data->stack_b = ft_calloc(data->len_a, sizeof(int));
	return (data);
}

void	sort_stack(t_data *data)
{
	if (data->len_a == 2)
	{
		if (!check_sorted(data))
			swap_top(data, 1);
	}
	else if (data->len_a == 3)
	{
		if (!check_sorted(data))
			sort_3(data);
	}
	else if (data->len_a == 5)
	{
		if (!check_sorted(data))
			sort_5(data);
	}
	else if (data->len_a <= 250)
		insertion_sort(data, 2);
	else
		insertion_sort(data, 4);

}
//
static	void	swap_num(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static	void	selection_sort(int *stack, int size)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < size)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (stack[j] < stack[min])
				min = j;
			j++;
		}
		swap_num(&stack[min], &stack[i]);
		i++;
	}
}

static	int	get_index(t_data *data, int index)
{
	int	i;
	int	*temp;

	i = 0;
	temp = ft_calloc(data->len_a, sizeof(int));
	while (i < data->len_a)
	{
		temp[i] = data->stack_a[i];
		i++;
	}
	selection_sort(temp, data->len_a);
	i = 0;
	while (i < data->len_a)
	{
		if (temp[i] == data->stack_a[index])
		{
			free(temp);
			return (i + 1);
		}
		i++;
	}
	free(temp);
	return (-1);
}

void	optimize_numbers(t_data *data)
{
	int	i;
	int	*temp;

	i = 0;
	temp = ft_calloc(data->len_a, sizeof(int));
	while (i < data->len_a)
	{
		temp[i] = get_index(data, i);
		i++;
	}
	i = 0;
	while (i < data->len_a)
	{
		data->stack_a[i] = temp[i];
		i++;
	}
	free(temp);
}

int main(int argc, char **argv)
{
	t_data *data;

	data = ft_calloc(1, sizeof(t_data));
	init_struct(data, argc);
	create_stack(data, argv);
	// printf ("data->stack_a[3]:%d\n", data->stack_a[3]);
	optimize_numbers(data);
	// printf ("data->stack_a[3]:%d\n", data->stack_a[3]);
	if (check_sorted(data))
	{
		free(data->stack_a);
		free(data->stack_b);
		free(data);
		return (0);
	}
	sort_stack(data);
	free(data->stack_a);
	free(data->stack_b);
	free(data);
	return (0);
}
