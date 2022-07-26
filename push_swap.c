#include "../includes/push_swap.h"

static t_data *init_struct(t_data *data, int argc)
{
	data->stack_a = 0;
	data->stack_b = 0;
	data->size_a = argc - 1;//minus the program name
	data->size_b = 0;
	return (data);
}

void init_stack(t_data *data, int argc, char **argv)
{
	int x;

	x = 0;
	data->stack_a = malloc(sizeof(int) * (argc - 1));
	while (x < argc - 1)
	{
		data->stack_a[x] = ft_atoi(argv[x + 1]);
		x++;
	}
}

void	sort_stack(t_data *data)
{
	if (data->size_a == 2)
	{
		if (!check_sorted(data))
			swap_top(data, 1);
	}
	// if (data->size_a == 3)
	// {
	// 	if (!check_sorted(data))
	// 		swap_3(data);
	// }
	// if (data->size_a == 5)
	// {
	// 	if (!check_sorted(data))
	// 		swap_5(data);
	// }
	else
		return ;
}

int main(int argc, char **argv)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	check_error(argc, argv);
	init_struct(data, argc);
	init_stack(data, argc, argv);
	// printf ("%d\n", data->stack_a[2]);
	if (check_sorted(data))
	{
		free(data->stack_a);
		// free(data->stack_b);
		free(data);
		ft_putstr_fd("sorted\n", 1);
		exit(1);
	}
	// ft_putstr_fd("not sorted\n", 1);
	sort_stack(data);
	// insertion_sort(data);
	return (0);
}
