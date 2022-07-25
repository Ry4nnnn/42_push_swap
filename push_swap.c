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

void	ft_swap(int a, int b)
{
	
}

void	check_sorted(int argc, char **argv)
{
	int	i;

	i = 1;
	while (argc++)
	{
		if (*argv[i] > *argv[i + 1]);
			ft_swap
	}
}

void	insertion_sort(int argc, char **argv)
{

}

int main(int argc, char **argv)
{
	check_error(argc, argv);
	check_sorted(argc, argv);
	insertion_sort(argc, argv);
	return (0);
}