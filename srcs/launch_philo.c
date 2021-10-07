#include "philo.h"

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
	i = 0;
	ft_usleep(1000);
	while (i < env->nb_philo)
	{
		pthread_detach(philo[i].t_id);
		++i;
	}
}

static unsigned int	take_fork(t_philo *philo)
{
	unsigned int		fork;

	fork = philo->p_id;
	if (fork + 1 >= philo->env->nb_philo)
		fork = 0;
	else
		fork += 1;
	pthread_mutex_lock(&(philo->env->fork[fork]));
	dis_take_fork(philo);
	fork = philo->p_id;
	pthread_mutex_lock(&(philo->env->fork[philo->p_id]));
	dis_take_fork(philo);
	if (fork + 1 >= philo->env->nb_philo)
		fork = 0;
	else
		fork += 1;
	return (fork);
}

void	*routine(void *arg)
{
	t_philo		*philo;

	philo = arg;
	unsigned int		fork;

	while (philo->env->is_all_created == 0)
		ft_usleep(100);
	philo->start_time = get_time();
	if (philo->p_id % 2 == 0 && philo->env->philo[philo->p_id + 1].has_eaten == 0)
		ft_usleep(philo->env->time_to_eat);
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
		write(1, "\n", 1);
	}
	return (NULL);
}

int	launch_philo(t_env *env)
{
	unsigned int	i;
	unsigned int	time;
	t_philo			*philo;

	i = 0;
	time = 0;
	env->is_dead = 0;
	env->nb_feed = 0;
	env->is_all_created = 0;
	philo = (t_philo *)malloc(sizeof(t_philo) * env->nb_philo);
	env->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * env->nb_philo);
	if (env->fork == NULL)
		return (-1);
	if (philo == NULL)
		return (-1);
	env->philo = philo;
	pthread_mutex_init(&env->m_write, NULL);
	while (i < env->nb_philo)
	{
		pthread_mutex_init(&(env->fork[i]), NULL);
		++i;
	}
	i = 0;
	while (i < env->nb_philo)
	{
		philo[i].p_id = i;
		philo[i].env = env;
		philo[i].last_meal = get_time();
		philo[i].nb_eat = 0;
		philo[i].start_time = 0;
		philo[i].has_eaten = 0;
		pthread_create(&(philo[i].t_id), NULL, routine, &(philo[i]));
		++i;
	}
	env->is_all_created = 1;
	philo_is_dead(env, philo);
	return (0);
}
