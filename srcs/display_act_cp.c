#include "philo.h"

void	dis_eat(t_philo *philo)
{
	t_env			*env;
	char		 	buffer[200];
	char			*tmp;

	env = philo->env;
	ft_bzero(buffer, 200);
	pthread_mutex_lock(&(env->m_write));
	if (env->is_dead == 0)
	{
		tmp = ft_itoa(get_time() - env->start_time);
		ft_strcat(buffer, tmp);
		free(tmp);
		ft_strcat(buffer, " \033[1;35m");
		tmp = ft_itoa((long long int)(philo->p_id + 1));
		ft_strcat(buffer, tmp);
		free(tmp);
		ft_strcat(buffer, "\033[1;33m is eating\033[0m\n");
		write(1, buffer, ft_strlen(buffer));
	}
	pthread_mutex_unlock(&(env->m_write));
}

void	dis_think(t_philo *philo)
{
	t_env			*env;
	char		 	buffer[200];
	char			*tmp;

	env = philo->env;
	ft_bzero(buffer, 200);
	pthread_mutex_lock(&(env->m_write));
	if (env->is_dead == 0)
	{
		tmp = ft_itoa(get_time() - env->start_time);
		ft_strcat(buffer, tmp);
		free(tmp);
		ft_strcat(buffer, " \033[1;35m");
		tmp = ft_itoa((long long int)(philo->p_id + 1));
		ft_strcat(buffer, tmp);
		free(tmp);
		ft_strcat(buffer, "\033[1;32m is thinking\033[0m\n");
		write(1, buffer, ft_strlen(buffer));
	}
	pthread_mutex_unlock(&(env->m_write));
}

void	dis_sleep(t_philo *philo)
{
	t_env			*env;
	char		 	buffer[200];
	char			*tmp;

	env = philo->env;
	ft_bzero(buffer, 200);
	pthread_mutex_lock(&(env->m_write));
	if (env->is_dead == 0)
	{
		tmp = ft_itoa(get_time() - env->start_time);
		ft_strcat(buffer, tmp);
		free(tmp);
		ft_strcat(buffer, " \033[1;35m");
		tmp = ft_itoa((long long int)(philo->p_id + 1));
		ft_strcat(buffer, tmp);
		free(tmp);
		ft_strcat(buffer, "\033[1;34m is sleeping\033[0m\n");
		write(1, buffer, ft_strlen(buffer));
	}
	pthread_mutex_unlock(&(env->m_write));
}

void	dis_take_fork(t_philo *philo)
{
	t_env			*env;
	char		 	buffer[200];
	char			*tmp;

	env = philo->env;
	ft_bzero(buffer, 200);
	pthread_mutex_lock(&(env->m_write));
	if (env->is_dead == 0)
	{
		tmp = ft_itoa(get_time() - env->start_time);
		ft_strcat(buffer, tmp);
		free(tmp);
		ft_strcat(buffer, " \033[1;35m");
		tmp = ft_itoa((long long int)(philo->p_id + 1));
		ft_strcat(buffer, tmp);
		free(tmp);
		ft_strcat(buffer, "\033[1;34m has taken a fork\033[0m\n");
		write(1, buffer, ft_strlen(buffer));
	}
	pthread_mutex_unlock(&(env->m_write));
}

void	dis_death(t_philo *philo)
{
	long long	int	time;

	time = get_time() - philo->env->start_time;
	ft_putnbr_fd(time, 1);
	write(1, " ", 1);
	write(1, PURPLE, ft_strlen(PURPLE));
	ft_putnbr_fd(philo->p_id + 1, 1);
	write(1, " ", 1);
	write(1, GREY, ft_strlen(BLUE));
	write(1, "died\n", 6);
	write(1, NC, ft_strlen(NC));
}
