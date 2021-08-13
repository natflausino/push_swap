#include "../../include/push_swap.h"

char	**parse_string(int *argc, char **argv)
{
	int	i;

	i = 0;
	if (!(argv[0][0]))
		exit(0);
	argv = ft_split(argv[0], ' ');
	while (argv[i] != NULL)
		i++;
	*argc = i;
	return (argv);
}

void	load_args(char **argv, t_stack **stack_a)
{
	int			i;
	long int	data;
	t_stack		*new_node;

	i = 0;
	while (argv[i])
	{
		if (!ft_str_isnumeric(argv[i]))
			exit_push_swap(*stack_a, 0, 0);
		data = ft_atol(argv[i]);
		if (!ft_isint(data))
			exit_push_swap(*stack_a, 0, 0);
		new_node = ft_stack_new(data);
		if (!new_node)
			exit_push_swap(*stack_a, 0, 0);
		ft_stack_add_back(stack_a, new_node);
		i++;
	}
	if (ft_stack_is_duplicate(*stack_a))
		exit_push_swap(*stack_a, 0, 0);
}

void	exit_push_swap(t_stack *stack_a, t_stack *stack_b, int flag)
{
	if (stack_a)
		ft_stack_clear(&stack_a);
	if (stack_b)
		ft_stack_clear(&stack_b);
	if (!flag)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
