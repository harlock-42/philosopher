/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:53:54 by tallaire          #+#    #+#             */
/*   Updated: 2021/10/20 13:59:01 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	kill_philo(t_env *env, t_philo *philo, int i)
{
	pthread_mutex_lock(&(env->m_write));
	dis_death(philo, philo[i].p_id);
	env->is_dead = 1;
	pthread_mutex_unlock(&(env->m_write));
}

static	void	check_death(t_env *env)
{
	unsigned int	i;
	t_philo			*philo;

	philo = env->philo;
	while (env->start_time == 0)
		usleep(10);
	if (philo->p_id % 2 == 0)
		ft_usleep(10);
	while (env->is_dead == 0 && env->nb_feed <= env->nb_philo)
	{
		i = 0;
		while (env->is_dead == 0 && i < env->nb_philo
			&& env->nb_feed <= env->nb_philo)
		{
			if (philo[i].is_feed == 0 && get_time()
				- philo[i].last_meal >= env->time_to_die)
				kill_philo(env, philo, i);
			if (philo[i].is_feed == 1)
				++env->nb_feed;
			++i;
			usleep(10);
		}
	}
}

static	void	dinner(t_philo *philo)
{
	t_env	*env;

	env = philo->env;
	if (philo->p_id % 2 == 1)
	{
		pthread_mutex_lock(&(env->fork[philo->r_fork]));
		dis_take_fork(philo);
		pthread_mutex_lock(&(env->fork[philo->l_fork]));
		dis_take_fork(philo);
	}
	else
	{
		pthread_mutex_lock(&(env->fork[philo->l_fork]));
		dis_take_fork(philo);
		if (env->nb_philo == 1)
			return ;
		pthread_mutex_lock(&(env->fork[philo->r_fork]));
		dis_take_fork(philo);
	}
	philo->last_meal = get_time();
	++philo->nb_eat;
	dis_eat(philo);
	ft_usleep(env->time_to_eat);
	pthread_mutex_unlock(&(env->fork[philo->l_fork]));
	pthread_mutex_unlock(&(env->fork[philo->r_fork]));
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_env	*env;

	philo = (t_philo *)arg;
	env = philo->env;
	while (philo->env->is_all_created == 0)
		usleep(10);
	philo->last_meal = get_time();
	if (philo->p_id % 2 == 1)
		usleep(1000);
	while (env->is_dead == 0 && philo->is_feed == 0)
	{
		if (philo->nb_eat >= env->nb_meal)
			philo->is_feed = 1;
		if (env->is_dead == 0)
			dinner(philo);
		if (env->nb_philo == 1)
			break ;
		if (env->is_dead == 0)
			dis_sleep(philo);
		ft_usleep(env->time_to_sleep);
		if (env->is_dead == 0)
			dis_think(philo);
	}
	pthread_exit(arg);
}

int	launch_philo(t_env *env)
{
	unsigned int			i;

	i = 0;
	while (i < env->nb_philo)
	{
		pthread_create(&(env->philo[i].t_id), NULL, routine, &(env->philo[i]));
		++i;
	}
	env->start_time = get_time();
	env->is_all_created = 1;
	i = 0;
	usleep(1000);
	check_death(env);
	while (i < env->nb_philo)
	{
		if (pthread_join(env->philo[i].t_id, NULL))
			return (clean(env, -1));
		++i;
	}
	return (clean(env, 0));
}
