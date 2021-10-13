#include "philo.h"

void	init_philo(t_env *env)
{
	unsigned int	i;

	i = 0;
	while (i < env->nb_philo)
	{
		env->philo[i].p_id = i;
		env->philo[i].env = env;
		env->philo[i].last_meal = 0;
		env->philo[i].nb_eat = 0;
		env->philo[i].has_eaten = 0;
		pthread_mutex_init(&(env->fork[i]), NULL);
		env->philo[i].l_fork = i;
		if (i == env->nb_philo - 1)
			env->philo[i].r_fork = 0;
		else
			env->philo[i].r_fork = i + 1;
		++i;
	}
	pthread_mutex_init(&env->m_write, NULL);
}
