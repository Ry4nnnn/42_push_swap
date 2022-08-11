#include "push_swap.h"

static	void	shift_down(int *stack, int size)
{
	int	i;
	int	*temp;

	i = 1;
	temp = ft_calloc(size, sizeof(int));
	temp[0] = stack[size - 1];
	while (i < size)
	{
		temp[i] = stack[i - 1];
		i++;
	}
	i = 0;
	while (i < size)
	{
		stack[i] = temp[i];
		i++;
	}
	free(temp);
	return ;
}

//first last to the top one 123 -> 312
void	rev_rotate(t_data *data, int type)
{
	if (type == 1 || type == 3)
		shift_down(data->stack_a, data->len_a);
	if (type == 2 || type == 3)
		shift_down(data->stack_b, data->len_b);
	if (type == 1)
		ft_putstr_fd("rra\n", 1);
	if (type == 2)
		ft_putstr_fd("rrb\n", 1);
	if (type == 3)
		ft_putstr_fd("rrr\n", 1);
	return ;
}
