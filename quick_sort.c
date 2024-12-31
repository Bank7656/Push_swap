/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:04:47 by thacharo          #+#    #+#             */
/*   Updated: 2024/12/31 01:24:05 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_count_moves_a(t_data **data);
void	ft_count_moves_b(t_data **data);
void	ft_check_index_a(t_data **data, t_node *node_b);
void	ft_sum_moves(t_data **data);
void	ft_find_diff(t_data **data);
void	ft_reset_count_moves(t_data **data);

void	update_stack(t_data **data);

t_node	*find_candidate(t_data **data);
void	rotate_operation(t_data **data, t_node *node);
int	ft_check_median(t_node *head, int median);
static void	divide_stack(t_data **data, int lower_bound, int upper_bound);
static void	conquer_stack(t_data **data);

void	quick_sort(t_data **data)
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

void	update_stack(t_data **data)
{
	ft_reset_count_moves(data);
	ft_get_stack_length(data);
	ft_find_diff(data);
	ft_count_moves_a(data);
	ft_count_moves_b(data);
	ft_sum_moves(data);
}

static void 	conquer_stack(t_data **data)
{
	t_node	*candidate;

	while ((*data) -> stack_b.length > 0)
	{
		update_stack(data);
		candidate = find_candidate(data);
		if (candidate == NULL)
			break ;
		rotate_operation(data, candidate);
		push(data, "pa");
	}
	while (!(ft_is_sorted(*data)))
		reverse_rotate(data, "rra");
	return ;
}

void	rotate_operation(t_data **data, t_node *node)
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

t_node    *find_candidate(t_data **data)
{
	t_node *tmp;
	t_node *trav1;
	t_node *trav2;
	
	if ((*data) -> head_b == NULL)
		return (NULL);
	trav1 = (*data) -> head_b;
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

void    ft_reset_count_moves(t_data **data)
{
	t_node *tmp_a;
	t_node *tmp_b;

	tmp_a = (*data) -> head_a;
	tmp_b = (*data) -> head_b;
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

void    ft_find_diff(t_data **data)
{
	t_node *tmp1;
	t_node *tmp2;

	tmp2 = (*data) -> head_b;
	while (tmp2 != NULL)
	{
		tmp1 = (*data) -> head_a;
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

void    ft_sum_moves(t_data **data)
{
	t_node *trav;

	trav = (*data) -> head_b;
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

void    ft_count_moves_a(t_data **data)
{
	t_node *trav;

	trav = (*data) -> head_b;
	while (trav != NULL)
	{
		ft_check_index_a(data, trav);
		trav = trav -> next;
	}
	return ;
}

void    ft_check_index_a(t_data **data, t_node *node_b)
{
	int     i;
	int     midpoint;
	t_node *tmp;
	t_node *trav;

	i = 0;
	midpoint = ((*data) -> stack_a.length) / 2;
	
	tmp = (*data) -> head_a;
	node_b -> ra_count = 0;
	while (tmp != NULL  && i <= midpoint)
	{
		if (tmp -> index < node_b -> index)
			node_b -> ra_count++;
		if (tmp -> index == (node_b -> index) - 1)
			break;
		tmp = tmp -> next;
		i++;
	}
	if (node_b -> ra_count > 0)
		return ;
	tmp = (*data) -> tail_a;
	node_b -> rra_count = 0;
	i = 0;
	while (tmp != NULL && i < midpoint)
	{
		if ((tmp -> index) == (*data) -> stack_a.max)
			return ;
		if ((tmp -> index) > (node_b -> index))
		{
			node_b -> rra_count++;
		}
		tmp = tmp -> prev;
		i++;    
	}
	return ;
}

void    ft_count_moves_b(t_data **data)
{
	int i;
	int midpoint;
	t_node *trav1;
	t_node *trav2;

	i = 0;
	if ((*data) -> head_b == NULL)
		return ;
	trav1 = (*data) -> head_b;
	trav2 = (*data) -> tail_b;
	midpoint = ((*data) -> stack_b.length) / 2;
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

static void    divide_stack(t_data **data, int lower_bound, int upper_bound)
{
	int median;

	if ((*data) -> stack_a.length <= 3)
		return;
	median = (lower_bound + upper_bound) / 2;
	while (ft_check_median((*data) -> head_a, median))
	{
		if ((*data) -> head_a -> index <= median)
			push(data, "pb");
		if ((*data) -> head_b != NULL)
		{
			if (((*data) -> head_a -> index > median) &&
			((*data) -> head_b -> index <= (lower_bound + median) / 2))
				rotate(data, "rr");
			else if ((*data) -> head_a -> index > median)
				rotate(data, "ra");
			else if (((*data) -> head_b -> index <= (lower_bound + median) / 2))
				rotate(data, "rb");
		}
		else if ((*data) -> head_a -> index > median)
			rotate(data, "ra");
	}
	ft_get_stack_length(data);
	divide_stack(data, median, upper_bound);
}

int	ft_check_median(t_node *head, int median)
{
	t_node *tmp1;
	
	tmp1 = head;
	while (tmp1 != NULL)
	{
		if (tmp1 -> index < median)
			return (1);       
		tmp1 = tmp1 -> next;
	}
	return (0);
}