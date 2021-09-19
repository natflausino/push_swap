/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 22:45:16 by nbarreir          #+#    #+#             */
/*   Updated: 2021/09/18 22:45:18 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	split_block_aux(t_list *lst, t_list **stack_a, t_list *tmp, int first)
{
	int	count;
	int	last;

	count = 0;
	while (lst)
	{
		count++;
		if (lst->number >= tmp->number
			&& lst->number <= tmp->next->number)
			last = count;
		lst = lst->next;
	}
	if (first <= ft_lstsize(*stack_a) - last + 1)
		while (first--)
			set_rotate(stack_a, 0);
	else
		while (ft_lstsize(*stack_a) + 1 - last++)
			set_reverse_rotate(stack_a, 0);
}

void	split_block(t_list **stack_a, t_list **stack_b, t_list *tmp)
{
	t_list	*lst;
	int		block_size;
	int		first;

	block_size = tmp->next->number - tmp->number + 1;
	while (ft_lstsize(*stack_b) < block_size)
	{
		first = 0;
		lst = *stack_a;
		while (lst)
		{
			if (lst->number >= tmp->number
				&& lst->number <= tmp->next->number)
				break ;
			first++;
			lst = lst->next;
		}
		lst = *stack_a;
		split_block_aux(lst, stack_a, tmp, first);
		set_push(stack_a, stack_b, 'b');
	}
}

int	find_position(t_list *stack, int position)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (i == position)
			return (stack->number);
		stack = stack->next;
		i++;
	}
	return (INT_MIN);
}

void	define_block(t_list *stack_a, t_list **tmp, int flag)
{
	t_list	*duplicate;
	int		min_ind;
	int		max_ind;
	int		new;

	duplicate = ft_lstduplicate(stack_a);
	sort_duplicate(&duplicate);
	if (flag)
	{
		min_ind = equal_value(duplicate, (*tmp)->number);
		max_ind = equal_value(duplicate, (*tmp)->next->number);
		new = find_position(duplicate, ((max_ind - min_ind) / 2 + min_ind));
	}
	else
		new = find_position(duplicate, (ft_lstsize(duplicate) / 2));
	ft_lstadd_front(tmp, ft_lstnew(new));
	sort_duplicate(tmp);
	ft_lst_free(&duplicate);
}
