/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilse.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <moelkama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:01:36 by moelkama          #+#    #+#             */
/*   Updated: 2023/04/02 11:45:50 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	min(t_push *list)
{
	int	n;

	if (list)
	n = list->nb;
	list = list->next;
	while (list)
	{
		if (list->nb < n)
			return (0);
		list = list->next;
	}
	return (1);
}

int	half(t_push *list, int to_find)
{
	int	size;
	int	i;

	size = listsize(list);
	i = 0;
	while (list)
	{
		if (i < size / 2 && list->index == to_find)
			return (1);
		else if (i >= size / 2 && list->index == to_find)
			return (2);
		list = list->next;
		i++;
	}
	return (0);
}

int	lastismin(t_push *list)
{
	t_push	*ptr;
	int		n;

	ptr = list;
	while (ptr->next)
		ptr = ptr->next;
	n = ptr->nb;
	ptr = list;
	while (ptr->next)
	{
		if (ptr->nb < n)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	duplicate(t_push *list, int nb)
{
	while (list)
	{
		if (list->nb == nb)
			return (0);
		list = list->next;
	}
	return (1);
}
