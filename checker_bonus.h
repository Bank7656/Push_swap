/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:38:25 by thacharo          #+#    #+#             */
/*   Updated: 2025/01/06 14:50:28 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# define ERROR_MSG "Error\n"

# include "libft/libft.h"

typedef struct s_node
{
	int				moves;
	int				ra_count;
	int				rra_count;
	int				rb_count;
	int				rrb_count;
	int				diff;
	int				number;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int	length;
	int	max;
}	t_stack;

typedef struct s_data
{
	t_node	*head_a;
	t_node	*head_b;
	t_node	*tail_a;
	t_node	*tail_b;
	t_stack	stack_a;
	t_stack	stack_b;
}	t_data;

void	ft_sort_index(t_node **lst);
int		ft_is_sorted(t_data *data);
void	close_program(t_data **data);
void	ft_create_stack(t_data **data);
void	ft_get_stack(t_data **data, int ac, char **argv);
void	ft_get_stack_length(t_data **data);
int		ft_input_handling(int ac, char **argv);
void	ft_clear_data(t_data **data);
t_node	*create_node(t_data **data, char *str);
void	swap(t_data **data, char *operation);
void	push(t_data **data, char *operation);
void	rotate(t_data **data, char *operation);
void	reverse_rotate(t_data **data, char *operation);
#endif