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
	// printf ("length:%d, stack_a:%d, mask:%d, next_mask:%d\n", data->len_a, data->stack_a[0], data->stack_b[0], data->stack_b[1]);
	if (mask > data->stack_a[data->len_a - 1])
	{
		push_a(data);
		rotate(data, 1);
	}
	if (data->len_a == 4)
	{
		if (mask > data->stack_a[2] && mask < data->stack_a[3])
		{
			rev_rotate(data, 1);
			push_a(data);
			rotate(data, 1);
			rotate(data, 1);
		}
	}
	if (mask > data->stack_a[1] && mask < data->stack_a[2])
	{
		rotate(data, 1);
		rotate(data, 1);
		push_a(data);
		rev_rotate(data, 1);
		rev_rotate(data, 1);
	}
	if (mask > data->stack_a[0] && mask < data->stack_a[1])
	{
		rotate(data, 1);
		push_a(data);
		rev_rotate(data, 1);
	}
	if (mask < data->stack_a[0])
		push_a(data);
}

void	sort_5(t_data *data)
{
	push_b(data);
	push_b(data);
	sort_3(data);
	// printf ("||||||||||||||||||||||||||||||\n");
	// printf ("stack A:%d		| stack B:%d\n", data->stack_a[0], data->stack_b[0]);
	// printf ("stack A:%d		| stack B:%d\n", data->stack_a[1], data->stack_b[1]);
	// printf ("stack A:%d		| stack B:%d\n", data->stack_a[2], data->stack_b[2]);
	// printf ("stack A:%d		| stack B:%d\n", data->stack_a[3], data->stack_b[3]);
	// printf ("stack A:%d		| stack B:%d\n", data->stack_a[4], data->stack_b[4]);
	// printf ("b:%d\n", data->len_b);
	// printf ("a:%d\n", data->len_a);
	// printf ("||||||||||||||||||||||||||||||\n");
	// rotate(data, 1);
	printf ("||||||||||||||||||||||||||||||\n");
	printf ("stack A:%d		| stack B:%d\n", data->stack_a[0], data->stack_b[0]);
	printf ("stack A:%d		| stack B:%d\n", data->stack_a[1], data->stack_b[1]);
	printf ("stack A:%d		| stack B:%d\n", data->stack_a[2], data->stack_b[2]);
	printf ("stack A:%d		| stack B:%d\n", data->stack_a[3], data->stack_b[3]);
	printf ("stack A:%d		| stack B:%d\n", data->stack_a[4], data->stack_b[4]);
	printf ("b:%d\n", data->len_b);
	printf ("a:%d\n", data->len_a);
	printf ("||||||||||||||||||||||||||||||\n");
	printf ("%d\n", data->stack_b[0]);
	push_a(data);
	printf ("||||||||||||||||||||||||||||||\n");
	printf ("stack A:%d		| stack B:%d\n", data->stack_a[0], data->stack_b[0]);
	printf ("stack A:%d		| stack B:%d\n", data->stack_a[1], data->stack_b[1]);
	printf ("stack A:%d		| stack B:%d\n", data->stack_a[2], data->stack_b[2]);
	printf ("stack A:%d		| stack B:%d\n", data->stack_a[3], data->stack_b[3]);
	printf ("stack A:%d		| stack B:%d\n", data->stack_a[4], data->stack_b[4]);
	printf ("b:%d\n", data->len_b);
	printf ("a:%d\n", data->len_a);
	printf ("||||||||||||||||||||||||||||||\n");
	rev_rotate(data, 1);
	// push_back(data);
	// printf ("||||||||||||||||||||||||||||||\n");
	// printf ("stack A:%d		| stack B:%d\n", data->stack_a[0], data->stack_b[0]);
	// printf ("stack A:%d		| stack B:%d\n", data->stack_a[1], data->stack_b[1]);
	// printf ("stack A:%d		| stack B:%d\n", data->stack_a[2], data->stack_b[2]);
	// printf ("stack A:%d		| stack B:%d\n", data->stack_a[3], data->stack_b[3]);
	// printf ("stack A:%d		| stack B:%d\n", data->stack_a[4], data->stack_b[4]);
	// printf ("b:%d\n", data->len_b);
	// printf ("a:%d\n", data->len_a);
	// printf ("||||||||||||||||||||||||||||||\n");
	// push_back(data);
	// printf ("||||||||||||||||||||||||||||||\n");
	// printf ("stack A:%d		| stack B:%d\n", data->stack_a[0], data->stack_b[0]);
	// printf ("stack A:%d		| stack B:%d\n", data->stack_a[1], data->stack_b[1]);
	// printf ("stack A:%d		| stack B:%d\n", data->stack_a[2], data->stack_b[2]);
	// printf ("stack A:%d		| stack B:%d\n", data->stack_a[3], data->stack_b[3]);
	// printf ("stack A:%d		| stack B:%d\n", data->stack_a[4], data->stack_b[4]);
	// printf ("b:%d\n", data->len_b);
	// printf ("a:%d\n", data->len_a);
	// printf ("||||||||||||||||||||||||||||||\n");
}
