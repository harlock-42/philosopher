/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:21:44 by tallaire          #+#    #+#             */
/*   Updated: 2021/10/28 11:27:00 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

enum		e_bool
{
	YES = 0,
	NO
};

typedef struct s_philo
{
	int					p_id;
	int					has_eaten;
	long long int		last_meal;
	long long int		start_time;
	int					l_fork;
	int					r_fork;
	unsigned int		nb_eat;
	int					is_feed;
	pthread_t			t_id;
	pthread_mutex_t		m_last_meal;
	pthread_mutex_t		m_nb_meal;
	pthread_mutex_t		m_undertaker;
	struct s_env		*env;
}				t_philo;

typedef struct s_env
{
	pthread_mutex_t			is_mealed;
	pthread_mutex_t			m_write;
	pthread_mutex_t			fork[200];
	pthread_mutex_t			m_undertaker;
	unsigned int			nb_philo;
	long long int			time_to_die;
	unsigned int			time_to_eat;
	unsigned int			time_to_sleep;
	unsigned int			nb_meal;
	long long int			start_time;
	int						p_id;
	int						is_dead;
	int						is_all_created;
	unsigned int			nb_feed;
	struct s_philo			philo[200];
}				t_env;

#endif
