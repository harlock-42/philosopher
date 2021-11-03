/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_uintovf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:33:06 by tallaire          #+#    #+#             */
/*   Updated: 2021/11/03 14:02:39 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_uintovf(char *str)
{
	int		size;
	int		diff;
	int		i;

	i = 0;
	while (str[i] == '0')
		++i;
	size = ft_strlen(str) - i;
	diff = 0;
	if (size > 10)
		return (YES);
	if (size == 10)
		diff = ft_strcmp(str, "4294967295");
	if (diff > 0)
		return (YES);
	return (NO);
}
