/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstduplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 22:44:15 by nbarreir          #+#    #+#             */
/*   Updated: 2021/09/18 22:44:18 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*ft_lstduplicate(t_list *lst)
{
	t_list	*duplicate;
	t_list	*new;

	duplicate = NULL;
	while (lst)
	{
		new = ft_lstnew(lst->number);
		if (!new)
		{
			ft_lst_free(&duplicate);
			return (NULL);
		}
		ft_lstadd_back(&duplicate, new);
		lst = lst->next;
	}
	return (duplicate);
}
