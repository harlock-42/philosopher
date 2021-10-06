#include "philo.h"

void	ft_usleep(long int time)
{
	long	int	i;
	long	int	start;

	start = get_time();
	i = 0;
	while (1)
	{
		i = get_time();
		if ((i - start) >= time)
			break ;
		usleep(50);
	}
}