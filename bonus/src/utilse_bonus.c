/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilse_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <moelkama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:01:36 by moelkama          #+#    #+#             */
/*   Updated: 2023/04/02 11:46:59 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
