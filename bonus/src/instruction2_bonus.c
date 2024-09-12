/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:44:27 by moelkama          #+#    #+#             */
/*   Updated: 2023/04/02 11:44:55 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ss(t_push **a, t_push **b)
{
	swap(a);
	swap(b);
}

void	rr(t_push **a, t_push **b)
{
	retate(a);
	retate(b);
}

void	rrr(t_push **a, t_push **b)
{
	rretate(a);
	rretate(b);
}
