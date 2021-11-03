/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:53:54 by tallaire          #+#    #+#             */
/*   Updated: 2021/11/03 14:22:19 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	kill_philo(t_env *env, t_philo *philo, int i)
{
	unsigned int	j;

	j = 0;
	pthread_mutex_lock(&(philo->m_undertaker));
	dis_death(philo, philo[i].p_id);
	env->is_dead = 1;
	pthread_mutex_unlock(&(philo->m_undertaker));
	while (j < env->nb_philo)
	{
		pthread_detach(env->philo[j].t_id);
		++j;
	}
}

static	void	check_death(t_env *env)
{
	unsigned int	i;
	t_philo			*philo;

	philo = env->philo;
	while (env->is_dead == 0 && env->nb_feed <= env->nb_philo)
	{
		i = 0;
		while (env->is_dead == 0 && i < env->nb_philo
			&& env->nb_feed <= env->nb_philo)
		{
			pthread_mutex_lock(&(philo[i].m_last_meal));
			if (philo[i].is_feed == 0 && get_time()
				- philo[i].last_meal >= env->time_to_die)
				return (kill_philo(env, philo, i));
			pthread_mutex_unlock(&(philo[i].m_last_meal));
			pthread_mutex_lock(&(philo[i].m_nb_meal));
			if (philo[i].nb_eat >= env->nb_meal)
				++env->nb_feed;
			pthread_mutex_unlock(&(philo[i].m_nb_meal));
			++i;
			usleep(10);
		}
	}
}

static	void	dinner(t_philo *philo)
{
	t_env	*env;

	env = philo->env;
	pthread_mutex_lock(&(env->fork[philo->l_fork]));
	dis_take_fork(philo);
	pthread_mutex_lock(&(env->fork[philo->r_fork]));
	dis_take_fork(philo);
	pthread_mutex_lock(&(philo->m_undertaker));
	pthread_mutex_lock(&(philo->m_last_meal));
	philo->last_meal = get_time();
	pthread_mutex_unlock(&(philo->m_last_meal));
	dis_eat(philo);
	pthread_mutex_lock(&(philo->m_nb_meal));
	++philo->nb_eat;
	pthread_mutex_unlock(&(philo->m_nb_meal));
	ft_usleep(env->time_to_eat);
	pthread_mutex_unlock(&(philo->m_undertaker));
	pthread_mutex_unlock(&(env->fork[philo->r_fork]));
	pthread_mutex_unlock(&(env->fork[philo->l_fork]));
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_env	*env;

	philo = (t_philo *)arg;
	env = philo->env;
	if (philo->p_id % 2 == 1)
		usleep(100000);
	while (philo->nb_eat < env->nb_meal)
	{
		dinner(philo);
		if (env->nb_philo == 1)
			break ;
		dis_sleep(philo);
		ft_usleep(env->time_to_sleep);
		dis_think(philo);
	}
	pthread_exit(arg);
}

int	launch_philo(t_env *env)
{
	unsigned int			i;

	i = 0;
	env->start_time = get_time();
	while (i < env->nb_philo)
	{
		env->philo[i].last_meal = get_time();
		pthread_create(&(env->philo[i].t_id), NULL, routine, &(env->philo[i]));
		++i;
	}
	i = 0;
	usleep(1000);
	check_death(env);
	while (i < env->nb_philo)
	{
		if (pthread_join(env->philo[i].t_id, NULL))
			return (clean(env, 1));
		++i;
	}
	return (clean(env, 0));
}
