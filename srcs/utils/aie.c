#include "philo.h"

int	aie(char *str)
{
	write(2, "ERROR\n", 6);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (-1);
}