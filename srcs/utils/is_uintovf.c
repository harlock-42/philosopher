#include "philo.h"

int	is_uintovf(char *str)
{
	int		size;
	int		diff;

	size = ft_strlen(str);
	diff = 0;
	if (size > 10)
		return (YES);
	diff = ft_strcmp(str, "4294967295");
	if (diff > 0)
		return (YES);
	return (NO);
}