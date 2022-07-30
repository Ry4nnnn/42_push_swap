#include "push_swap.h"

void	swap_top(t_data *data, int type)
{
	int	temp;

	if (type == 1 || type == 3)
	{
		if (data->len_a <= 1)
			return ;
		temp = data->stack_a[0];
		data->stack_a[0] = data->stack_a[1];
		data->stack_a[1] = temp;
	}
	if (type == 2 || type == 3)
	{
		if (data->len_b <= 1)
			return ;
		temp = data->stack_b[0];
		data->stack_b[0] = data->stack_b[1];
		data->stack_b[1] = temp;
	}
	if (type == 1)
		ft_putstr_fd("sa\n", 1);
	if (type == 2)
		ft_putstr_fd("sb\n", 1);
	if (type == 3)
		ft_putstr_fd("ss\n", 1);
	return ;
}
