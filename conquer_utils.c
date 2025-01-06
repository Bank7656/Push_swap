/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conquer_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:04:39 by thacharo          #+#    #+#             */
/*   Updated: 2025/01/06 13:18:41 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check_index_a_top(t_data **data, t_node *node_b, int midpoint);
static void	ft_check_index_a_bot(t_data **data, t_node *node_b, int midpoint);

void	ft_count_moves_a(t_data **data)
{
	int		midpoint;
	t_node	*trav;

	trav = (*data)->head_b;
	while (trav != NULL)
	{
		midpoint = ((*data)->stack_a.length) / 2;
		ft_check_index_a_top(data, trav, midpoint);
		if (trav -> ra_count == 0)
			ft_check_index_a_bot(data, trav, midpoint);
		trav = trav -> next;
	}
	return ;
}

static void	ft_check_index_a_top(t_data **data, t_node *node_b, int midpoint)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = (*data)->head_a;
	node_b -> ra_count = 0;
	while (tmp != NULL && i <= midpoint)
	{
		if (tmp -> index < node_b -> index)
			node_b -> ra_count++;
		if (tmp -> index == (node_b -> index) - 1)
			break ;
		tmp = tmp -> next;
		i++;
	}
	return ;
}

static void	ft_check_index_a_bot(t_data **data, t_node *node_b, int midpoint)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = (*data)->tail_a;
	node_b -> rra_count = 0;
	while (tmp != NULL && i < midpoint)
	{
		if ((tmp -> index) == (*data)->stack_a.max)
			return ;
		if ((tmp -> index) > (node_b -> index))
			node_b -> rra_count++;
		tmp = tmp -> prev;
		i++;
	}
}

void	ft_count_moves_b(t_data **data)
{
	int		i;
	int		midpoint;
	t_node	*trav1;
	t_node	*trav2;

	i = 0;
	if ((*data)->head_b == NULL)
		return ;
	trav1 = (*data)->head_b;
	trav2 = (*data)->tail_b;
	midpoint = ((*data)->stack_b.length) / 2;
	while (i <= midpoint)
	{
		trav1 -> rb_count = i;
		trav1 = trav1 -> next;
		i++;
	}
	i = 1;
	while (i < midpoint + 1)
	{
		trav2 -> rrb_count = i;
		trav2 = trav2 -> prev;
		i++;
	}
}
