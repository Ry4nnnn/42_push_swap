#include "../includes/push_swap.h"

void	check_error(int argc, char **argv)
{
	int i;
	int	j;

	i = 1;
	if (argc < 2)
	{
		ft_putstr_fd("Usage: [Programe Name] [Numbers]\n", 1);
		exit(0);
	}
	while (argv[i])
	{
		if (!(ft_isnum(argv[i])))
		{
			ft_putstr_fd("Error!\n", 1);
			exit(0);
		}
		j = 0;
		while (argv[++j])
		{
			if ((ft_atoi(argv[j]) == ft_atoi(argv[i]) && j != i)
				|| (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN))
			{
				ft_putstr_fd("No Duplicate numbers allowed\n", 1);
				exit (0);
			}
		}
		i++;
	}
}

//sa (swap a): Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one or no elements.
// void	sa(int argc, char **argv)
// {
// 	char *temp;

// 	if (argc == 2)
// 		return (0);
// 	else
// 	{
// 		temp == argv[1];
// 		argv[1] == argv[2];
// 		argv[2] == temp;
// 	}
// }

int main(int argc, char **argv)
{
	check_error(argc, argv);
	
	return (0);
}