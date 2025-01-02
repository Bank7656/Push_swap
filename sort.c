/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 23:00:04 by thacharo          #+#    #+#             */
/*   Updated: 2025/01/02 19:37:58 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_is_sorted(t_data *data);
void		sort_three(t_data **data);
void		sort_five(t_data **data);
static int	find_min_stack(t_data **data);

void	ft_sort_stack(t_data **data)
{
	t_data	*data_ptr;

	data_ptr = *data;
	if (data_ptr -> stack_a.length <= 1)
		return ;
	else if (ft_is_sorted(data_ptr))
		return ;
	else if (data_ptr -> stack_a.length == 2)
	{
		if (data_ptr -> head_a -> index > data_ptr -> head_a -> next -> index)
			swap(&data_ptr, "sa");
	}
	else if (data_ptr -> stack_a.length == 3)
		sort_three(&data_ptr);
	else if (data_ptr -> stack_a.length == 5)
		sort_five(&data_ptr);
	else
		divide_and_conquer(&data_ptr);
	return ;
}

void	sort_five(t_data **data)
{
	int		i;
	int		j;
	int		count;

	i = -1;
	while (++i < 2)
	{
		count = find_min_stack(data);
		j = -1;
		if (count >= 3)
		{
			while (++j < ((*data)->stack_a.length - count))
				reverse_rotate(data, "rra");
		}
		else
		{
			while (++j < count)
				rotate(data, "ra");
		}
		push(data, "pb");
		(*data)->stack_a.length--;
	}
	sort_three(data);
	push(data, "pa");
	push(data, "pa");
}

static int	find_min_stack(t_data **data)
{
	int		i;
	int		count;
	t_node	*trav;
	t_node	*tmp;

	i = 1;
	tmp = (*data)->head_a;
	trav = tmp -> next;
	count = -1;
	while (trav != NULL)
	{
		if (tmp -> index > trav -> index)
		{
			count = i;
			tmp = trav;
		}
		trav = trav -> next;
		i++;
	}
	if (count == -1)
		return (0);
	return (count);
}

void	sort_three(t_data **data)
{
	int		top;
	int		middle;
	int		bottom;
	t_data	*data_ptr;

	data_ptr = *data;
	top = data_ptr -> head_a -> index;
	middle = data_ptr -> head_a -> next -> index;
	bottom = data_ptr -> head_a -> next -> next -> index;
	if ((top < middle && middle > bottom && top < bottom)
		|| (top > middle && middle < bottom && top < bottom)
		|| (top > middle && middle > bottom && top > bottom))
		swap(&data_ptr, "sa");
	if ((top < middle && middle > bottom && top < bottom)
		|| (top > middle && middle < bottom && top > bottom))
		rotate(&data_ptr, "ra");
	if ((top < middle && middle > bottom && top > bottom)
		|| (top > middle && middle > bottom && top > bottom))
		reverse_rotate(&data_ptr, "rra");
	return ;
}

int	ft_is_sorted(t_data *data)
{
	t_node	*tmp_node1;
	t_node	*tmp_node2;

	tmp_node1 = data -> head_a;
	while (tmp_node1 != NULL)
	{
		tmp_node2 = tmp_node1 -> next;
		while (tmp_node2 != NULL)
		{
			if (tmp_node1 -> index > tmp_node2 -> index)
				return (0);
			tmp_node2 = tmp_node2 -> next;
		}
		tmp_node1 = tmp_node1 -> next;
	}
	return (1);
}
