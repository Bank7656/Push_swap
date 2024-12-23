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
    t_node *head_a;
    t_node *head_b;
    t_node *tail_a;
    t_node *tail_b;
    t_stack stack_a;
    t_stack stack_b;
}   t_data;

int	ft_input_handling(int ac, char **argv);

int     ft_get_num_list(char *str);
void	ft_clear_data(t_data **data);
void    ft_print_doubly_list(t_data *data);
void    close_program(t_data **data);
t_node	*create_node(t_data **data, char *str);
void    swap(t_data **data, char *operation);
void    push(t_data **data, char *operation);
void    rotate(t_data **data, char *operation);
void    reverse_rotate(t_data **data, char *operation);

void	ft_print_reverse_stack(t_node *lst);
void	ft_print_forward_stack(t_node *lst);