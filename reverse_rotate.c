#include "push_swap.h"

static void    reverse_stack(t_node **head, t_node **tail);

void    reverse_rotate(t_data **data, char *operation)
{
    if (ft_strncmp(operation, "rra", -1) == 0)
        reverse_stack(&((*data) -> head_a), &((*data) -> tail_a));
    else if (ft_strncmp(operation, "rrb", -1) == 0)
        reverse_stack(&((*data) -> head_b), &((*data) -> tail_b));
    else if (ft_strncmp(operation, "rrr", - 1) == 0)
    {
        reverse_stack(&((*data) -> head_a), &((*data) -> tail_a));
        reverse_stack(&((*data) -> head_b), &((*data) -> tail_b));
    }
    else
        return ;
    ft_putstr_fd(operation, 1);
    ft_putstr_fd("\n", 1);
    return ;   
}

static void    reverse_stack(t_node **head, t_node **tail)
{
    if (*head == NULL || *tail == NULL)
        return ;
    (*tail) -> next = *head;
    (*head) -> prev = (*tail);
    (*head) = (*head) -> prev;
    (*tail) = (*tail) -> prev;
    (*head) -> prev = NULL;
    (*tail) -> next = NULL;
}