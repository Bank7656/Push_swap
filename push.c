/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 00:44:38 by thacharo          #+#    #+#             */
/*   Updated: 2024/12/03 12:54:25 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void 	push_stack(t_list **lst_a, t_list **lst_b);

void	push(t_list **lst_a, t_list **lst_b, char *operation)
{
	if (lst_a == NULL && lst_b == NULL)
		return ;
	if (ft_strncmp(operation, "pa", -1))
	{
		push_stack(lst_a, lst_b);	
	}
	else if (ft_strncmp(operation, "pb", -1))
	{
		push_stack(lst_b, lst_a);
	}
	else
		return ;
	ft_printf("%s\n", operation);
}

static void	push_stack(t_list **lst_to, t_list **lst_from)
{
	t_list *top_stack;

	if (*lst_from == NULL)
		return ;
	top_stack = *lst_from;
	*lst_from = (*lst_from) -> next;
	top_stack -> next = NULL;
	if (*lst_to == NULL)
		*lst_to = top_stack;
	else
	{
		top_stack -> next = *lst_to;
		*lst_to = top_stack;
	}
}
