/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_and_conquer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:04:47 by thacharo          #+#    #+#             */
/*   Updated: 2025/01/02 20:51:26 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_stack(t_data **data);
static void	rotate_operation(t_data **data, t_node *node);
static void	reverse_rotate_operation(t_data **data, t_node *node);
static void	conquer_stack(t_data **data);

void	divide_and_conquer(t_data **data)
{
	int		lower_bound;
	int		upper_bound;
	t_data	*data_ptr;

	data_ptr = *data;
	upper_bound = data_ptr -> stack_a.length;
	lower_bound = 0;
	divide_stack(&data_ptr, lower_bound, upper_bound);
	ft_sort_stack(&data_ptr);
	conquer_stack(&data_ptr);
}

static void	conquer_stack(t_data **data)
{
	t_node	*candidate;

	while ((*data)->stack_b.length > 0)
	{
		update_stack(data);
		candidate = find_candidate(data);
		if (candidate == NULL)
			break ;
		rotate_operation(data, candidate);
		reverse_rotate_operation(data, candidate);
		push(data, "pa");
	}
	while (!(ft_is_sorted(*data)))
		reverse_rotate(data, "rra");
	return ;
}

static void	update_stack(t_data **data)
{
	ft_reset_count_moves(data);
	ft_get_stack_length(data);
	ft_find_diff(data);
	ft_count_moves_a(data);
	ft_count_moves_b(data);
	ft_sum_moves(data);
}

static void	rotate_operation(t_data **data, t_node *node)
{
	while (node -> ra_count > 0 || node -> rb_count > 0)
	{
		if (node -> ra_count > 0 && node -> rb_count > 0)
		{
			rotate(data, "rr");
			node -> ra_count--;
			node -> rb_count--;
		}
		else if (node -> ra_count > 0)
		{
			rotate(data, "ra");
			node -> ra_count--;
		}
		else if (node -> rb_count > 0)
		{
			rotate(data, "rb");
			node -> rb_count--;
		}
	}
}

static void	reverse_rotate_operation(t_data **data, t_node *node)
{
	while (node -> rra_count > 0 || node -> rrb_count > 0)
	{
		if (node -> rra_count > 0 && node -> rrb_count > 0)
		{
			reverse_rotate(data, "rrr");
			node -> rra_count--;
			node -> rrb_count--;
		}
		else if (node -> rra_count > 0)
		{
			reverse_rotate(data, "rra");
			node -> rra_count--;
		}
		else if (node -> rrb_count > 0)
		{
			reverse_rotate(data, "rrb");
			node -> rrb_count--;
		}
	}
}
