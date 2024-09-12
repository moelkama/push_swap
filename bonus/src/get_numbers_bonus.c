/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <moelkama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:50:50 by moelkama          #+#    #+#             */
/*   Updated: 2023/04/02 17:07:49 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

long	returnnbr(char *str, int index, int sign)
{
	unsigned long	nb;
	unsigned long	pow;

	nb = 0;
	pow = 1;
	while (index >= 0)
	{
		nb += (str[index] - 48) * pow;
		pow *= 10;
		if (nb > 2147483647 && sign == 1)
			return (nb * sign);
		else if (nb > 2147483648 && sign == -1)
			return (nb * sign);
		index--;
	}
	return (sign * nb);
}

long	ft_atoi(char *str)
{
	int	index;
	int	sign;

	if (!str)
		return (2147483649);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	index = 0;
	while (str[index] >= '0' && str[index] <= '9')
		index++;
	index--;
	return (returnnbr(str, index, sign));
}

int	is_int(char *nb, long n)
{
	int	i;

	i = 0;
	if (n > 2147483647 || n < -2147483648)
		return (0);
	if (!(nb[0] >= '0' && nb[0] <= '9') && nb[0] != '+' && nb[0] != '-')
		return (0);
	if ((nb[0] == '+' || nb[0] == '-') && !nb[1])
		return (0);
	while (nb[i])
	{
		if (i != 0 && !(nb[i] >= '0' && nb[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	fill(t_push *list, char **arr, int i)
{
	char	**nbs;
	int		nb;
	int		j;

	nbs = ft_split(arr[i], ' ');
	j = 0;
	if (i == 0)
		j++;
	while (nbs[j])
	{
		nb = ft_atoi(nbs[j]);
		if (is_int(nbs[j], nb) && duplicate(list, nb))
			lastnode(list)->next = ft_lstnew(nb);
		else
			break ;
		j++;
	}
	if (!arr[i][0] || nbs[j] || !nbs[0])
	{
		write(2, "Error\n", 6);
		ft_freee(nbs);
		exit(1);
	}
	ft_freee(nbs);
}

void	get_numbers(t_push **list, int size, char **arr)
{
	char	**nbs;
	long	nb;
	int		i;

	nbs = ft_split(arr[0], ' ');
	nb = ft_atoi(nbs[0]);
	if (is_int(nbs[0], nb) && duplicate(*list, nb))
		*list = ft_lstnew(nb);
	else
	{
		write(2, "Error\n", 6);
		ft_freee(nbs);
		exit(1);
	}
	ft_freee(nbs);
	i = 0;
	while (i < size)
		fill(*list, arr, i++);
}
