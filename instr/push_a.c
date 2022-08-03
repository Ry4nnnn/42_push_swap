#include "push_swap.h"

static	void update_b(t_data *data)
{
	int i;
	int *temp;

	i = 0;
	temp = malloc(sizeof(int) * data->len_b - 1);
	while (i < data->len_b)
	{
		temp[i] = data->stack_b[i + 1];
		i++;
	}
	i = 0;
	while (temp[i])
	{
		data->stack_b[i] = temp[i];
		i++;
	}
	data->stack_b[i] = 0;
	free(temp);
}

static	void update_a(t_data *data)
{
	int *temp;
	int i;

	i = 0;
	temp = malloc(sizeof(int) * data->len_a + 1);
	temp[i] = data->stack_b[0];
	// printf ("temp:%d\n", temp[0]);
	while (i < data->len_a)
	{
		temp[i + 1] = data->stack_a[i];
		i++;
	}
	i = 0;
	while (temp[i])
	{
		data->stack_a[i] = temp[i];
		i++;
	}
	free(temp);
}

void	push_a(t_data *data)
{
	ft_putstr_fd("pa\n", 1);
	if (data->len_a != 0)
	{
		update_a(data);
		update_b(data);
	}
	else
	{
		data->stack_a[0] = data->stack_b[0];
		update_a(data);
	}
	data->len_b -= 1;
	data->len_a += 1;
}
