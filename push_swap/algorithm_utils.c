#include "../../include/push_swap.h"

int	count_index(t_stack *stack_a, t_stack *refs)
{
	t_stack	*duplicate;
	int		max_idx;
	int		min_idx;

	duplicate = ft_stack_duplicate(stack_a);
	ft_stack_sort(&duplicate);
	min_idx = ft_stack_find(duplicate, refs->data);
	max_idx = ft_stack_find(duplicate, refs->next->data);
	ft_stack_clear(&duplicate);
	return (max_idx - min_idx + 1);
}

void	get_new_block(t_stack **refs, t_stack *stack, int flag)
{
	t_stack	*duplicate;
	int		min_idx;
	int		max_idx;
	int		new;

	duplicate = ft_stack_duplicate(stack);
	ft_stack_sort(&duplicate);
	if (flag)
	{
		min_idx = ft_stack_find(duplicate, (*refs)->data);
		max_idx = ft_stack_find(duplicate, (*refs)->next->data);
		new = ft_stack_get(duplicate, ((max_idx - min_idx) / 2 + min_idx + 3));
	}
	else
		new = ft_stack_get(duplicate, ft_stack_size(duplicate) / 2);
	ft_stack_add_front(refs, ft_stack_new(new));
	ft_stack_sort(refs);
	ft_stack_clear(&duplicate);
}

void	split_blocks(t_stack **stack_a, t_stack **stack_b, t_stack *refs)
{
	int	size;
	int	first;

	size = count_index(*stack_a, refs);
	while (ft_stack_size(*stack_b) < size)
	{
		first = moves_to_top(*stack_a, refs);
		while (first--)
			rotate_stack(stack_a, 0, "ra\n");
		push_stack(stack_a, stack_b, "pb\n");
	}
}

void	merge_max_back(t_stack **stack_a, t_stack **stack_b, t_stack *refs)
{
	get_new_block(&refs, *stack_b, 0);
	while (ft_stack_has_bigger(*stack_b, refs->next->data))
	{
		if ((*stack_b)->data == ft_stack_min_value(*stack_b))
		{
			push_stack(stack_b, stack_a, "pa\n");
			if ((*stack_b)->data != ft_stack_min_value(*stack_b)
				&& (*stack_b)->data <= refs->next->data)
				rotate_stack(stack_a, stack_b, "rr\n");
			else
				rotate_stack(stack_a, 0, "ra\n");
		}
		else if ((*stack_b)->data > refs->next->data)
			push_stack(stack_b, stack_a, "pa\n");
		else
			rotate_stack(stack_b, 0, "rb\n");
	}
}

void	merge_sorted(t_stack **stack_a, t_stack **stack_b, t_stack *refs)
{
	t_stack	*duplicate;

	duplicate = ft_stack_duplicate(*stack_b);
	ft_stack_sort(&duplicate);
	while (ft_stack_size(*stack_b))
	{
		if ((*stack_b)->data == duplicate->data)
		{
			push_stack(stack_b, stack_a, "pa\n");
			duplicate = duplicate->next;
			 if (ft_stack_size(*stack_b) && (*stack_b)->data != duplicate->data
				&& (*stack_b)->data != ft_stack_max_value(*stack_b))
				rotate_stack(stack_a, stack_b, "rr\n");
			else
				rotate_stack(stack_a, 0, "ra\n");
		}
		else if ((*stack_b)->data == ft_stack_max_value(*stack_b))
			push_stack(stack_b, stack_a, "pa\n");
		else
			rotate_stack(stack_b, 0, "rb\n");
	}
	while (ft_stack_last(*stack_a)->data != refs->next->data)
		rotate_stack(stack_a, 0, "ra\n");
	refs->next->data = get_next_min(*stack_a, &refs);
	ft_stack_clear(&duplicate);
}
