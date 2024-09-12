/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:43:49 by moelkama          #+#    #+#             */
/*   Updated: 2023/04/02 11:43:53 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap(t_push **list)
{
	t_push	*swap;

	if (list && *list && (*list)->next)
	{
		swap = (*list)->next;
		(*list)->next = (*list)->next->next;
		swap->next = *list;
		*list = swap;
	}
}

void	push(t_push **a, t_push **b)
{
	t_push	*swap;

	if (a && *a && b)
	{
		swap = (*a)->next;
		(*a)->next = *(b);
		*b = *a;
		*a = swap;
	}
}

void	retate(t_push **list)
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
	}
}

void	rretate(t_push **list)
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
}
