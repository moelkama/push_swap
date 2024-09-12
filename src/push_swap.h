/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelkama <moelkama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 02:09:27 by moelkama          #+#    #+#             */
/*   Updated: 2023/04/01 02:18:08 by moelkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
t_push	*lastnode(t_push *list);
t_push	*is_max(t_push *list);
void	sort1(t_push **a, t_push **b);
void	sort2(t_push **a, t_push **b, int size, int mid);
int		lastismin(t_push *list);
int		max(t_push *list);
int		min(t_push *list);
int		duplicate(t_push *list, int nb);
void	sortindex(t_push *list, int size);
int		listsize(t_push *list);
int		exist(t_push *ptr, int start, int end, int size);
int		half(t_push *list, int to_find);
int		checker(t_push *list);
char	**ft_split(char *str, char c);
void	swap(t_push **list, char c);
void	retate(t_push **list, char c);
void	rretate(t_push **list, char c);
void	push(t_push **list1, t_push **list2, char c);
void	get_numbers(t_push **list, int size, char **arr);
long	ft_atoi(char *str);
char	**ft_free(char **str);
int		ft_strlen(char *str);

#endif
