/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 22:44:58 by nbarreir          #+#    #+#             */
/*   Updated: 2021/09/18 22:45:00 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_big(t_list **stack_a, t_list **stack_b, t_list **tmp, int len)
{
	if (ft_lstsize(*tmp) == 1)
	{
		ft_lst_free(tmp);
		return ;
	}
	if (index_counter(*stack_a, *tmp) >= 20 && (ft_lstsize(*tmp) == 2))
		define_block(*stack_a, tmp, 1);
	if (!ft_lstsize(*stack_b))
	{
		split_block(stack_a, stack_b, *tmp);
		rotate_to_sort(stack_a, *tmp);
	}
	if (ft_lstsize(*stack_b))
	{
		if (len > 100)
			merge_max_to_a(stack_a, stack_b, *tmp);
		merge_sorted(stack_a, stack_b, *tmp);
	}
	ft_lstclear(tmp);
	sort_big(stack_a, stack_b, tmp, len);
}

void	sort_middle(t_stack *stack)
{
	while (ft_lstsize(stack->stack_a) > 3)
		send_min(stack, &stack->stack_a, &stack->stack_b);
	sort_three(stack);
	while (ft_lstsize(stack->stack_b))
		set_push(&stack->stack_a, &stack->stack_b, 'a');
}

void	sort_three_simple(t_stack *stack, int first, int second, int third)
{
	if (first > second && second < third && third > first)
		set_swap(stack->stack_a, NULL);
	else if (first < second && first > third && second > third)
		set_reverse_rotate(&stack->stack_a, NULL);
	else if (first > second && second < third && third < first)
		set_rotate(&stack->stack_a, NULL);
	else
		return ;
}

void	sort_three(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->stack_a->number;
	second = stack->stack_a->next->number;
	third = stack->stack_a->next->next->number;
	if (first < second && second > third && first < third)
	{
		set_rotate(&stack->stack_a, NULL);
		set_swap(stack->stack_a, NULL);
		set_reverse_rotate(&stack->stack_a, NULL);
	}
	else if (first > second && second > third && third < first)
	{
		set_swap(stack->stack_a, NULL);
		set_reverse_rotate(&stack->stack_a, NULL);
	}
	sort_three_simple(stack, first, second, third);
}

void	set_sort(t_stack *stack)
{
	t_list	*tmp;

	if (stack->len_args == 2)
	{
		if (stack->stack_a->number < stack->stack_a->next->number)
			return ;
		else
			set_swap(stack->stack_a, NULL);
	}
	else if (stack->len_args == 3)
		sort_three(stack);
	else if (!is_stack_sorted(stack->stack_a))
	{
		if (stack->len_args <= 19)
			sort_middle(stack);
		else
		{
			tmp = ft_lstnew(minimum_value(stack->stack_a));
			ft_lstadd_back(&tmp, ft_lstnew(maximum_value(stack->stack_a)));
			sort_big(&stack->stack_a, &stack->stack_b, &tmp, stack->len_args);
		}
	}
}
