/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:04:47 by thacharo          #+#    #+#             */
/*   Updated: 2024/12/30 19:28:56 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_count_moves_a(t_data **data);
void    ft_count_moves_b(t_data **data);
void    ft_check_index_a(t_data **data, t_node *node_b);
void    ft_sum_moves(t_data **data);
void    ft_find_diff(t_data **data);
void    ft_reset_count_moves(t_data **data);

void    update_stack(t_data **data);

int     ft_check_median(t_node *head, int median);
static void     divide_stack(t_data **data, int lower_bound, int upper_bound);
static void     conquer_stack(t_data **data);

void    quick_sort(t_data **data)
{
    // int median;
    int lower_bound;
    int upper_bound;

    upper_bound = (*data) -> stack_a.length;
    lower_bound = 0;
    // Divide
    divide_stack(data, lower_bound, upper_bound);
    ft_sort_stack(data);
    conquer_stack(data);
}

void    update_stack(t_data **data)
{
    ft_reset_count_moves(data);
    ft_get_stack_length(data);
    ft_find_diff(data);
    ft_count_moves_a(data);
    ft_count_moves_b(data);
    ft_sum_moves(data);
}

static void     conquer_stack(t_data **data)
{
    t_node *tmp;
    
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "ra");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rra");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "ra");
    update_stack(data);
    rotate(data, "ra");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rra");
    update_stack(data);
    reverse_rotate(data, "rra");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "ra");
    update_stack(data);
    rotate(data, "ra");
    update_stack(data);
    rotate(data, "ra");
    update_stack(data);
    rotate(data, "ra");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rra");
    update_stack(data);
    reverse_rotate(data, "rra");
    update_stack(data);
    reverse_rotate(data, "rra");
    update_stack(data);
    reverse_rotate(data, "rra");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "ra");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrr");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "rr");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "rr");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "rr");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrr");
    update_stack(data);
    reverse_rotate(data, "rrr");
    update_stack(data);
    reverse_rotate(data, "rra");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "ra");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "ra");
    update_stack(data);
    rotate(data, "ra");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "ra");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rra");
    update_stack(data);
    reverse_rotate(data, "rra");
    update_stack(data);
    reverse_rotate(data, "rra");
    update_stack(data);
    reverse_rotate(data, "rra");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "rr");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrr");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "rr");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rra");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);

    reverse_rotate(data, "rrb");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);

    push(data, "pa");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "rr");
    update_stack(data);
    rotate(data, "rr");
    update_stack(data);
    rotate(data, "rr");
    update_stack(data);
    rotate(data, "rr");
    update_stack(data);
    rotate(data, "rr");
    update_stack(data);
    rotate(data, "rr");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "rr");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrr");
    update_stack(data);
    reverse_rotate(data, "rrr");
    update_stack(data);
    reverse_rotate(data, "rrr");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rra");
    update_stack(data);
    reverse_rotate(data, "rra");
    update_stack(data);
    reverse_rotate(data, "rra");
    update_stack(data);
    reverse_rotate(data, "rra");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "ra");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrr");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "rr");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "rr");
    update_stack(data);
    rotate(data, "rr");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rra");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rra");
    update_stack(data);
    reverse_rotate(data, "rra");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "rr");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "rr");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrr");
    update_stack(data);
    reverse_rotate(data, "rra");
    update_stack(data);

    push(data, "pa");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "rb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    rotate(data, "ra");
    update_stack(data);
    rotate(data, "ra");
    update_stack(data);
    rotate(data, "ra");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrr");
    update_stack(data);
    reverse_rotate(data, "rra");
    update_stack(data);
    reverse_rotate(data, "rra");
    update_stack(data);    
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    reverse_rotate(data, "rrb");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    push(data, "pa");
    update_stack(data);
    push(data, "pa");
    update_stack(data);



    
    
    // tmp = (*data) -> head_a;
    // while (tmp != NULL)
    // {
    //     ft_printf("Stack A\t");
    //     ft_printf("%i, %i, %i, %i, %i, diff: %i, sum: %i\n", tmp -> index, tmp -> ra_count, tmp -> rra_count, tmp -> rb_count, tmp -> rrb_count, tmp -> diff, tmp -> moves + tmp -> diff);
    //     tmp = tmp -> next;
    // }

    // ft_printf("\n");
    // tmp = (*data) -> head_b;
    // while (tmp != NULL)
    // {
    //     ft_printf("Stack B\t");
    //     ft_printf("%i, %i, %i, %i, %i, diff: %i, sum: %i\n", tmp -> index, tmp -> ra_count, tmp -> rra_count, tmp -> rb_count, tmp -> rrb_count, tmp -> diff, tmp -> moves + tmp -> diff);
    //     tmp = tmp -> next;
    // }
    return ;
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
    // node_b -> rra_count = 0;
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
            // if ((*data) -> head_b -> next != NULL)
            // {
            //     if (((*data) -> head_b -> index < (*data) -> head_b -> next -> index) && 
            //     ((*data) -> head_a -> index > median) && 
            //     ((*data) -> head_a -> index > (*data) -> head_a -> next -> index))
            //         swap(data, "ss");
            //     if ((*data) -> head_b -> index < (*data) -> head_b -> next -> index)
            //         swap(data, "sb");
            // }
            // if ((*data) -> tail_b -> index > (*data) -> head_b -> index)
            //     rotate(data, "rb");
        }
        else if ((*data) -> head_a -> index > median)
            rotate(data, "ra");
    }
    // Update length
    ft_get_stack_length(data);
    divide_stack(data, median, upper_bound);
}

int     ft_check_median(t_node *head, int median)
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