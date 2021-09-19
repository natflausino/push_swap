/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 22:45:28 by nbarreir          #+#    #+#             */
/*   Updated: 2021/09/18 22:45:30 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_stack_sorted(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (stack->number > stack->next->number)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	*replace_numbers(int argc, char **argv)
{
	int	*numbers1;
	int	*numbers2;
	int	count;
	int	i;
	int	j;

	numbers1 = malloc((argc) * sizeof(int *));
	numbers2 = malloc((argc) * sizeof(int *));
	i = -1;
	while (++i < argc)
		numbers1[i] = ft_atoi(argv[i]);
	i = -1;
	while (++i < argc)
	{
		j = -1;
		count = 0;
		while (++j < argc)
			if (numbers1[i] > numbers1[j])
				count++;
		numbers2[i] = count + 1;
	}
	free(numbers1);
	return (numbers2);
}

void	fill_stack_a(t_stack *stack, int argc, char **argv)
{
	int		i;
	double	tmp;
	t_list	*numbers;
	int		*nuns;

	nuns = replace_numbers(argc, argv);
	i = 0;
	while (i < stack->len_args)
	{
		numbers = (t_list *)malloc(sizeof(t_list));
		if (!numbers)
			return ;
		tmp = nuns[i];
		numbers->number = tmp;
		numbers->next = NULL;
		ft_lstadd_back(&stack->stack_a, numbers);
		i++;
	}
	free(nuns);
}

int	init_stacks(t_stack *stack, int argc, char **argv)
{
	stack->stack_a = NULL;
	stack->stack_b = NULL;
	stack->len_args = argc;
	fill_stack_a(stack, argc, argv);
	return (0);
}
