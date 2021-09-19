/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 22:45:23 by nbarreir          #+#    #+#             */
/*   Updated: 2021/09/18 22:45:24 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	equal_value(t_list *stack, int value)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (stack->number == value)
			return (i);
		stack = stack->next;
		i++;
	}
	return (INT_MIN);
}

int	maximum_value(t_list *stack)
{
	int	value;

	value = stack->number;
	while (stack != NULL)
	{
		if (stack->number > value)
		{
			value = stack->number;
		}
		stack = stack->next;
	}
	return (value);
}

int	minimum_value(t_list *stack)
{
	int		value;
	t_list	*aux;

	aux = stack;
	value = stack->number;
	while (aux != NULL)
	{
		if (aux->number <= value)
		{
			value = aux->number;
		}
		aux = aux->next;
	}
	return (value);
}

void	send_min(t_stack *stack, t_list **stack_x, t_list **stack_y)
{
	int	min_num;

	stack_y = (t_list **)stack_y;
	min_num = minimum_value(*stack_x);
	while ((*stack_x)->number != min_num)
	{
		if ((*stack_x)->next->number != min_num)
			set_reverse_rotate(stack_x, NULL);
		else
			set_rotate(stack_x, NULL);
	}
	set_push(&stack->stack_a, &stack->stack_b, 'b');
}
