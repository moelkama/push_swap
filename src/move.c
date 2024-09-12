/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <moelkama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:06:47 by moelkama          #+#    #+#             */
/*   Updated: 2023/04/01 02:08:32 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_push **list, char c)
{
	t_push	*swap;

	if (list && *list && (*list)->next)
	{
		swap = (*list)->next;
		(*list)->next = (*list)->next->next;
		swap->next = *list;
		*list = swap;
	}
	write(1, "s", 1);
	write(1, &c, 1);
	if (c)
		write(1, "\n", 1);
}

void	push(t_push **a, t_push **b, char c)
{
	t_push	*swap;

	if (a && *a && b)
	{
		swap = (*a)->next;
		(*a)->next = *(b);
		*b = *a;
		*a = swap;
		write(1, "p", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	retate(t_push **list, char c)
{
	t_push	*swap;
	t_push	*ptr;

	if (list && *list)
	{
		ptr = *list;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = *list;
		swap = (*list)->next;
		(*list)->next = NULL;
		*list = swap;
		write(1, "r", 1);
		write(1, &c, 1);
		if (c)
			write(1, "\n", 1);
	}
}

void	rretate(t_push **list, char c)
{
	t_push	*ptr;
	t_push	*swap;

	if (list && *list)
	{
		ptr = *list;
		while (ptr->next)
		{
			if (!ptr->next->next)
				swap = ptr;
			ptr = ptr->next;
		}
		ptr->next = *list;
		swap->next = NULL;
		*list = ptr;
	}
	if (c)
	{
		write(1, "rr", 2);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}
