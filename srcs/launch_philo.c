#include "philo.h"

static	void	check_death(t_env *env)
{
	unsigned	int		i;
	long long int time;
	t_philo		*philo;

	philo = env->philo;
	while (env->start_time == 0)
		usleep(10);
	if (philo->p_id % 2 == 0)
		ft_usleep(10);
	while (env->is_dead == 0)
	{
		i = 0;
		while (env->is_dead == 0 && i < env->nb_philo)
		{
			if ((time = get_time() - philo[i].last_meal) >= env->time_to_die)
			{
				pthread_mutex_lock(&(env->m_write));
				dis_death(philo, philo[i].p_id);
				env->is_dead = 1;
				pthread_mutex_unlock(&(env->m_write));
			}
			++i;
			usleep(10);
		}
	}
}

static	void	dinner(t_philo *philo)
{
	t_env *env;

	env = philo->env;
	pthread_mutex_lock(&(env->fork[philo->l_fork]));
	dis_take_fork(philo);
	pthread_mutex_lock(&(env->fork[philo->r_fork]));
	dis_take_fork(philo);
	philo->last_meal = get_time();
	dis_eat(philo);
	ft_usleep(env->time_to_eat);
	pthread_mutex_unlock(&(env->fork[philo->l_fork]));
	pthread_mutex_unlock(&(env->fork[philo->r_fork]));
}

void	*routine(void *arg)
{
	t_philo 		*philo;
	t_env			*env;

	philo = (t_philo *)arg;
	env = philo->env;
	while (philo->env->is_all_created == 0)
		usleep(10);
	philo->last_meal = get_time();
	if (philo->p_id % 2 == 1)
		usleep(10000);
	while (env->is_dead == 0)
	{
		if (env->is_dead == 0)
			dinner(philo);
		if (env->is_dead == 0)
			dis_sleep(philo);
		ft_usleep(env->time_to_sleep);
		if (env->is_dead == 0)
			dis_think(philo);
	}
	pthread_exit(arg);
}

int	launch_philo(t_env *env)
{
	unsigned int			i;

	i = 0;
	while (i < env->nb_philo)
	{
		pthread_create(&(env->philo[i].t_id), NULL, routine, &(env->philo[i]));
		++i;
	}
	env->start_time = get_time();
	env->is_all_created = 1;
	i = 0;
	usleep(1000);
	check_death(env);
	pthread_mutex_unlock(&(env->m_write));
	while (i < env->nb_philo)
	{
		pthread_join(env->philo[i].t_id, NULL);
		++i;
	}
	return (0);
}
