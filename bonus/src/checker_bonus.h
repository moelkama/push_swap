/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <moelkama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:09:27 by moelkama          #+#    #+#             */
/*   Updated: 2023/04/02 11:28:46 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <unistd.h>

# include <stdlib.h>

typedef struct s_push
{
	int				nb;
	int				index;
	struct s_push	*next;
}			t_push;

t_push	*lastnode(t_push *list);
t_push	*ft_lstnew(int nb);
void	ss(t_push **a, t_push **b);
void	rr(t_push **a, t_push **b);
void	rrr(t_push **a, t_push **b);
int		duplicate(t_push *list, int nb);
int		checker(t_push *list);
char	**ft_split(char *str, char c);
void	swap(t_push **list);
void	retate(t_push **list);
void	rretate(t_push **list);
void	push(t_push **list1, t_push **list2);
void	get_numbers(t_push **list, int size, char **arr);
long	ft_atoi(char *str);
char	**ft_freee(char **str);
int		ft_strlen(char *str);

#endif
