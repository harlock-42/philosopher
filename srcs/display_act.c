#include "philo.h"

void	dis_eat(t_env *env)
{
	pthread_mutex_lock(&env->m_write);

	long	int	time;
	int		index;

	index = 0;
	time = get_time() - env->start_time;
	ft_putnbr_fd(time, 1);
	write(1, " ", 1);
	ft_putnbr_fd(env->philo->p_id, 1);
	write(1, " ", 1);
	write(1, "is eating\n", 10);
	pthread_mutex_unlock(&env->m_write);

}

void	dis_think(t_env *env)
{
	pthread_mutex_lock(&env->m_write);
	long	int	time;

	time = get_time() - env->start_time;
	ft_putnbr_fd(time, 1);
	write(1, " ", 1);
	ft_putnbr_fd(env->philo->p_id, 1);
	write(1, " ", 1);
	write(1, "is thinking\n", 13);
	pthread_mutex_unlock(&env->m_write);
}

void	dis_sleep(t_env *env)
{
		pthread_mutex_lock(&env->m_write);

	long	int	time;

	time = get_time() - env->start_time;
	ft_putnbr_fd(time, 1);
	write(1, " ", 1);
	ft_putnbr_fd(env->philo->p_id, 1);
	write(1, " ", 1);
	write(1, "is sleeping\n", 12);
	pthread_mutex_unlock(&env->m_write);
}