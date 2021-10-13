#include "philo.h"

static	void	philo_is_dead(t_env *env)
{
	unsigned int		i;

	while (env->is_dead != 1 && env->nb_meal > env->nb_feed)
	{
		i = 0;
		while (i < env->nb_philo && env->is_dead != 1 && env->nb_meal > env->nb_feed)
		{
			if (env->philo[i].nb_eat >= env->nb_meal)
				++env->nb_feed;
			if (env->nb_meal <= env->nb_feed)
				break ;
			if ( env->philo[i].last_meal != 0 && get_time() - env->philo[i].last_meal >= env->time_to_die)
			{
				pthread_mutex_lock(&env->m_write);
				dis_death(&env->philo[i]);
				env->is_dead = 1;
			}
			++i;
		}
	}
}

static unsigned int	take_fork(t_philo *philo)
{
	unsigned int		fork;

	fork = philo->p_id;
	pthread_mutex_lock(&(philo->env->fork[philo->p_id]));
	dis_take_fork(philo);
	fork = philo->p_id;
	if (fork + 1 >= philo->env->nb_philo)
		fork = 0;
	else
		fork += 1;
	pthread_mutex_lock(&(philo->env->fork[fork]));
	dis_take_fork(philo);
	return (fork);
}

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = arg;
	unsigned int		fork;

	while (philo->env->start_time == 0)
		ft_usleep(100);
	if (philo->p_id % 2 == 0 && philo->env->philo[philo->p_id + 1].has_eaten == 0)
		ft_usleep(5000);
	while (philo->env->is_dead == 0)
	{
		fork = take_fork(philo);
		dis_eat(philo);
		philo->last_meal = get_time();
		ft_usleep(philo->env->time_to_eat);
		++philo->nb_eat;
		philo->has_eaten = 1;
		pthread_mutex_unlock(&(philo->env->fork[philo->p_id]));
		pthread_mutex_unlock(&(philo->env->fork[fork]));
		if (philo->nb_eat >= philo->env->nb_meal)
			break ;
		dis_sleep(philo);
		ft_usleep(philo->env->time_to_sleep);
		dis_think(philo);
		usleep(200);
	}
	return (NULL);
}

int	launch_philo(t_env *env)
{
	unsigned int	i;

	i = 0;
	while (i < env->nb_philo)
	{
		pthread_create(&env->philo[i].t_id, NULL, routine, &(env->philo[i]));
		++i;
	}
	env->start_time = get_time();
	philo_is_dead(env);
	i = 0;
	ft_usleep(1000);
	while (i < env->nb_philo)
	{
		pthread_join(env->philo[i].t_id, NULL);
		++i;
	}
	return (0);
}
