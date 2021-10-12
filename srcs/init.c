#include "philo.h"

t_philo	*init_philo(t_env *env)
{
	t_philo	*philo;
	unsigned int	i;

	i = 0;
	philo = (t_philo *)malloc(sizeof(t_philo) * env->nb_philo);
	if (philo == NULL)
		return (NULL);
	while (i < env->nb_philo)
	{
		philo[i].p_id = i;
		philo[i].env = env;
		philo[i].last_meal = get_time();
		philo[i].nb_eat = 0;
		philo[i].has_eaten = 0;
		pthread_mutex_init(&(env->fork[i]), NULL);
		++i;
	}
	pthread_mutex_init(&env->m_write, NULL);
	return (philo);
}
