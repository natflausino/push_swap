#include "../../include/push_swap.h"

void	reverse_rotate_stack(t_stack **base, t_stack **aux, char *msg)
{
	int		data;
	t_stack	*last_node;

	last_node = ft_stack_last(*base);
	data = last_node->data;
	ft_stack_remove(&last_node);
	ft_stack_add_front(base, ft_stack_new(data));
	if (aux)
	{
		last_node = ft_stack_last(*aux);
		data = last_node->data;
		ft_stack_remove(&last_node);
		ft_stack_add_front(aux, ft_stack_new(data));
	}
	ft_putstr_fd(msg, 1);
}

void	rotate_stack(t_stack **base, t_stack **aux, char *msg)
{
	int	data;

	data = ft_stack_first(*base)->data;
	ft_stack_remove(base);
	ft_stack_add_back(base, ft_stack_new(data));
	if (aux)
	{
		data = ft_stack_first(*aux)->data;
		ft_stack_remove(aux);
		ft_stack_add_back(aux, ft_stack_new(data));
	}
	ft_putstr_fd(msg, 1);
}

void	swap_stack(t_stack *base, t_stack *aux, char *msg)
{
	ft_swap(&(base->data), &(base->next->data));
	if (aux)
		ft_swap(&(aux->data), &(aux->next->data));
	ft_putstr_fd(msg, 1);
}

void	send_min_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = ft_stack_min_value(*stack_a);
	while ((*stack_a)->data != min)
	{
		if ((*stack_a)->data != min && (*stack_a)->next->data != min)
			reverse_rotate_stack(stack_a, 0, "rra\n");
		else
			rotate_stack(stack_a, 0, "ra\n");
	}
	push_stack(stack_a, stack_b, "pb\n");
}

void	push_stack(t_stack **from_stack, t_stack **to_stack, char *msg)
{
	if (!(*from_stack))
		return ;
	ft_stack_add_front(to_stack, ft_stack_new((*from_stack)->data));
	ft_stack_remove(from_stack);
	ft_putstr_fd(msg, 1);
}
