#include "./includes/push_swap.h"

static	void	shift_down(int *data, int size)
{
	int	i;
	int	*temp;

	i = 1;
	temp = ft_calloc(size, sizeof(int));
	temp[0] = data[size - 1];
	while (i < size)
	{
		temp[i] = data[i - 1];
		i++;
	}
	i = 0;
	while (i < size)
	{
		data[i] = temp[i];
		i++;
	}
	free(temp);
	return ;
}

//first last to the top one 123 -> 312
void	bot2top(t_data *data, int type)
{
	if (type == 1)
	{
		shift_down(data->stack_a, data->size_a);
		ft_putstr_fd("rra\n", 1);
	}
	if (type == 2)
	{
		shift_down(data->stack_b, data->size_b);
		ft_putstr_fd("rrb\n", 1);
	}
	if (type == 3)
	{
		shift_down(data->stack_a, data->size_a);
		shift_down(data->stack_b, data->size_b);
		ft_putstr_fd("rrr\n", 1);
	}
	return ;
}
