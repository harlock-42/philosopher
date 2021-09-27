/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:28:11 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/27 16:22:05 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include "./color.h"
# include "./list.h"
# include "./struct.h"

/*
** SRCS
*/

int		get_arg(t_env *env, char **arg);

/*
** UTILS
*/

int		aie(char *str);
int		where_is_c(char c, char *str);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
int		is_uintovf(char *str);

#endif
