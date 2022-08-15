#include "checker.h"

static t_stack	*reset_struct(t_stack *stack)
{
	stack->a = 0;
	stack->b = 0;
	stack->size_a = 0;
	stack->size_b = 0;
	return (stack);
}

int main(int argc, char **argv);
{
	t_stack *stack;

	stack = ft_calloc(1, sizeof(t_stack));
	reset_struct(stack);
	if (argc => 2)
	{
		
	}
	return (0);
}