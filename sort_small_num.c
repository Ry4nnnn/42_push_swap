#include "push_swap.h"

void	sort_3(t_data *data)
{
	int a;
	int b;
	int c;

	a = data->stack_a[0];
	b = data->stack_a[1];
	c = data->stack_a[2];
	if (a > b && a < c)
		swap_top(data, 1);
	else if (a < b && a > c)
		bot2top(data, 1);
	else if (a > b && a > c && b < c)
		top2bot(data, 1);
	else if (a > b && a > c && b > c)
	{
		swap_top(data, 1);
		bot2top(data, 1);
	}
	else if (a < b && a < c && b > c)
	{
		swap_top(data, 1);
		top2bot(data, 1);
	}
}