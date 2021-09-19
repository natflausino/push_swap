/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 22:45:04 by nbarreir          #+#    #+#             */
/*   Updated: 2021/09/18 22:45:06 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*merge_sorted_duplicate(t_list *first, t_list *second)
{
	if (!first)
		return (second);
	if (!second)
		return (first);
	if (first->number < second->number)
	{
		first->next = merge_sorted_duplicate(first->next, second);
		return (first);
	}
	else
	{
		second->next = merge_sorted_duplicate(first, second->next);
		return (second);
	}
}

t_list	*find_middle(t_list *stack)
{
	t_list	*future;
	t_list	*present;

	future = stack;
	present = stack;
	while (future->next && future->next->next)
	{
		future = future->next->next;
		present = present->next;
	}
	future = present->next;
	present->next = 0;
	return (future);
}

void	sort_duplicate(t_list **duplicate)
{
	t_list	*first;
	t_list	*second;

	first = *duplicate;
	if (!first || !first->next)
		return ;
	second = find_middle(first);
	sort_duplicate(&first);
	sort_duplicate(&second);
	*duplicate = merge_sorted_duplicate(first, second);
}

int	index_counter(t_list *stack_a, t_list *tmp)
{
	t_list	*duplicate;
	int		min_ind;
	int		max_ind;

	duplicate = ft_lstduplicate(stack_a);
	sort_duplicate(&duplicate);
	min_ind = equal_value(duplicate, tmp->number);
	max_ind = equal_value(duplicate, tmp->next->number);
	ft_lst_free(&duplicate);
	return (max_ind - min_ind + 1);
}
