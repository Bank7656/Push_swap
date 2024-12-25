/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 23:03:44 by thacharo          #+#    #+#             */
/*   Updated: 2024/12/24 00:19:02 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_create_stack(t_data **data)
{
	(*data) = (t_data *)malloc(sizeof(t_data));
	if (*data == NULL)
		close_program(data);
	(*data) -> head_a = NULL;
	(*data) -> head_b = NULL;
	(*data) -> tail_a = NULL;
	(*data) -> tail_b = NULL;
	(*data) -> stack_a.name = 'A';
	(*data) -> stack_b.name = 'B';
	(*data) -> stack_a.length = 0;
	(*data) -> stack_b.length = 0;
	(*data) -> stack_a.median = 0;
	(*data) -> stack_b.median = 0;
}


void    ft_get_stack_length(t_data **data)
{
    t_node *ptr;

    (*data) -> stack_a.length = 0;
    (*data) -> stack_b.length = 0;
    ptr = (*data) -> head_a;
    while (ptr != NULL)
    {
        (*data) -> stack_a.length++;
        ptr = ptr -> next;
    }
    ptr = (*data) -> head_b;
    while (ptr != NULL)
    {
        (*data) -> stack_b.length++;
        ptr = ptr -> next;
    }
}