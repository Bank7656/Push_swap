/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:48:02 by thacharo          #+#    #+#             */
/*   Updated: 2024/12/01 16:57:47 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_get_index(t_list *lst, t_data **content)
{
	int		idx;
	int		number;

	idx = 0;
	while (lst != NULL)
	{
		number = (*content) -> number; 
		if (number > ((t_data *)(lst -> content)) -> number)
			idx++;
		lst = lst -> next;
	}
	(*content) -> index = idx;
}

void ft_sort_index(t_list **lst)
{
	t_data *stack_i;
	t_list *trav;

	trav = *lst;
	while (trav != NULL)
	{
		stack_i = ((t_data *)(trav -> content));
		ft_get_index(*lst, &stack_i);
		trav = trav -> next;
	}
}