/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:13:45 by tallaire          #+#    #+#             */
/*   Updated: 2021/11/02 17:26:09 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clean(t_env *env, int ret)
{
	unsigned int	i;

	i = 0;
	if (ret != 0)
	{
		while (i < env->nb_philo)
		{
			pthread_detach(env->philo[i].t_id);
			++i;
		}
	}
	i = 0;
	usleep(500000);
	while (i < env->nb_philo)
	{
		pthread_mutex_destroy(&(env->fork[i]));
		++i;
	}
	pthread_mutex_destroy(&env->m_write);
	return (ret);
}
