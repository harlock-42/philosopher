#include "philo.h"

int		get_arg(t_env *env, char **arg)
{
	env->nb_philo = ft_atoi(arg[0]);
	env->time_to_die = ft_atoi(arg[1]);
	env->time_to_eat = ft_atoi(arg[2]);
	env->time_to_sleep = ft_atoi(arg[3]);
	printf("%u\n", env->nb_philo);
	return (0);
}
