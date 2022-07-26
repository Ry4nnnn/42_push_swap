#include "push_swap.h"

static void	shift_up(int *stack, int size)
{
	int i;
	int *temp;

	i = 1;
	temp = ft_calloc(size, sizeof(int));
	while (i < size)
	{
		temp[i - 1] = stack[i];
		i++;
	}
	temp[i - 1] = stack[0];
	i = 0;
	while (i < size)
	{
		stack[i] = temp[i];
		i++;
	}
	free(temp);
}

//first top to the last one 123 -> 231
void top2bot(t_data *data, int type)
{
	if (type == 1)
	{
		shift_up(data->stack_a, data->size_a);
		ft_putstr_fd("ra\n", 1);
	}
	if (type == 2)
	{
		shift_up(data->stack_b, data->size_b);
		ft_putstr_fd("rb\n", 1);
	}
	if (type == 3)
	{
		shift_up(data->stack_a, data->size_a);
		shift_up(data->stack_b, data->size_b);
		ft_putstr_fd("rr\n", 1);
	}
}
