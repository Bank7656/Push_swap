/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:04:47 by thacharo          #+#    #+#             */
/*   Updated: 2024/12/26 17:14:51 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_check_median(t_node *head, int median);

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

void    quick_sort(t_data **data)
{
    int median;
    int lower_bound;
    int upper_bound;

    upper_bound = (*data) -> stack_a.length;
    lower_bound = 0;
    median =  (upper_bound + lower_bound) / 2;
    while (ft_check_median((*data) -> head_a, median))
    {
        if ((*data) -> head_a -> index <= median)
            push(data, "pb");
        if ((*data) -> head_b != NULL)
        {
            if (((*data) -> head_a -> index > median) && ((*data) -> head_b -> index <= (lower_bound + median) / 2))
            {
                rotate(data, "rr");
            }
            else if ((*data) -> head_a -> index > median)
            {
                rotate(data, "ra");
            }
            else if (((*data) -> head_b -> index <= (lower_bound + median) / 2))
            {
                rotate(data, "rb");
            }
            if ((*data) -> head_b -> next != NULL)
            {
                if (((*data) -> head_b -> index < (*data) -> head_b -> next -> index) && ((*data) -> head_a -> index > median) && ((*data) -> head_a -> index > (*data) -> head_a -> next -> index))
                    swap(data, "ss");
                else if ((*data) -> head_b -> index < (*data) -> head_b -> next -> index)
                    swap(data, "sb");
                else if ((*data) -> head_a -> index > median)
                {
                    if ((*data) -> head_a -> index > (*data) -> head_a -> next -> index)
                        swap(data, "sa");
                }
            }
            if ((*data) -> tail_b -> index > (*data) -> head_b -> index)
            {
                rotate(data, "rb");
            }
        }
        else if ((*data) -> head_a -> index > median)
        {
            rotate(data, "ra");
        }
    }
    // divide_stack(data, 0, upper_bound);


    // ft_get_stack_length(data);

    // lower_bound = median;
    // median = (lower_bound + upper_bound) / 2;
    // while (ft_check_median((*data) -> head_a, median))
    // {
    //     if ((*data) -> head_a -> index <= median)
    //         push(data, "pb");
    //     if ((*data) -> head_b != NULL)
    //     {
    //         if (((*data) -> head_a -> index > median) && ((*data) -> head_b -> index <= (lower_bound + median) / 2))
    //         {
    //             rotate(data, "rr");
    //         }
    //         else if ((*data) -> head_a -> index > median)
    //         {
    //             rotate(data, "ra");
    //         }
    //         else if (((*data) -> head_b -> index <= (lower_bound + median) / 2))
    //         {
    //             rotate(data, "rb");
    //         }
    //         if ((*data) -> head_b -> next != NULL)
    //         {
    //             if (((*data) -> head_b -> index < (*data) -> head_b -> next -> index) && ((*data) -> head_a -> index > median) && ((*data) -> head_a -> index > (*data) -> head_a -> next -> index))
    //                 swap(data, "ss");
    //             else if ((*data) -> head_b -> index < (*data) -> head_b -> next -> index)
    //                 swap(data, "sb");
    //             // else if ((*data) -> head_a -> index > median)
    //             // {
    //             //     if ((*data) -> head_a -> index > (*data) -> head_a -> next -> index)
    //             //         swap(data, "sa");
    //             // }
    //         }
    //         if ((*data) -> tail_b -> index > (*data) -> head_b -> index)
    //         {
    //             rotate(data, "rb");
    //         }
    //     }
    //     else if ((*data) -> head_a -> index > median)
    //     {
    //         rotate(data, "ra");
    //     }
    // }

    // int i = 0;
    // while (i < median)
    // {
    //     push(data, "pa");
    //     i++;
    // }
}