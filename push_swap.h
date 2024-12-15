#include "libft/libft.h"

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#endif

#define ERROR_MSG "Error\n"

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
    char    name;
}   t_stack;

typedef struct s_data
{
    t_node *lst_a;
    t_node *lst_b;
    t_stack stack_a;
    t_stack stack_b;
}   t_data;

int	ft_input_handling(int ac, char **argv);

int	ft_get_num_list(char *str);
t_node	*create_node(t_data **data, char *str, int *idx);
void	ft_clear_data(t_data **data);
void    ft_print_doubly_list(t_node *lst);
void    close_program(t_data **data);