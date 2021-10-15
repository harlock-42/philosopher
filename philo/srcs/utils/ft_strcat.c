/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:33:56 by tallaire          #+#    #+#             */
/*   Updated: 2021/10/15 13:34:08 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*ft_strcat(char *dst, char *src)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (dst && dst[i])
		++i;
	while (src && src[j])
	{
		dst[i + j] = src[j];
		++j;
	}
	dst[i + j] = '\0';
	return (dst);
}
