/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 23:00:04 by thacharo          #+#    #+#             */
/*   Updated: 2024/12/24 15:25:22 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int    ft_is_sorted(t_data *data);
void    sort_three(t_data **data);

void    ft_sort_stack(t_data **data)
{
    ft_is_sorted(*data);
    if ((*data) -> stack_a.length == 2)
    {
        if ((*data) -> head_a -> index > (*data) -> head_a -> next -> index)
            swap(data, "sa");
    }
    if ((*data) -> stack_a.length == 3)
        sort_three(data);
    ft_is_sorted(*data);
    return ;   
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
            {
                printf("Not Sorted!!\n");
                return (0);            
            }
            tmp_node2 = tmp_node2 -> next;
        }    
        tmp_node1 = tmp_node1 -> next;
    }
    printf("Sorted!!\n");
    return(1);
}