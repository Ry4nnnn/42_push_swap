#include "push_swap.h"

void	create_stack(t_data *data, char **argv)
{
	int i;
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
		data->stack_a = ft_calloc(i, sizeof(int));
		data->stack_b = ft_calloc(i, sizeof(int));
		i = 0;
		while (res[i])
		{
			if (!(ft_isnum(res[i])))
			{
				ft_putstr_fd("Error!\n", 1);
				exit(0);
			}
			data->stack_a[i] = ft_atoi(res[i]);
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
			i++;
		}
	}
	data->len_a = i;
	free (res);
	check_dup(data);
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
				ft_putstr_fd("no duplicate numbers allowed\n", 1);
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
