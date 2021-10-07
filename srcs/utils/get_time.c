#include "philo.h"

unsigned long int	get_time(void)
{
	struct						timeval	tv;
	unsigned long	int			time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000;
	time += tv.tv_usec / 1000;
	return (time);
}
