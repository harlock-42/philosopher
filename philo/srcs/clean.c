#include "philo.h"

int	clean(t_env *env, int ret)
{
	unsigned int	i;

	i = 0;
	while (i < env->nb_philo)
	{
		pthread_detach(env->philo[i].t_id);
		++i;
	}
	i = 0;
	while (i < env->nb_philo)
	{
		pthread_mutex_destroy(&(env->fork[i]));
		++i;
	}
	pthread_mutex_destroy(&env->m_write);
	return (ret);
}