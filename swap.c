/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:02:16 by thacharo          #+#    #+#             */
/*   Updated: 2024/12/02 18:05:02 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_list **lst);

void	swap(t_list **lst_a, t_list **lst_b, char *operation)
{
	// Only one char is better
	if (!(ft_strncmp(operation, "sa", -1)))
	{
		swap_stack(lst_a);
	}
	else if (!(ft_strncmp(operation, "sb", -1)))
	{
		swap_stack(lst_b);	
	}
	else if (!(ft_strncmp(operation, "ss", -1)))
	{
		swap_stack(lst_a);
		swap_stack(lst_b);
	}
	else
		return ;
	ft_printf("%s\n", operation);
	return ;
}

static void	swap_stack(t_list **lst)
{
	t_data temp_stack;
	t_data *stack_1;
	t_data *stack_2;

	if ((*lst) == NULL || (*lst) -> next == NULL)
		return ;
	stack_1 = (*lst) -> content;
	stack_2 = (*lst) -> next -> content;
	temp_stack = *stack_1;
	*stack_1 = *stack_2;
	*stack_2 = temp_stack;
}