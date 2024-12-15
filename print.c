#include "push_swap.h"

static void	ft_print_reverse_stack(t_node *lst);
static void	ft_print_forward_stack(t_node *lst);

void    ft_print_doubly_list(t_node *lst)
{
    t_node *tmp1;
    t_node *tmp2;
    t_node *tmp3;

    tmp1 = lst;
    if (tmp1 -> prev != NULL)
    {
        ft_printf("First previous error\n");
        return ;
    }
    else if (tmp1 -> next == NULL)
    {
        printf("[%d | %d] -> ", tmp1 -> number, tmp1 -> index);
        printf("NULL\n");
        return ;
    }
    tmp2 = tmp1 -> next;
    while (tmp2 != NULL)
    {
        if (tmp1 != tmp2 -> prev)
        {
            ft_print_forward_stack(lst);
            ft_print_reverse_stack(lst);
            return ;
        }
        tmp1 = tmp1 -> next;
        tmp2 = tmp1 -> next;
    }
    tmp3 = lst;
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

static void	ft_print_reverse_stack(t_node *lst)
{
	t_node *last_node;

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

static void	ft_print_forward_stack(t_node *lst)
{
	while (lst != NULL)
	{
		printf("[%d | %d] -> ", lst -> number, lst -> index);
		lst = lst -> next;
	}
	printf("NULL\n");
}

