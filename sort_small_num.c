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
		rev_rotate(data, 1);
	else if (a > b && a > c && b < c)
		rotate(data, 1);
	else if (a > b && a > c && b > c)
	{
		swap_top(data, 1);
		rev_rotate(data, 1);
	}
	else if (a < b && a < c && b > c)
	{
		swap_top(data, 1);
		rotate(data, 1);
	}
}

void	push_back(t_data *data)
{
	int mask;

	mask = data->stack_b[0];
	if (mask > data->stack_a[4])
	{
		push_a(data);
		rotate(data, 1);
	}
	if (mask < data->stack_a[4])
	{
		rev_rotate(data, 1);
		push_a(data);
		rotate(data, 1);
		rotate(data, 1);
	}
	else if (mask < data->stack_a[3])
	{
		rev_rotate(data, 1);
		push_a(data);
		rotate(data, 1);
		rotate(data, 1);
	}
	else if (mask < data->stack_a[2])
	{
		rotate(data, 1);
		rotate(data, 1);
		push_a(data);
		rev_rotate(data, 1);
		rev_rotate(data, 1);
	}
	else if (mask < data->stack_a[1])
	{
		rotate(data, 1);
		push_a(data);
		rev_rotate(data, 1);
	}
	else
		push_a(data);
}

void	sort_5(t_data *data)
{
	push_b(data);
	push_b(data);
	sort_3(data);
	push_back(data);
	push_back(data);
}
