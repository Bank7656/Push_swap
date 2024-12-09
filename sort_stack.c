/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:00:16 by thacharo          #+#    #+#             */
/*   Updated: 2024/12/07 00:16:06 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_swap(t_list **lst_a, t_list **lst_b);
void	sort_three_stack(t_stack **stack_a, t_stack **stack_b);

void ft_sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_list *lst_a;
	t_list *lst_b;

	lst_a = (*stack_a) -> head;
	lst_b = (*stack_b) -> head;
	if ((*stack_a) -> length == 2)
		check_swap(&lst_a, &lst_b);
	else if ((*stack_a) -> length == 3)
		sort_three_stack(stack_a, stack_b);
}

void	sort_three_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	top;
	int	middle;
	int	bottom;
	t_list *lst_a;
	t_list *lst_b;

	lst_a = (*stack_a) -> head;
	lst_b = (*stack_b) -> head;
	top = ((t_data *)((lst_a) -> content)) -> index;
	middle = ((t_data *)((lst_a) -> next -> content)) -> index;
	bottom = ((t_data *)((lst_a) -> next -> next -> content)) -> index;
	if ((top < middle && middle > bottom && top < bottom) ||
		(top > middle && middle < bottom && top < bottom) ||
		(top > middle && middle > bottom && top > bottom))
		swap(&lst_a, &lst_b, "sa");
	if ((top < middle && middle > bottom && top < bottom) || 
		(top > middle && middle < bottom && top > bottom))
		rotate(stack_a, stack_b, "ra");
	if (((top < middle && middle > bottom && top > bottom) ||
		(top > middle && middle > bottom && top > bottom)))
		reverse_rotate(stack_a, stack_b, "rra");
	return ;
}

void check_swap(t_list **lst_a, t_list **lst_b)
{
	t_data *top;
	t_data *bottom;

	top = ((t_data *)((*lst_a) -> content));
	bottom = ((t_data *)((*lst_a) -> next -> content));
	if (top -> number > bottom -> number)
		swap(lst_a, lst_b, "sa");
}