/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conquer_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 20:08:31 by thacharo          #+#    #+#             */
/*   Updated: 2025/01/02 20:51:00 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reset_count_moves(t_data **data)
{
	t_node	*tmp_a;
	t_node	*tmp_b;

	tmp_a = (*data)->head_a;
	tmp_b = (*data)->head_b;
	while (tmp_a != NULL)
	{
		tmp_a -> ra_count = 0;
		tmp_a -> rb_count = 0;
		tmp_a -> rra_count = 0;
		tmp_a -> rrb_count = 0;
		tmp_a -> moves = 0;
		tmp_a -> diff = 0;
		tmp_a = tmp_a -> next;
	}
	while (tmp_b != NULL)
	{
		tmp_b -> ra_count = 0;
		tmp_b -> rb_count = 0;
		tmp_b -> rra_count = 0;
		tmp_b -> rrb_count = 0;
		tmp_b -> moves = 0;
		tmp_b -> diff = 0;
		tmp_b = tmp_b -> next;
	}
}

void	ft_find_diff(t_data **data)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp2 = (*data)->head_b;
	while (tmp2 != NULL)
	{
		tmp1 = (*data)->head_a;
		tmp2 -> diff = (tmp1 -> index) - (tmp2 -> index);
		while (tmp1 != NULL)
		{
			if ((tmp1 -> index) - (tmp2 -> index) < tmp2 -> diff)
				tmp2 -> diff = (tmp1 -> index) - (tmp2 -> index);
			tmp1 = tmp1 -> next;
		}
		tmp2 = tmp2 -> next;
	}
}

t_node	*find_candidate(t_data **data)
{
	t_node	*tmp;
	t_node	*trav1;
	t_node	*trav2;

	if ((*data)->head_b == NULL)
		return (NULL);
	trav1 = (*data)->head_b;
	tmp = trav1;
	if (tmp -> next == NULL)
		return (tmp);
	trav2 = trav1 -> next;
	while (trav2 != NULL)
	{
		if ((trav2->moves) + (trav2->diff) < (tmp->moves) + (tmp->diff))
			tmp = trav2;
		else if ((trav2->moves) + (trav2->diff) == (tmp->moves) + (tmp->diff))
		{
			if (trav2 -> diff < tmp -> diff)
				tmp = trav2;
		}
		trav2 = trav2 -> next;
	}
	return (tmp);
}

void	ft_sum_moves(t_data **data)
{
	t_node	*trav;

	trav = (*data)->head_b;
	while (trav != NULL)
	{
		if (trav -> ra_count == -1 && trav -> rra_count == -1)
			trav -> moves = -1;
		else
		{
			trav -> moves += trav -> ra_count;
			trav -> moves += trav -> rb_count;
			trav -> moves += trav -> rra_count;
			trav -> moves += trav -> rrb_count;
		}
		trav = trav -> next;
	}
}
