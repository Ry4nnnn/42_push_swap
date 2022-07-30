#include "push_swap.h"

static	void update_b(t_data *data)
{
	int i;
	int *temp;

	i = 0;
	temp = malloc(sizeof(int) * data->len_b);
	while (i < data->len_b)
	{
		temp[i] = data->stack_b[i + 1];
		i++;
	}
	i = 0;
	while (i < data->len_b)
	{
		data->stack_b[i] = temp[i];
		i++;
	}
	data->stack_b[i] = '\0';
	free(temp);
}

static	void update_a(t_data *data, int push)
{
	int *temp;
	int i;

	i = 0;
	temp = malloc(sizeof(int) * data->len_a);
	ft_putstr_fd("pa\n", 1);
	while (i < data->len_a)
	{
		temp[i] = data->stack_a[i];
		i++;
	}
	i = 0;
	data->len_a += 1;
	data->stack_a[0] = push;
	while (i < data->len_a)
	{
		data->stack_a[i + 1] = temp[i];
		i++;
	}
	data->stack_a[i] = '\0';
	free(temp);
}

void	push_a(t_data *data)
{
	int push;

	push = data->stack_b[0];
	data->len_b -= 1;
	update_b(data);
	if (data->len_a != 0)
		update_a(data, push);
	else
	{
		data->stack_a[0] = push;
		data->len_a += 1;
	}
	// printf ("||||||||||||||||||||||||||||||\n");
	// printf ("stack A:%d		| stack B:%d\n", data->stack_a[0], data->stack_b[0]);
	// printf ("stack A:%d		| stack B:%d\n", data->stack_a[1], data->stack_b[1]);
	// printf ("stack A:%d		| stack B:%d\n", data->stack_a[2], data->stack_b[2]);
	// printf ("stack A:%d		| stack B:%d\n", data->stack_a[3], data->stack_b[3]);
	// printf ("stack A:%d		| stack B:%d\n", data->stack_a[4], data->stack_b[4]);
	// printf ("stack A:%d		| stack B:%d\n", data->stack_a[5], data->stack_b[5]);
	// printf ("stack A:%d		| stack B:%d\n", data->stack_a[6], data->stack_b[6]);
	// printf ("stack A:%d		| stack B:%d\n", data->stack_a[7], data->stack_b[7]);
	// printf ("stack A:%d		| stack B:%d\n", data->stack_a[8], data->stack_b[8]);
	// printf ("stack A:%d		| stack B:%d\n", data->stack_a[9], data->stack_b[9]);
	// printf ("b:%d\n", data->len_b);
	// printf ("a:%d\n", data->len_a);
	// printf ("||||||||||||||||||||||||||||||\n");
}
