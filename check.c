#include "push_swap.h"

void	create_stack(t_data *data, char **argv)
{
	int i;
	// int	j;
	char **res;

	i = 0;
	res = 0;
	if (data->argc < 2)
	{
		ft_putstr_fd("Usage: [Programe Name] [Numbers]\n", 1);
		exit(0);
	}
	else if (data->argc == 2)
	{
		res = ft_split(argv[1], ' ');//bug
		while (res[i])
			i++;
		// printf ("%d\n", i) ;
		data->stack_a = ft_calloc(i, sizeof(int));
		data->stack_b = ft_calloc(i, sizeof(int));
		// printf("check:%s\n", res[1]);
		i = 0;
		while (res[i])
		{
			// printf ("%s\n", res[0]);
			if (!(ft_isnum(res[i])))
			{
				ft_putstr_fd("Error!\n", 1);
				exit(0);
			}
			data->stack_a[i] = ft_atoi(res[i]);
			// printf ("%d\n", data->stack_a[i]);
			i++;
		}
	}
	else
	{
		data->stack_a = ft_calloc(data->argc - 1, sizeof(int));
		data->stack_b = ft_calloc(data->argc - 1, sizeof(int));
		while (i < data->argc - 1)
		{
			data->stack_a[i] = ft_atoi(argv[i + 1]);
			// printf ("%d\n", data->stack_a[i]);
			i++;
		}
	}
	data->len_a = i;
	free (res);
	check_dup(data);
	// printf ("sz: %d\n", data->len_a);
}

//check for duplicate numbers
void	check_dup(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->stack_a[i])
	{
		j = 0;
		while (data->stack_a[++j])
		{
			if (data->stack_a[i] == data->stack_a[j] && i != j)
			{
				ft_putstr_fd("no duplicate numbers allowed", 1);
				exit(0);
			}
		}
		i++;
	}
}

//this function is to check whether array is sorted
//sorted  = 1;
//not sorted = 0;
int	check_sorted(t_data *data)
{
	int	i;
	int	res;

	i = 1;
	res = 1;
	while (i < data->len_a)
	{
		// printf ("checking: %d < %d\n", data->stack_a[i - 1], data->stack_a[i]);
		if (data->stack_a[i - 1] > data->stack_a[i])
		{
			res = 0;
			break ;
		}
		i++;
	}
	if (res == 1)
		return (1);
	else
		return (0);
}