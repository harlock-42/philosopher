/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tallaire <tallaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:43:34 by tallaire          #+#    #+#             */
/*   Updated: 2021/09/27 13:24:08 by tallaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	lst_size(t_list *list)
{
	size_t	size;
	t_list	*tmp;

	size = 0;
	tmp = list;
	while (list)
	{
		size++;
		list = list->next;
	}
	list = tmp;
	return (size);
}
