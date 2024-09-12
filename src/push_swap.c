/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <moelkama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:33:01 by moelkama          #+#    #+#             */
/*   Updated: 2023/04/02 17:14:11 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker(t_push *list)
{
	while (list && list->next)
	{
		if (list->nb > list->next->nb)
			return (0);
		list = list->next;
	}
	return (1);
}

void	sortindex(t_push *list, int size)
{
	t_push	*ptr;

	ptr = list;
	while (ptr)
	{
		ptr->index = 0;
		ptr = ptr->next;
	}
	size--;
	while (size >= 0)
		is_max(list)->index = size--;
}

int	main(int c, char **v)
{
	t_push	*a;
	t_push	*b;
	int		size;

	if (c > 1)
	{
		a = NULL;
		b = NULL;
		get_numbers(&a, c - 1, v + 1);
		size = listsize(a);
		sortindex(a, size);
		if (size <= 5 && size > 1)
			sort1(&a, &b);
		else if (size != 1)
			sort2(&a, &b, size, size / 2 - 1);
	}
}
