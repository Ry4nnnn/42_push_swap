#include "push_swap.h"

void	check_error(int argc, char **argv)
{
	int i;
	int	j;

	i = 1;
	if (argc < 2)
	{
		ft_putstr_fd("Usage: [Programe Name] [Numbers]\n", 1);
		exit(0);
	}
	while (argv[i])
	{
		if (!(ft_isnum(argv[i])))
		{
			ft_putstr_fd("Error!\n", 1);
			exit(0);
		}
		j = 0;
		while (argv[++j])
		{
			if ((ft_atoi(argv[j]) == ft_atoi(argv[i]) && j != i)
				|| (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN))
			{
				ft_putstr_fd("No Duplicate numbers allowed\n", 1);
				exit (0);
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
	while (i < data->size_a)
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