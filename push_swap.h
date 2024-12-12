#include "libft/libft.h"

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#endif

typedef struct s_node
{
    int number;
    int index;
    struct s_node *next;
    struct s_node *prev;
}   t_node;

typedef struct s_stack
{
    int     length;
    int     median;
    char    *name;
}   t_stack;

typedef struct s_data
{
    t_node *lst_a;
    t_node *lst_b;
    t_stack *stack_a;
    t_stack *stack_b;
}   t_data;

int	ft_input_handling(int ac, char **argv);