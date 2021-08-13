#include "../../include/push_swap.h"

void	sort_small(t_stack **stack_a)
{
	int	max;
	int	min;

	max = ft_stack_max_value(*stack_a);
	min = ft_stack_min_value(*stack_a);
	while (!ft_stack_is_sorted(*stack_a))
	{
		if ((*stack_a)->data != min && (*stack_a)->next->data == max)
			reverse_rotate_stack(stack_a, 0, "rra\n");
		else if ((*stack_a)->data == max && (*stack_a)->next->data == min)
			rotate_stack(stack_a, 0, "ra\n");
		else
			swap_stack(*stack_a, 0, "sa\n");
	}
}

void	sort_medium(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stack_size(*stack_a) > 3)
		send_min_to_b(stack_a, stack_b);
	sort_small(stack_a);
	while (ft_stack_size(*stack_b))
		push_stack(stack_b, stack_a, "pa\n");
}

void	sort_big(t_stack **stack_a, t_stack **stack_b, t_stack **refs, int i)
{
	if (ft_stack_size(*refs) == 1)
	{
		ft_stack_clear(refs);
		return ;
	}
	if (ft_stack_size(*refs) == 2 && count_index(*stack_a, *refs) >= MAX_SIZE)
		get_new_block(refs, *stack_a, 1);
	if (!ft_stack_size(*stack_b))
	{
		split_blocks(stack_a, stack_b, *refs);
		rotate_stack_to_sort(stack_a, *refs);
	}
	if (ft_stack_size(*stack_b) >= MAX_SIZE)
		merge_max_back(stack_a, stack_b, *refs);
	else
	{
		merge_sorted(stack_a, stack_b, *refs);
		ft_stack_remove(refs);
	}
	sort_big(stack_a, stack_b, refs, ++i);
}

int	get_next_min(t_stack *stack_a, t_stack **refs)
{
	t_stack	*duplicate;
	int		position;
	int		min;

	duplicate = ft_stack_duplicate(stack_a);
	ft_stack_sort(&duplicate);
	position = ft_stack_find(duplicate, (*refs)->next->data);
	min = ft_stack_get(duplicate, position);
	if (min == ft_stack_last(duplicate)->data)
	{
		ft_stack_clear(&duplicate);
		return (min);
	}
	else
		min = ft_stack_get(duplicate, position + 1);
	ft_stack_clear(&duplicate);
	return (min);
}

void	rotate_stack_to_sort(t_stack **stack_a, t_stack *refs)
{
	t_stack	*duplicate;
	int		num;
	int		index;

	duplicate = ft_stack_duplicate(*stack_a);
	ft_stack_add_front(&duplicate, ft_stack_new(refs->data));
	ft_stack_sort(&duplicate);
	num = ft_stack_get(duplicate, ft_stack_find(duplicate, refs->data) - 1);
	ft_stack_clear(&duplicate);
	index = ft_stack_find(*stack_a, num);
	if (num == -2147483648 || index == -2147483648)
		return ;
	if (index <= ft_stack_size(*stack_a) / 2)
		while (ft_stack_last(*stack_a)->data != num)
			rotate_stack(stack_a, 0, "ra\n");
	else
		while (ft_stack_last(*stack_a)->data != num)
			reverse_rotate_stack(stack_a, 0, "rra\n");
}
