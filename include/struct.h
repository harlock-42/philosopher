/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:21:44 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/28 18:02:40 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

enum		e_bool
{
	YES = 0,
	NO
};

typedef	struct	s_philo
{
	int			p_id;
	pthread_t	t_id;
}				t_philo;

typedef	struct	s_env
{
	unsigned long int	start_time;
	pthread_mutex_t		m_write;
	unsigned int		nb_philo;
	unsigned int		time_to_die;
	unsigned int		time_to_eat;
	unsigned int		time_to_sleep;
	int					p_id;
	pthread_t			*t_id;
	t_philo				*philo;
}				t_env;

#endif