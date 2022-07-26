#include "../includes/push_swap.h"

static void	push_a(t_data *data)
{
	int i;
	int *temp;

	i = 1;
	temp = malloc(sizeof(int) * data->size_a);
	temp[0] = data->stack_b[0];
	while (i < data->size_a)
	{
		temp[i] = data->stack_a[i - 1];
		i++;
	}
	i = 0;
	while (i < data->size_a)
	{
		data->stack_a[i] = temp[i];
		i++;
	}
	free (temp);
	data->size_a += 1;
	data->size_b -= 1;
}

static void	push_b(t_data *data)
{
	int i;
	int *temp;

	i = 1;
	temp = malloc(sizeof(int) * data->size_a);
	temp[0] = data->stack_a[0];
	while (i < data->size_b)
	{
		temp[i] = data->stack_b[i - 1];
		i++;
	}
	i = 0;
	while (i < data->size_b)
	{
		data->stack_b[i] = temp[i];
		i++;
	}
	free (temp);
	data->size_a -= 1;
	data->size_b += 1;
}


void	push_top(t_data *data, int type)
{
	if (type == 1)
	{
		push_a(data);
		ft_putstr_fd("pa\n", 1);
	}
	if (type == 2)
	{
		push_b(data);
		ft_putstr_fd("pb\n", 1);
	}
}
