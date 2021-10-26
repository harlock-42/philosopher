/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:56:13 by tallaire          #+#    #+#             */
/*   Updated: 2021/10/15 15:48:39 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philo(t_env *env)
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
		pthread_mutex_init(&(env->fork[i]), NULL);
		env->philo[i].l_fork = i;
		env->philo[i].r_fork = i + 1 % env->nb_philo;
		++i;
	}
	pthread_mutex_init(&env->m_write, NULL);
	pthread_mutex_init(&env->is_mealed, NULL);
}
