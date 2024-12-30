#include "push_swap.h"

void	ft_print_reverse_stack(t_node *lst);
void	ft_print_forward_stack(t_node *lst);

void    ft_print_doubly_list(t_data *data)
{
    t_data *ptr;
    t_node *tmp1;
    t_node *tmp2;
    t_node *tmp3;

    ptr = data;
    if (ptr -> head_a -> prev != NULL)
    {
        ft_printf("First previous error\n");
        return ;
    }
    if (ptr -> head_a -> next == NULL)
    {
        printf("NULL <- ");
        printf("[%d | %d] -> ", ptr -> head_a -> number, ptr -> head_a -> index);
        printf("NULL\n");
        return ;
    }
    tmp1 = ptr -> head_a; 
    tmp2 = tmp1 -> next;
    while (tmp2 != NULL)
    {
        if (tmp1 != tmp2 -> prev)
        {
            ft_print_forward_stack(data -> head_a);
            ft_print_reverse_stack(data -> head_a);
            return ;
        }
        tmp1 = tmp1 -> next;
        tmp2 = tmp1 -> next;
    }
    tmp3 = data -> head_a;
    printf("NULL <- ");
    while (tmp3 != NULL)
    {
        if (tmp3 -> next != NULL)
            printf("[%d | %d] <-> ", tmp3 -> number, tmp3 -> index);
        else
            printf("[%d | %d] -> ", tmp3 -> number, tmp3 -> index); 
        tmp3 = tmp3 -> next;
    }
    printf("NULL\n");
    // printf("Tail: [%d | %d]\n", data -> tail_a -> number, data -> tail_a -> index);

    if (ptr -> head_b == NULL)
        return ;

    if (ptr -> head_b -> prev != NULL)
    {
        ft_printf("First previous error\n");
        return ;
    }
    if (ptr -> head_b -> next == NULL)
    {
        printf("NULL <- ");
        printf("[%d | %d] -> ", ptr -> head_b -> number, ptr -> head_b -> index);
        printf("NULL\n");
        return ;
    }
    tmp1 = ptr -> head_b; 
    tmp2 = tmp1 -> next;
    while (tmp2 != NULL)
    {
        if (tmp1 != tmp2 -> prev)
        {
            ft_print_forward_stack(data -> head_b);
            ft_print_reverse_stack(data -> head_b);
            return ;
        }
        tmp1 = tmp1 -> next;
        tmp2 = tmp1 -> next;
    }
    tmp3 = data -> head_b;
    printf("NULL <- ");
    while (tmp3 != NULL)
    {
        if (tmp3 -> next != NULL)
            printf("[%d | %d] <-> ", tmp3 -> number, tmp3 -> index);
        else
            printf("[%d | %d] -> ", tmp3 -> number, tmp3 -> index); 
        tmp3 = tmp3 -> next;
    }
    printf("NULL\n");
    return ;
}

void	ft_print_reverse_stack(t_node *lst)
{
	t_node *last_node;

    if (lst == NULL)
    {
       printf("NULL\n"); 
       return ;
    }
	last_node = lst;
	while (last_node -> next != NULL)
		last_node = last_node -> next;
	while (last_node != NULL)
	{
		printf("[%d | %d] -> ", last_node -> number, last_node -> index);
		last_node = last_node -> prev;
	}
	printf("NULL\n");

}

void	ft_print_forward_stack(t_node *lst)
{
	while (lst != NULL)
	{
		ft_printf("[%d | %d] -> ", lst -> number, lst -> index);
		lst = lst -> next;
	}
	ft_printf("NULL\n");
}

