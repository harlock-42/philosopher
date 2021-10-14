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
			if (env->philo[i].last_meal != 0 && get_time() - env->philo[i].last_meal >= env->time_to_die)
			{
				pthread_mutex_lock(&env->m_write);
				printf("last_meal = %lld\n", get_time() - env->philo[i].last_meal);
				dis_death(&env->philo[i]);
				env->is_dead = 1;
			}
			++i;
		}
	}
}

static void take_dinner(t_philo *philo)
{
	t_env	*env;

	env = philo->env;
	pthread_mutex_lock(&(env->fork[philo->l_fork]));
	dis_take_fork(philo);
	pthread_mutex_lock(&(env->fork[philo->r_fork]));
	dis_take_fork(philo);
//	pthread_mutex_lock(&(env->is_mealed));
	dis_eat(philo);
	philo->last_meal = get_time();
//	pthread_mutex_unlock(&(env->is_mealed));
	ft_usleep(env->time_to_eat);
	++philo->nb_eat;
	philo->has_eaten = 1;
	pthread_mutex_unlock(&(env->fork[philo->l_fork]));
	pthread_mutex_unlock(&(env->fork[philo->r_fork]));
}

void	*routine(void *arg)
{
	t_philo		*philo;
	t_env		*env;

	philo = (t_philo *)arg;
	env = philo->env;
//	while (philo->env->start_time == 0)
//		ft_usleep(100);
	if (philo->p_id % 2)
		ft_usleep(100);
	while (env->is_dead == 0)
	{
		take_dinner(philo);
		if (philo->nb_eat >= env->nb_meal)
			break ;
		dis_sleep(philo);
		ft_usleep(env->time_to_sleep);
		dis_think(philo);
	}
	return (NULL);
}

int	launch_philo(t_env *env)
{
	t_philo			*philo;
	unsigned int	i;

	i = 0;
	philo = env->philo;
	env->start_time = get_time();
	while (i < env->nb_philo)
	{
		pthread_create(&(philo[i].t_id), NULL, routine, &(philo[i]));
		philo[i].last_meal = get_time();
		++i;
	}
	philo_is_dead(env);
	i = 0;
	ft_usleep(1000000);
	while (i < env->nb_philo)
	{
		pthread_join(philo[i].t_id, NULL);
		++i;
	}
	i = 0;
	while (i < env->nb_philo)
	{
		pthread_mutex_destroy(&(env->fork[i]));
		++i;
	}
	return (0);
}
