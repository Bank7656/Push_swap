#include "push_swap.h"

static void    rotate_stack(t_node **head, t_node **tail);

void    rotate(t_data **data, char *operation)
{
    if (ft_strncmp(operation, "ra", -1) == 0)
        rotate_stack(&((*data) -> head_a), &((*data) -> tail_a));
    else if (ft_strncmp(operation, "rb", -1) == 0)
        rotate_stack(&((*data) -> head_b), &((*data) -> tail_b));
    else if (ft_strncmp(operation, "rr", - 1) == 0)
    {
        rotate_stack(&((*data) -> head_a), &((*data) -> tail_a));
        rotate_stack(&((*data) -> head_b), &((*data) -> tail_b));
    }
    else
        return ;
    ft_putstr_fd(operation, 1);
    ft_putstr_fd("\n", 1);
    ft_get_stack_length(data);
    return ;   
}

static void    rotate_stack(t_node **head, t_node **tail)
{
    if (*head == NULL || *tail == NULL)
        return ;
    (*tail) -> next = *head;
    (*head) -> prev = (*tail);
    (*head) = (*head) -> next;
    (*tail) = (*tail) -> next;
    (*head) -> prev = NULL;
    (*tail) -> next = NULL;
}