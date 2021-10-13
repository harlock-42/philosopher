#include "philo.h"

void	dis_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->env->m_write);

	long long	int	time;
	int				index;

	index = 0;
	time = get_time() - philo->env->start_time;
	ft_putnbr_fd(time, 1);
	write(1, " ", 1);
	write(1, PURPLE, ft_strlen(PURPLE));
	ft_putnbr_fd(philo->p_id + 1, 1);
	write(1, " ", 1);
	write(1, YELLOW, ft_strlen(YELLOW));
	write(1, "is eating\n", 10);
	write(1, NC, ft_strlen(NC));
	pthread_mutex_unlock(&philo->env->m_write);
}

void	dis_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->env->m_write);
	long long	int	time;

	time = get_time() - philo->env->start_time;
	ft_putnbr_fd(time, 1);
	write(1, " ", 1);
	write(1, PURPLE, ft_strlen(PURPLE));
	ft_putnbr_fd(philo->p_id + 1, 1);
	write(1, " ", 1);
	write(1, GREEN, ft_strlen(GREEN));
	write(1, "is thinking\n", 13);
	write(1, NC, ft_strlen(NC));
	pthread_mutex_unlock(&philo->env->m_write);
}

void	dis_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->env->m_write);

	long long	int	time;

	time = get_time() - philo->env->start_time;
	ft_putnbr_fd(time, 1);
	write(1, " ", 1);
	write(1, PURPLE, ft_strlen(PURPLE));
	ft_putnbr_fd(philo->p_id + 1, 1);
	write(1, " ", 1);
	write(1, BLUE, ft_strlen(BLUE));
	write(1, "is sleeping\n", 12);
	write(1, NC, ft_strlen(NC));
	pthread_mutex_unlock(&philo->env->m_write);
}

void	dis_take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->env->m_write);

	long long	int	time;

	time = get_time() - philo->env->start_time;
	ft_putnbr_fd(time, 1);
	write(1, " ", 1);
	write(1, PURPLE, ft_strlen(PURPLE));
	ft_putnbr_fd(philo->p_id + 1, 1);
	write(1, " ", 1);
	write(1, CYAN, ft_strlen(CYAN));
	write(1, "has taken a fork\n", 17);
	write(1, NC, ft_strlen(NC));
	pthread_mutex_unlock(&philo->env->m_write);
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
