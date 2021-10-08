#include "philo.h"

t_env	*free_env(t_env *env)
{
	free(env->philo);
	return (NULL);
}