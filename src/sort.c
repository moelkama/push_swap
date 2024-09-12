/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <moelkama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:04:48 by moelkama          #+#    #+#             */
/*   Updated: 2023/04/02 14:27:09 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exist(t_push *list, int start, int end, int size)
{
	int	ind;
	int	first;
	int	last;

	first = -1;
	last = -1;
	ind = 0;
	while (list)
	{
		if (list->index >= start && list->index <= end && ind < size / 2)
		{
			first = ind;
			break ;
		}
		if (list->index >= start && list->index <= end && ind >= size / 2)
			last = size - ind - 1;
		list = list->next;
		ind++;
	}
	if ((first <= last && first != -1) || (first != -1 && last == -1))
		return (0);
	else if ((last < first && last != -1) || (last != -1 && first == -1))
		return (1);
	return (-1);
}

void	push_to_a(t_push **a, t_push **b, int index, int k)
{
	if (*b && (*b)->index == index)
	{
		push(b, a, 'a');
		index--;
	}
	else if (*a && lastnode(*a)->index == index)
	{
		rretate(a, 'a');
		index--;
		k--;
	}
	else if (*b && (k == 0 || (*b)->index > lastnode(*a)->index))
	{
		push(b, a, 'a');
		retate(a, 'a');
		k++;
	}
	else if (*b && half(*b, index) == 1)
		retate(b, 'b');
	else if (*b && half(*b, index) == 2)
		rretate(b, 'b');
	if (*b || k != 0)
		push_to_a(a, b, index, k);
}

void	push_to_b(t_push **a, t_push**b, int *range, int size)
{
	int	mid;

	mid = size / 2 - 1;
	while (exist(*a, range[0], range[1], size) != -1)
	{
		if ((*a)->index <= range[1] && (*a)->index >= range[0])
		{
			push(a, b, 'b');
			if ((*b)->index < mid && (*b)->next)
				retate(b, 'b');
		}
		else if (exist(*a, range[0], range[1], size) == 1)
			rretate(a, 'a');
		else if (exist(*a, range[0], range[1], size) == 0)
			retate(a, 'a');
	}
}

void	sort1(t_push **a, t_push **b)
{
	if ((min(*a) && !checker(*a)))
		push(a, b, 'b');
	else if (lastismin(*a) && listsize(*a) != 3)
		rretate(a, 'a');
	else if (*a && (*a)->nb > lastnode(*a)->nb)
		retate(a, 'a');
	else if (*a && (*a)->next && (*a)->next->nb < (*a)->nb)
		swap(a, 'a');
	else if (!checker(*a))
		push(a, b, 'b');
	else if (*b && checker(*a))
		push(b, a, 'a');
	if (!checker(*a) || *b)
		sort1(a, b);
}

void	sort2(t_push **a, t_push **b, int size, int mid)
{
	int	range[2];
	int	ofset;

	ofset = 0;
	while (a && *a)
	{
		if (size <= 100)
			ofset += size / 5;
		else
			ofset += size / 25;
		range[0] = mid - ofset;
		if (range[0] < 0)
			range[0] = 0;
		range[1] = mid + ofset;
		if (range[1] >= size)
			range[1] = size - 1;
		push_to_b(a, b, range, size);
	}
	push_to_a(a, b, size - 1, 0);
}
