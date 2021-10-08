/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:28:11 by tallaire          #+#    #+#             */
/*   Updated: 2021/10/08 12:41:31 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include "./color.h"
# include "./list.h"
# include "./struct.h"

/*
** SRCS
*/

void				dis_death(t_philo *philo);
void				dis_eat(t_philo *philo);
void				dis_sleep(t_philo *philo);
void				dis_take_fork(t_philo *philo);
void				dis_think(t_philo *philo);
int					get_arg(t_env *env, char **arg);
int					launch_philo(t_env *env);

/*
** UTILS
*/

int					aie(char *str);
int					where_is_c(char c, char *str);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *str);
int					is_uintovf(char *str);
void				ft_usleep(long int time);
void				ft_putnbr_fd(long int n, int fd);
long long int		get_time(void);

#endif
