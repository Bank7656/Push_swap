/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 19:33:08 by thacharo          #+#    #+#             */
/*   Updated: 2025/01/02 19:45:59 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_median(t_node *head, int median);
static void	ft_check_rotate(t_data **data, int lower_bound, int median);

void	divide_stack(t_data **data, int lower_bound, int upper_bound)
{
	int	median;

	if ((*data)->stack_a.length <= 3)
		return ;
	median = (lower_bound + upper_bound) / 2;
	while (ft_check_median((*data)->head_a, median))
	{
		if ((*data)->head_a->index <= median)
			push(data, "pb");
		if ((*data)->head_b != NULL)
			ft_check_rotate(data, lower_bound, median);
		else if ((*data)->head_a->index > median)
			rotate(data, "ra");
	}
	ft_get_stack_length(data);
	divide_stack(data, median, upper_bound);
}

static void	ft_check_rotate(t_data **data, int lower_bound, int median)
{
	if (((*data)->head_a->index > median)
		&& ((*data)->head_b->index <= (lower_bound + median) / 2))
		rotate(data, "rr");
	else if ((*data)->head_a->index > median)
		rotate(data, "ra");
	else if (((*data)->head_b->index <= (lower_bound + median) / 2))
		rotate(data, "rb");
}

static int	ft_check_median(t_node *head, int median)
{
	t_node	*tmp1;

	tmp1 = head;
	while (tmp1 != NULL)
	{
		if (tmp1 -> index < median)
			return (1);
		tmp1 = tmp1 -> next;
	}
	return (0);
}
