#include "philo.h"

int		get_arg(t_env *env, char **arg)
{
	env->nb_philo = ft_atoi(arg[0]);
//	printf("%d\n", env->nb_philo);
	env->time_to_die = ft_atoi(arg[1]);
	env->time_to_eat = ft_atoi(arg[2]);
	env->time_to_sleep = ft_atoi(arg[3]);
	if (arg[4] != NULL)
		env->nb_meal = ft_atoi(arg[4]);
	else
		env->nb_meal = 4294967295;
	return (0);
}
