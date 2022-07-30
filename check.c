#include "push_swap.h"

void	create_stack(t_data *data, char **argv)
{
	int i;
	// int	j;
	char **res;

	i = 0;
	if (data->argc < 2)
	{
		ft_putstr_fd("Usage: [Programe Name] [Numbers]\n", 1);
		exit(0);
	}
	res = ft_split(argv[1], ' ');//bug
	printf("check:%s\n", res[1]);
	while (res[i])
	{
		// printf ("%s\n", res[0]);
		if (!(ft_isnum(res[i])))
		{
			ft_putstr_fd("Error!\n", 1);
			exit(0);
		}
		data->stack_a[i] = ft_atoi(res[i]);
		printf ("%d\n", data->stack_a[i]);
		i++;
	}
	data->len_a = i;
	free (res);
	printf ("sz: %d\n", data->len_a);
}

// void	check_dup(t_data *data)
// {
// 	int i;

// 	i = 0;
// 	while (data->len_a)
// }
	// while (argv[i])
	// {
	// 	if (!(ft_isnum(argv[i])))
	// 	{
	// 		ft_putstr_fd("Error!\n", 1);
	// 		exit(0);
	// 	}
	// 	j = 0;
	// 	while (argv[++j])
	// 	{
	// 		if ((ft_atoi(argv[j]) == ft_atoi(argv[i]) && j != i)
	// 			|| (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN))
	// 		{
	// 			ft_putstr_fd("No Duplicate numbers allowed\n", 1);
	// 			exit (0);
	// 		}
	// 	}
	// 	i++;
	// }

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