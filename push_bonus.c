/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:17:09 by thacharo          #+#    #+#             */
/*   Updated: 2025/01/08 03:30:41 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_stack(t_node **headDst, t_node **tailDst, t_node **headSrc);

void	push(t_data **data, char *operation)
{
	if (ft_strncmp(operation, "pa", -1) == 0)
		push_stack(&((*data)->head_a), &((*data)->tail_a), &((*data)->head_b));
	else if (ft_strncmp(operation, "pb", -1) == 0)
		push_stack(&((*data)->head_b), &((*data)->tail_b), &((*data)->head_a));
	else
		return ;
	return ;
}

static void	push_stack(t_node **headDst, t_node **tailDst, t_node **headSrc)
{
	t_node	*tmp_stack;

	if ((*headSrc) == NULL)
		return ;
	tmp_stack = *headSrc;
	if ((*headSrc)->next != NULL)
	{
		*headSrc = (*headSrc)->next;
		tmp_stack -> next = NULL;
		(*headSrc)->prev = NULL;
	}
	else
		*headSrc = NULL;
	if ((*headDst) == NULL)
	{
		*headDst = tmp_stack;
		*tailDst = tmp_stack;
	}
	else
	{
		tmp_stack -> next = *headDst;
		(*headDst)->prev = tmp_stack;
		*headDst = tmp_stack;
	}
}
