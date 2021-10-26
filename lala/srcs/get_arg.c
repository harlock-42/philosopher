/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:55:57 by tallaire          #+#    #+#             */
/*   Updated: 2021/10/15 17:18:21 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_arg(t_env *env, char **arg)
{
	unsigned int		nb;

	nb = ft_atoi(arg[0]);
	env->nb_philo = nb;
	env->time_to_die = ft_atoi(arg[1]);
	env->time_to_eat = ft_atoi(arg[2]);
	env->time_to_sleep = ft_atoi(arg[3]);
	if (arg[4] != NULL)
		env->nb_meal = ft_atoi(arg[4]);
	else
		env->nb_meal = 4294967295;
	return (0);
}
