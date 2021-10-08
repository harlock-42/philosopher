#include "philo.h"

static	t_philo	*init_philo(t_env *env)
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
		philo[i].start_time = 0;
		philo[i].has_eaten = 0;
		pthread_mutex_init(&(env->fork[i]), NULL);
		++i;
	}
	pthread_mutex_init(&env->m_write, NULL);
	return (philo);
}

static	void	philo_is_dead(t_env *env, t_philo *philo)
{
	unsigned int		i;

	while (env->is_dead != 1 && env->nb_meal > env->nb_feed)
	{
		i = 0;
		while (i < env->nb_philo && env->is_dead != 1 && env->nb_meal > env->nb_feed)
		{
			if (philo[i].nb_eat >= env->nb_meal)
				++env->nb_feed;
			if (env->nb_meal <= env->nb_feed)
				break ;
			if (get_time() - philo[i].last_meal >= env->time_to_die)
			{
				pthread_mutex_lock(&philo->env->m_write);
				dis_death(&philo[i]);
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

//	while (philo->env->is_all_created == 0)
//		ft_usleep(100);
	philo->start_time = get_time();
	if (philo->p_id % 2 == 0 && philo->env->philo[philo->p_id + 1].has_eaten == 0)
		ft_usleep(10);
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
	t_philo			*philo;

	i = 0;
	philo = init_philo(env);
	if (philo == NULL)
		return (-1);
	env->philo = philo;
	while (i < env->nb_philo)
	{
		pthread_create(&(philo[i].t_id), NULL, routine, &(philo[i]));
		++i;
	}
	env->is_all_created = 1;
	philo_is_dead(env, philo);
	i = 0;
	ft_usleep(1000);
	while (i < env->nb_philo)
	{
		pthread_join(philo[i].t_id, NULL);
		pthread_detach(philo[i].t_id);
		++i;
	}
	return (0);
}
