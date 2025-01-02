/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 01:46:34 by thacharo          #+#    #+#             */
/*   Updated: 2025/01/02 19:21:52 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_num_list(t_data **data, char *str);
static int	ft_checking_number(char *str, int len);

t_node	*create_node(t_data **data, char *str)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		close_program(data);
	new_node -> number = ft_get_num_list(data, str);
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

// Need to protect from stdin and handle INT_MAX, INT_MIN or more
static int	ft_get_num_list(t_data **data, char *str)
{
	int	num_len;
	int	number;

	num_len = ft_strlen(str);
	if (ft_checking_number(str, num_len))
		number = ft_atoi(str);
	else
		close_program(data);
	return (number);
}

static int	ft_checking_number(char *str, int len)
{
	if (len > 11 || (len > 10 && str[0] != '-'))
		return (0);
	if (str[0] == '-' && len == 11)
	{
		if (ft_strncmp(str, "-2147483648", len) > 0)
			return (0);
	}
	else if (len == 10)
	{
		if (ft_strncmp(str, "2147483647", len) > 0)
			return (0);
	}
	return (1);
}
