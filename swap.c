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
    t_node *tmp;
    
    if (*head == NULL)
        return ;
    tmp = *head;
    (*head) = (*head) -> next;
    (*head) -> prev = NULL;
    tmp -> next = (*head) -> next;
    (*head) -> next -> prev = tmp;
    (*head) -> next = tmp;
    tmp -> prev = (*head);
}