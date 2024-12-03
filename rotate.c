/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:22:25 by thacharo          #+#    #+#             */
/*   Updated: 2024/12/02 21:23:32 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_stack(t_list **lst_head, t_list **lst_tail);

void	rotate(t_stack **stack_a, t_stack **stack_b, char *operation)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (!(ft_strncmp(operation, "ra", -1)))
	{
		rotate_stack(&((*stack_a) -> head), &((*stack_a) -> tail));
	}
	else if (!(ft_strncmp(operation, "rb", -1)))
	{
		rotate_stack(&((*stack_b) -> head), &((*stack_b) -> tail));	
	}
	else if (!(ft_strncmp(operation, "rr", -1)))
	{
		rotate_stack(&((*stack_a) -> head), &((*stack_a) -> tail));
		rotate_stack(&((*stack_b) -> head), &((*stack_b) -> tail));	
	}
	else
		return ;
	ft_printf("%s\n", operation);
}

void rotate_stack(t_list **lst_head, t_list **lst_tail)
{
	t_list *top_stack;

	if (lst_head == NULL || lst_tail == NULL)
		return;
	top_stack = *lst_head;
	(*lst_head) = (*lst_head) -> next;
	top_stack -> next = NULL;
	(*lst_tail) -> next = top_stack;
}