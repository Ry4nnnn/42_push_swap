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

void	push_back(t_data *data)
{
	// int i;
	int mask;

	// i = 0;
	mask = data->stack_b[0];
	printf ("%d\n", data->stack_b[0]);
	if (mask < data->stack_a[0])
	{
		push_top(data, 1);
	}
	else if (mask > data->stack_a[data->size_a])
	{
		push_top(data, 1);
		top2bot(data, 1);
	}
}

void	sort_5(t_data *data)
{
	push_top(data, 2);
	push_top(data, 2);
	sort_3(data);
	push_back(data);
	// print_stack(data);
	// push_back(data);
}