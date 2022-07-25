#include "../includes/push_swap.h"

//this function is to check whether array is sorted
int	check_sorted(t_data *data)
{
	int	i;
	int	res;
	int	size;

	i = 0;
	res = 1;
	size = data->size_a;
	while (i < size - 1)
	{
		printf ("checking: %d < %d\n", data->stack_a[i], data->stack_a[i + 1]);
		if (data->stack_a[i] > data->stack_a[i + 1])
		{
			res = 0;
			break ;
		}
		i++;
	}
	if (res == 1)
	{
		printf("sorted\n");
		return (1);
	}
	else
	{
		printf("not sorted\n");
		return (0);
	}
}

static t_data *init_struct(t_data *data, int argc)
{
	data->stack_a = 0;
	data->stack_b = 0;
	data->size_a = argc - 1;
	data->size_b = 0;
	return (data);
}

void init_data(t_data *data, int argc, char **argv)
{
	int x;

	x = 0;
	data->stack_a = malloc(sizeof(int) * (argc - 1));
	while (x < argc - 1)
	{
		data->stack_a[x] = ft_atoi(argv[x + 1]);
		x++;
	}
	// printf ("%d\n", stack_a[2]);
}

int main(int argc, char **argv)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	check_error(argc, argv);
	init_struct(data, argc);
	init_data(data, argc, argv);
	printf ("%d\n", data->stack_a[2]);
	if (check_sorted(data))
	{
		free(data->stack_a);
		// free(data->stack_b);
		free(data);
	}
	return (0);
}
