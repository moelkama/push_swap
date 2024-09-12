/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <moelkama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:33:30 by moelkama          #+#    #+#             */
/*   Updated: 2023/04/02 11:59:11 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "get_next_line_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	applyinstruction2(t_push **a, t_push **b, char *instruction)
{
	if (!ft_strcmp(instruction, "pa\n"))
		push(b, a);
	else if (!ft_strcmp(instruction, "pb\n"))
		push(a, b);
	else if (!ft_strcmp(instruction, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(instruction, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(instruction, "rrr\n"))
		rrr(a, b);
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	applyinstruction(t_push **a, t_push **b, char *instruction)
{
	if (!ft_strcmp(instruction, "ra\n"))
		retate(a);
	else if (!ft_strcmp(instruction, "rb\n"))
		retate(b);
	else if (!ft_strcmp(instruction, "rra\n"))
		rretate(a);
	else if (!ft_strcmp(instruction, "rrb\n"))
		rretate(b);
	else if (!ft_strcmp(instruction, "sa\n"))
		swap(a);
	else if (!ft_strcmp(instruction, "sb\n"))
		swap(b);
	else
		applyinstruction2(a, b, instruction);
}

int	main(int c, char **v)
{
	t_push	*a;
	t_push	*b;
	char	*line;

	if (c > 1)
	{
		a = NULL;
		b = NULL;
		get_numbers(&a, c - 1, v + 1);
		line = get_next_line(0);
		while (line)
		{
			applyinstruction(&a, &b, line);
			free(line);
			line = get_next_line(0);
		}
		if (a && checker(a) && !b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 4);
	}
}
