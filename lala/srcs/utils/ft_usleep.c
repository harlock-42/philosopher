/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:33:39 by tallaire          #+#    #+#             */
/*   Updated: 2021/10/15 13:33:48 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long int time)
{
	long int	i;
	long int	start;

	start = get_time();
	i = 0;
	while (1)
	{
		i = get_time();
		if ((i - start) >= time)
			break ;
		usleep(50);
	}
}
