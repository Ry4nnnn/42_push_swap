#include "push_swap.h"

static t_data *init_struct(t_data *data, int argc)
{
	data->argc = argc;
	data->len_a = 0;
	data->len_b = 0;
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
	else
	{
		find_chunks(data);
		// insertion_sort();
	}
}

int main(int argc, char **argv)
{
	t_data *data;

	(void)argc;
	data = malloc(sizeof(t_data));
	init_struct(data, argc);
	create_stack(data, argv);
	// init_stack(data, argv);
	if (check_sorted(data))
	{
		free(data->stack_a);
		free(data->stack_b);
		free(data);
		ft_putstr_fd("sorted\n", 1);
		exit(1);
	}
	sort_stack(data);
	return (0);
}
