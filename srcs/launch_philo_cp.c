#include "philo.h"

/*
static	void	check_death(t_env *env)
{
	unsigned	int		i;
	long long int time;

	while (env->start_time == 0)
		usleep(10);
	while (env->is_dead == 0)
	{
		i = 0;
		while (env->is_dead == 0 && i < env->nb_philo)
		{
			if ((time = get_time() - env->start_time) >= env->time_to_die)
			{
				printf("%lld\n", time);
				env->is_dead = 1;
			}
			++i;
//			usleep(10);
		}
	}
}
*/

void	*checker(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	long long int time;
	
	while (philo->env->start_time == 0)
		usleep(10);
	while (1)
	{
		if ((time = get_time() - philo->env->start_time) >= philo->env->time_to_die)
		{
			philo->env->is_dead = 1;
//			printf("%lld\n", time);
			return (arg);
		}
		usleep(10);
	}
	return (arg);
}


void	*routine(void *arg)
{
	t_philo 		*philo;
	pthread_t		id;

	philo = (t_philo *)arg;
	pthread_create(&id, NULL, checker, philo);
//	usleep(100);
	while (philo->env->is_all_created == 0)
		usleep(10);

//	long long int time = 0;
	while (philo->env->is_dead == 0)
	{
		printf("%lld\n", get_time() - philo->env->start_time);
//		ft_usleep(philo->env->time_to_eat);
	}
//	printf("%lld\n", get_time() - philo->env->start_time);
	pthread_join(id, NULL);
	return (NULL);
}

int	launch_philo(t_env *env)
{
	unsigned int			i;

	i = 0;
	while (i < env->nb_philo)
	{
		pthread_create(&env->philo[i].t_id, NULL, routine, &(env->philo[i]));
		++i;
	}
	env->start_time = get_time();
	env->is_all_created = 1;

	i = 0;
//	check_death(env);

	while (i < env->nb_philo)
	{
		pthread_join(env->philo[i].t_id, NULL);
		pthread_detach(env->philo[i].t_id);
		++i;
	}
	return (0);
}
