/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:00:03 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/27 13:29:02 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dup;

	i = 0;
	while (*(s1 + i))
		i++;
	dup = (char *)malloc(i + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (*(s1 + i))
	{
		*(dup + i) = *(s1 + i);
		i++;
	}
	*(dup + i) = '\0';
	return (dup);
}
