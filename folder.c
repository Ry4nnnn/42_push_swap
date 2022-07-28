#include "push_swap.h"

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

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*res;

	if (nmemb > 4294967295 || size > 4294967295)
		return (NULL);
	res = malloc(nmemb * size);
	if (!res)
		return (0);
	ft_bzero(res, (nmemb * size));
	return (res);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write (fd, s, 1);
		s++;
	}
}

void	ft_bzero(void	*s, size_t	n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = 0;
}
