/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_act.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:59:11 by tallaire          #+#    #+#             */
/*   Updated: 2021/10/15 17:27:20 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dis_eat(t_philo *philo)
{
	long long int	time;
	t_env			*env;

	env = philo->env;
	pthread_mutex_lock(&(env->m_write));
	if (env->is_dead == 0 && philo->nb_eat <= env->nb_meal)
	{
		time = get_time() - env->start_time;
		ft_putnbr_fd(time, 1);
		write(1, " ", 1);
		write(1, PURPLE, ft_strlen(PURPLE));
		ft_putnbr_fd(philo->p_id + 1, 1);
		write(1, " ", 1);
		write(1, YELLOW, ft_strlen(YELLOW));
		write(1, "is eating\n", 10);
		write(1, NC, ft_strlen(NC));
	}
	pthread_mutex_unlock(&(env->m_write));
}

void	dis_think(t_philo *philo)
{
	long long int	time;
	t_env			*env;

	env = philo->env;
	pthread_mutex_lock(&(env->m_write));
	if (env->is_dead == 0)
	{
		time = get_time() - env->start_time;
		ft_putnbr_fd(time, 1);
		write(1, " ", 1);
		write(1, PURPLE, ft_strlen(PURPLE));
		ft_putnbr_fd(philo->p_id + 1, 1);
		write(1, " ", 1);
		write(1, GREEN, ft_strlen(GREEN));
		write(1, "is thinking\n", 12);
		write(1, NC, ft_strlen(NC));
	}
	pthread_mutex_unlock(&(env->m_write));
}

void	dis_sleep(t_philo *philo)
{
	long long int	time;
	t_env			*env;

	env = philo->env;
	pthread_mutex_lock(&(env->m_write));
	if (env->is_dead == 0)
	{
		time = get_time() - env->start_time;
		ft_putnbr_fd(time, 1);
		write(1, " ", 1);
		write(1, PURPLE, ft_strlen(PURPLE));
		ft_putnbr_fd(philo->p_id + 1, 1);
		write(1, " ", 1);
		write(1, BLUE, ft_strlen(BLUE));
		write(1, "is sleeping\n", 12);
		write(1, NC, ft_strlen(NC));
	}
	pthread_mutex_unlock(&(env->m_write));
}

void	dis_take_fork(t_philo *philo)
{
	long long int	time;
	t_env			*env;

	env = philo->env;
	pthread_mutex_lock(&(env->m_write));
	if (env->is_dead == 0 && philo->nb_eat <= env->nb_meal)
	{
		time = get_time() - env->start_time;
		ft_putnbr_fd(time, 1);
		write(1, " ", 1);
		write(1, PURPLE, ft_strlen(PURPLE));
		ft_putnbr_fd(philo->p_id + 1, 1);
		write(1, " ", 1);
		write(1, CYAN, ft_strlen(CYAN));
		write(1, "has taken a fork\n", 17);
		write(1, NC, ft_strlen(NC));
	}
	pthread_mutex_unlock(&(env->m_write));
}

void	dis_death(t_philo *philo, int id)
{
	long long int	time;
	t_env			*env;

	env = philo->env;
	time = get_time() - env->start_time;
	ft_putnbr_fd(time, 1);
	write(1, " ", 1);
	write(1, PURPLE, ft_strlen(PURPLE));
	ft_putnbr_fd(id + 1, 1);
	write(1, " ", 1);
	write(1, GREY, ft_strlen(BLUE));
	write(1, "died\n", 6);
	write(1, NC, ft_strlen(NC));
}
