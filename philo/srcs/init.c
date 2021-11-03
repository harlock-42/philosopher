/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:56:13 by tallaire          #+#    #+#             */
/*   Updated: 2021/11/03 14:37:48 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	int	init_mutex_philo(t_env *env, int i)
{
	if (pthread_mutex_init(&(env->philo[i].m_last_meal), NULL))
		return (-1);
	if (pthread_mutex_init(&(env->philo[i].m_nb_meal), NULL))
		return (-1);
	if (pthread_mutex_init(&(env->philo[i].m_undertaker), NULL))
		return (-1);
	return (0);
}

static	int	init_mutex_env(t_env *env)
{
	if (pthread_mutex_init(&env->m_write, NULL))
		return (-1);
	if (pthread_mutex_init(&env->is_mealed, NULL))
		return (-1);
	return (0);
}

int	init_philo(t_env *env)
{
	unsigned int	i;

	i = 0;
	while (i < env->nb_philo)
	{
		env->philo[i].p_id = i;
		env->philo[i].env = env;
		env->philo[i].last_meal = 0;
		env->philo[i].nb_eat = 0;
		env->philo[i].has_eaten = 0;
		env->philo[i].is_feed = 0;
		if (pthread_mutex_init(&(env->fork[i]), NULL))
			return (-1);
		if (init_mutex_philo(env, i))
			return (-1);
		env->philo[i].l_fork = i;
		if (i == env->nb_philo - 1)
			env->philo[i].r_fork = 0;
		else
			env->philo[i].r_fork = i + 1;
		++i;
	}
	if (init_mutex_env(env))
		return (-1);
	return (0);
}
