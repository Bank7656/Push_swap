/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 23:00:04 by thacharo          #+#    #+#             */
/*   Updated: 2024/12/31 19:26:31 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int    ft_is_sorted(t_data *data);
void    sort_three(t_data **data);
void    sort_five(t_data **data);
static int    find_min_stack(t_data **data);
void    quick_sort(t_data **data);

void    ft_sort_stack(t_data **data)
{
    if ((*data) -> stack_a.length <= 1)
        return ;
    else if (ft_is_sorted(*data))
        return ;
    else if ((*data) -> stack_a.length == 2)
    {
        if ((*data) -> head_a -> index > (*data) -> head_a -> next -> index)
            swap(data, "sa");
    }
    else if ((*data) -> stack_a.length == 3)
        sort_three(data);
    else if ((*data) -> stack_a.length == 5)
        sort_five(data);
    else
        quick_sort(data);
    return ;   
}

void    sort_five(t_data **data)
{
    int i;
    int j;
    int count;
    
    i = -1;    
    while (++i < 2)
    {
        count = find_min_stack(data);
        j = -1;
        if (count >= 3)
        {
            while (++j < ((*data) -> stack_a.length - count))
                reverse_rotate(data, "rra");    
        }
        else
        {
            while (++j < count)
                rotate(data, "ra");
        }
        push(data, "pb");
        (*data) -> stack_a.length--;
    }
    sort_three(data);
    push(data, "pa");
    push(data, "pa");
}

static int    find_min_stack(t_data **data)
{
    int i;
    int count;
    t_node *trav;
    t_node *tmp;
    
    i = 1;
    tmp = (*data) -> head_a;
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

void    sort_three(t_data **data)
{
    int top;
    int middle;
    int bottom;
    
    top = (*data) -> head_a -> index;
    middle = (*data) -> head_a -> next -> index;
    bottom = (*data) -> head_a -> next -> next -> index;
	if ((top < middle && middle > bottom && top < bottom) ||
		(top > middle && middle < bottom && top < bottom) ||
		(top > middle && middle > bottom && top > bottom))
		swap(data, "sa");
	if ((top < middle && middle > bottom && top < bottom) || 
		(top > middle && middle < bottom && top > bottom))
		rotate(data, "ra");
	if (((top < middle && middle > bottom && top > bottom) ||
		(top > middle && middle > bottom && top > bottom)))
		reverse_rotate(data, "rra");
	return ;
}

int    ft_is_sorted(t_data *data)
{
    t_node *tmp_node1;
    t_node *tmp_node2;

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
    return(1);
}