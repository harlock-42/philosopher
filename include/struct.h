/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:21:44 by tallaire          #+#    #+#             */
/*   Updated: 2021/10/06 16:58:20 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

enum		e_bool
{
	YES = 0,
	NO
};

typedef	struct	s_env
{
	unsigned long int	start_time;
	pthread_mutex_t		m_time;
	pthread_mutex_t		m_write;
	pthread_mutex_t		*fork;
	unsigned int		nb_philo;
	unsigned int		time_to_die;
	unsigned int		time_to_eat;
	unsigned int		time_to_sleep;
	unsigned int		nb_meal;
	int					p_id;
	int					is_dead;
	unsigned int		nb_feed;
}				t_env;

typedef	struct	s_philo
{
	int				p_id;
	long 	int		last_meal;
	unsigned	int	nb_eat;
	pthread_t		t_id;
	t_env			*env;
}				t_philo;

#endif