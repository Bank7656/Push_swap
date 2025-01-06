/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:37:49 by thacharo          #+#    #+#             */
/*   Updated: 2025/01/06 14:47:51 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

int	ft_is_sorted(t_data *data)
{
	t_node	*tmp_node1;
	t_node	*tmp_node2;

	tmp_node1 = data -> head_a;
	while (tmp_node1 != NULL)
	{
		tmp_node2 = tmp_node1 -> next;
		while (tmp_node2 != NULL)
		{
			if (tmp_node1 -> index > tmp_node2 -> index)
				return (0);
			tmp_node2 = tmp_node2 -> next;
		}
		tmp_node1 = tmp_node1 -> next;
	}
	return (1);
}
