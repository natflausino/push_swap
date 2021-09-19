/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 22:43:14 by nbarreir          #+#    #+#             */
/*   Updated: 2021/09/18 22:43:18 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				number;
	struct s_list	*next;
}	t_list;
typedef struct s_stack
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		len_args;
}	t_stack;

/*
**PUSH_SWAP
*/
void			verify_args(int argc, char **argv);
int				init_stacks(t_stack *stack, int argc, char **argv);
void			fill_stack_a(t_stack *stack, int argc, char **argv);
int				*replace_numbers(int argc, char **argv);
int				is_stack_sorted(t_list *stack);
void			send_min(t_stack *stack, t_list **stack_x, t_list **stack_y);
int				minimum_value(t_list *stack);
int				maximum_value(t_list *stack);
int				equal_value(t_list *stack, int value);
int				index_counter(t_list *stack_a, t_list *tmp);
void			sort_duplicate(t_list **duplicate);
t_list			*merge_sorted_duplicate(t_list *first, t_list *second);
t_list			*find_middle(t_list *stack);
void			free_stack(t_stack *stack);
void			define_block(t_list *stack_a, t_list **tmp, int flag);
int				find_position(t_list *stack, int position);
void			split_block(t_list **stack_a, t_list **stack_b, t_list *tmp);
void			set_sort(t_stack *stack);
void			sort_three(t_stack *stack);
void			sort_three_simple(t_stack *stack, int first, int second, int third);
void			sort_middle(t_stack *stack);
void			sort_big(t_list **stack_a, t_list **stack_b, t_list **tmp,
					int len);
void			rotate_to_sort(t_list **stack_a, t_list *tmp);
void			merge_max_to_a(t_list **stack_a, t_list **stack_b, t_list *tmp);
void			merge_sorted(t_list **stack_a, t_list **stack_b, t_list *tmp);

/*
** BASIC_MOVEMENTS
*/

void			push(t_list **stack_x, t_list **stack_y);
void			swap(t_list *stack);
void			rotate(t_list **stack);
void			reverse_rotate(t_list **stack);
void			set_push(t_list **stack_a, t_list **stack_b, int c);
void			set_swap(t_list *a, t_list *b);
void			set_rotate(t_list **a, t_list **b);
void			set_reverse_rotate(t_list **a, t_list **b);

/*
**ERROR
*/

void			exit_errors(void);
void			checker_duplicate(char **argv);
void			checker_errors(char **argv, int i);

/*
**UTILS
*/
long long int	ft_atoi(char *str);
int				ft_isdigit(int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
t_list			*ft_lstduplicate(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstnew(int number);
int				ft_lstsize(t_list *lst);
void			ft_lst_free(t_list **lst);
void			ft_lstclear(t_list **lst);

#endif