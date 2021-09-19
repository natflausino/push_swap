/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 22:45:11 by nbarreir          #+#    #+#             */
/*   Updated: 2021/09/18 22:45:12 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	merge_sorted_aux(t_list *lst, int count, int num)
{
	while (lst)
	{
		if (lst->number == num)
			break ;
		count++;
		lst = lst->next;
	}
	return (count);
}

void	merge_sorted(t_list **stack_a, t_list **stack_b, t_list *tmp)
{
	t_list	*lst;
	int		count;
	int		num;

	num = tmp->number;
	while (ft_lstsize(*stack_b))
	{
		count = 0;
		lst = *stack_b;
		count = merge_sorted_aux(lst, count, num);
		if (count <= ft_lstsize(*stack_b) - count)
			while (count--)
				set_rotate(0, stack_b);
		else
			while (ft_lstsize(*stack_b) - 1 - count++ >= 0)
				set_reverse_rotate(0, stack_b);
		set_push(stack_a, stack_b, 'a');
		set_rotate(stack_a, 0);
		num++;
	}
}

void	merge_max_to_a(t_list **stack_a, t_list **stack_b, t_list *tmp)
{
	int		b_middle;
	t_list	*stack_middle;

	stack_middle = tmp;
	b_middle = (ft_lstsize(*stack_b) / 2);
	if (ft_lstsize(*stack_b) < 20)
	{
		return ;
	}
	else
		define_block(*stack_b, &stack_middle, 0);
	while (ft_lstsize(*stack_b) > b_middle)
	{
		if ((*stack_b)->number >= stack_middle->next->number)
		{
			set_push(stack_a, stack_b, 'a');
		}
		set_rotate(0, stack_b);
	}
	merge_max_to_a(stack_a, stack_b, stack_middle);
}

void	rotate_to_sort(t_list **stack_a, t_list *tmp)
{
	t_list	*duplicate;
	int		number;
	int		index;

	duplicate = ft_lstduplicate(*stack_a);
	ft_lstadd_front(&duplicate, ft_lstnew(tmp->number));
	sort_duplicate(&duplicate);
	number = find_position(duplicate, equal_value(duplicate, tmp->number) - 1);
	ft_lst_free(&duplicate);
	index = equal_value(*stack_a, number);
	if (number == INT_MIN || index == INT_MIN)
		return ;
	if (index <= ft_lstsize(*stack_a) / 2)
	{
		while (ft_lstlast(*stack_a)->number != number)
			set_rotate(stack_a, NULL);
	}
	else
	{
		while (ft_lstlast(*stack_a)->number != number)
			set_reverse_rotate(stack_a, NULL);
	}
}
