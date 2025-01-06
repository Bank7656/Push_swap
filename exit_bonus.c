/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:22:28 by thacharo          #+#    #+#             */
/*   Updated: 2025/01/05 03:02:18 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_clear_data(t_data **data)
{
	t_node	*temp;

	if (data == NULL)
		return ;
	while ((*data)->head_a != NULL)
	{
		temp = (*data)->head_a;
		(*data)->head_a = (*data)->head_a->next;
		free(temp);
	}
	while ((*data)->head_b != NULL)
	{
		temp = (*data)->head_b;
		(*data)->head_b = (*data)->head_b->next;
		free(temp);
	}
	free(*data);
}

void	close_program(t_data **data)
{
	ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
	ft_clear_data(data);
	exit (0);
}
