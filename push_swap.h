/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:34:22 by thacharo          #+#    #+#             */
/*   Updated: 2024/12/02 22:13:27 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#endif

#include "libft/libft.h"

typedef struct s_data {
	int				number;
	int				index;
} t_data;

typedef struct s_stack {
	int		length;
	int		midpoint;
	char	name;
	t_list *head;
	t_list *tail;
} t_stack;

void	ft_sort_index(t_list **lst);
void	ft_print_list(t_stack **lst);
void	swap(t_list **lst_a, t_list **lst_b, char *operation);
void	push(t_list **lst_a, t_list **lst_b, char *operation);
void	rotate(t_stack **stack_a, t_stack **stack_b, char *operation);
void	reverse_rotate(t_stack **stack_a, t_stack **stack_b, char *operation);
void	ft_sort_stack(t_stack **stack_a, t_stack **stack_b);

