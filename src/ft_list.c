/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <moelkama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 00:27:14 by moelkama          #+#    #+#             */
/*   Updated: 2023/04/01 02:00:28 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push	*ft_lstnew(int content)
{
	t_push	*new;

	new = (t_push *)malloc(sizeof(t_push));
	if (new)
	{
		new->nb = content;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}

t_push	*lastnode(t_push *list)
{
	while (list->next)
		list = list->next;
	return (list);
}

int	listsize(t_push *list)
{
	int	size;

	size = 0;
	while (list)
	{
		list = list->next;
		size++;
	}
	return (size);
}

int	max(t_push *list)
{
	int	n;

	n = list->nb;
	list = list->next;
	while (list)
	{
		if (list->nb > n)
			return (0);
		list = list->next;
	}
	return (1);
}

t_push	*is_max(t_push *list)
{
	t_push	*max;

	max = list;
	while (list)
	{
		if (list->nb > max->nb && list->index == 0)
			max = list;
		else if (max->index != 0 && list->index == 0)
			max = list;
		list = list->next;
	}
	return (max);
}
