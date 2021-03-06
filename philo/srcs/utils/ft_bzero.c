/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:11:36 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/27 14:13:46 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*buff;

	buff = (char *)s;
	i = 0;
	if (n != 0)
	{
		while (i < n)
		{
			*(buff + i) = '\0';
			i++;
		}
	}
}
