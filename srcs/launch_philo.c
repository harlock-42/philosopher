#include "philo.h"

void	ft_usleep(long int time)
{
	long	int	i;
	long	int	start;

	start = get_time();
	i = 0;
	while (1)
	{
		i = get_time();
		if ((i - start) >= time)
			break ;
		usleep(50);
	}
}

long int	get_time(void)
{
	struct		timeval	tv;
	long	int			time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000;
	time += tv.tv_usec / 1000;
	return (time);
}

void	*routine(void *arg)
{
	t_env		*env;
	long	int	start;

	env = arg;
	start = get_time();
	while (1)
	{
		if (get_time() - start > env->time_to_die)
			break ;
		start = get_time();
		dis_eat(env);
		ft_usleep(env->time_to_eat);
		if (get_time() - start > env->time_to_die)
			break ;
		dis_sleep(env);
		ft_usleep(env->time_to_sleep);
		dis_think(env);
		write(1, "\n", 1);
	}
	return (NULL);
}

int	launch_philo(t_env *env)
{
	unsigned int	i;

	i = 0;
	
	pthread_mutex_init(&env->m_write, NULL);
	env->start_time = get_time();
	env->t_id = (pthread_t *)malloc(sizeof(pthread_t) * env->nb_philo);
	while (i < env->nb_philo)
	{
		env->p_id = i;
		pthread_create(&env->t_id[i], NULL, routine, env);
		++i;
	}
	i = 0;
	while (i < env->nb_philo)
	{
		pthread_join(env->t_id[i], NULL);
		++i;
	}
	return (0);
}