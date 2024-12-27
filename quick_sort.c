/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:04:47 by thacharo          #+#    #+#             */
/*   Updated: 2024/12/27 20:17:16 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void     conquer_stack(t_data **data)
{
    int i;
    int head_a_count_len;
    int tail_a_count_len;
    int head_b_count_len;
    int tail_b_count_len;
    t_node *tmp1;
    t_node *tmp2;
    
    
    while ((*data) -> stack_b.length > 0)
    {
        head_a_count_len = 0;        
        head_b_count_len = 0;
        tail_a_count_len = 0;    
        tail_b_count_len = 0;
        tmp1 = (*data) -> head_b;
        tmp2 = (*data) -> tail_b;
        while (tmp1 != NULL)
        {
            if (tmp1 -> index == (*data) -> head_a -> index - 1)
                break;
            tmp1 = tmp1 -> next;
            head_b_count_len++;
        }
        // ft_printf("Head_b: %i\n", head_b_count_len);
        while (tmp2 != NULL)
        {
            if (tmp2 -> index == (*data) -> head_a -> index - 1)
                break;
            tmp2 = tmp2 -> prev;
            tail_b_count_len++;
        }
        // ft_printf("Tail_b: %i\n", tail_b_count_len);
        if (tail_b_count_len > head_b_count_len)
        {
            i = -1;
            while (++i < head_b_count_len)
                rotate(data, "rb");
        }
        else
        {
            i = -1;
            while (++i <= tail_b_count_len)
                reverse_rotate(data, "rrb");
        }
        push(data, "pa");
        ft_get_stack_length(data);
        // exit(0);
        // ft_printf("%i %i ", (*data) -> stack_a.length, (*data) -> stack_b.length);
    }

    

    
    return ;
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
            ((*data) -> head_b -> index > (lower_bound + median) / 2))
                rotate(data, "rr");
            else if ((*data) -> head_a -> index > median)
                rotate(data, "ra");
            else if (((*data) -> head_b -> index > (lower_bound + median) / 2))
                rotate(data, "rb");
            if ((*data) -> head_b -> next != NULL)
            {
                if (((*data) -> head_b -> index < (*data) -> head_b -> next -> index) && 
                ((*data) -> head_a -> index > median) && 
                ((*data) -> head_a -> index > (*data) -> head_a -> next -> index))
                    swap(data, "ss");
                if ((*data) -> head_b -> index < (*data) -> head_b -> next -> index)
                    swap(data, "sb");
            }
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