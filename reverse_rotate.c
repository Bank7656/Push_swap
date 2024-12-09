/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:28:24 by thacharo          #+#    #+#             */
/*   Updated: 2024/12/03 14:50:37 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void reverse_rotate_stack(t_list **lst_head, t_list **lst_tail);

void	reverse_rotate(t_stack **stack_a, t_stack **stack_b, char *operation)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (!(ft_strncmp(operation, "rra", -1)))
	{
		reverse_rotate_stack(&((*stack_a) -> head), &((*stack_a) -> tail));
	}
	else if (!(ft_strncmp(operation, "rrb", -1)))
	{
		reverse_rotate_stack(&((*stack_b) -> head), &((*stack_b) -> tail));	
	}
	else if (!(ft_strncmp(operation, "rrr", -1)))
	{
		reverse_rotate_stack(&((*stack_a) -> head), &((*stack_a) -> tail));
		reverse_rotate_stack(&((*stack_b) -> head), &((*stack_b) -> tail));	
	}
	else
		return ;
	ft_printf("%s\n", operation);
}

static void reverse_rotate_stack(t_list **lst_head, t_list **lst_tail)
{
	t_list *trav;

	if (lst_head == NULL || lst_tail == NULL)
		return;

	trav = *lst_head;
	if (trav -> next == NULL)
		return ;
	while (trav -> next -> next != NULL)
		trav = trav -> next;
	trav -> next = NULL;
	(*lst_tail) -> next = (*lst_head);
	(*lst_head) = (*lst_tail);
	(*lst_tail) = trav;
	(*lst_tail) -> next = NULL;
}