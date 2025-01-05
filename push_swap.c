/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:30:33 by thacharo          #+#    #+#             */
/*   Updated: 2025/01/03 22:54:50 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_index(t_node **lst)
{
	int		idx;
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = *lst;
	while (tmp1 != NULL)
	{
		idx = 1;
		tmp2 = *lst;
		while (tmp2 != NULL)
		{
			if (tmp1 -> number > tmp2 -> number)
				idx++;
			tmp2 = tmp2 -> next;
		}
		tmp1 -> index = idx;
		tmp1 = tmp1 -> next;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (0);
	ft_create_stack(&data);
	if (ft_input_handling(argc, argv + 1))
		close_program(&data);
	if (ft_get_stack(&data, argc, argv + 1))
		close_program(&data);
	ft_sort_index(&(data -> head_a));
	data -> stack_a.max = data -> stack_a.length;
	data -> stack_b.max = data -> stack_b.length;
	ft_sort_stack(&data);
	ft_clear_data(&data);
	return (0);
}