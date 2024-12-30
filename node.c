#include "push_swap.h"

t_node	*create_node(t_data **data, char *str)
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
        close_program(data);
	new_node -> number =  ft_get_num_list(str);
	new_node -> moves = 0;
    new_node -> ra_count = 0;
    new_node -> rra_count = 0;
    new_node -> rb_count = 0;
    new_node -> rrb_count = 0;    
	new_node -> diff = -1;
	new_node -> next = NULL;
	new_node -> prev = NULL;
	return (new_node);
}