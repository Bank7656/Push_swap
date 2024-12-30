/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:17:09 by thacharo          #+#    #+#             */
/*   Updated: 2024/12/26 00:29:59 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push_stack(t_node **head_dest, t_node **tail_dest, t_node **head_src);

void   push(t_data **data, char *operation)
{
    if (ft_strncmp(operation, "pa", -1) == 0)
        push_stack(&((*data) -> head_a), &((*data) -> tail_a), &((*data) -> head_b));
    else if (ft_strncmp(operation, "pb", -1) == 0)
        push_stack(&((*data) -> head_b), &((*data) -> tail_b),  &((*data) -> head_a));
    else
        return ;
    ft_putstr_fd(operation, 1);
    ft_putstr_fd("\n", 1);
    // ft_get_stack_length(data);
    return ;
} 

static void push_stack(t_node **head_dest, t_node **tail_dest, t_node **head_src)
{
    t_node *tmp_stack;

    if ((*head_src) == NULL)
        return ;
    tmp_stack = *head_src;
    if ((*head_src) -> next != NULL)
    {
        *head_src = (*head_src) -> next;
        tmp_stack -> next = NULL;
        (*head_src) -> prev = NULL;
    }
    else
        *head_src = NULL;
    if ((*head_dest) == NULL)
    {
        *head_dest = tmp_stack;
        *tail_dest = tmp_stack;
    }
    else
    {
        tmp_stack -> next = *head_dest;
        (*head_dest) -> prev = tmp_stack;
        *head_dest = tmp_stack;
    }
}