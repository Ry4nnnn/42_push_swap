#include "../includes/push_swap.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ((*str >= 48 && *str <= 57) && *str != '\0')
	{
		result = (*str - 48) + (result * 10);
		str++;
	}
	return (result * sign);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write (fd, s, 1);
		s++;
	}
}

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
