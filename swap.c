#include "push_swap.h"

static void    swap_stack(t_node **head);

void    swap(t_data **data, char *operation)
{
    if (ft_strncmp(operation, "sa", -1) == 0)
        swap_stack(&((*data) -> head_a));
    else if (ft_strncmp(operation, "sb", -1) == 0)
        swap_stack(&((*data) -> head_b));
    else if (ft_strncmp(operation, "ss", - 1) == 0)
    {
        swap_stack(&((*data) -> head_a));
        swap_stack(&((*data) -> head_b));
    }
    else
        return ;
    ft_putstr_fd(operation, 1);
    ft_putstr_fd("\n", 1);
    return ;
}

static void    swap_stack(t_node **head)
{
    int     tmp_num;
    int     tmp_idx;
    t_node  *first_stack;
    t_node  *second_stack;
    
    if (*head == NULL || (*head) -> next == NULL)
        return ;
    first_stack = (*head);
    second_stack = (*head) -> next;
    tmp_num = first_stack -> number;
    tmp_idx = first_stack -> index;
    first_stack -> number = second_stack -> number;
    first_stack -> index = second_stack -> index;
    second_stack -> number = tmp_num;
    second_stack -> index = tmp_idx;
}