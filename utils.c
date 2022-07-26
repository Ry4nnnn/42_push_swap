#include "push_swap.h"

int	ft_isnum(char *s)
{
	int i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}
