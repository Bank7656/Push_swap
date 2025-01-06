/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 01:46:34 by thacharo          #+#    #+#             */
/*   Updated: 2025/01/06 14:49:41 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_num_list(t_data **data, char *str);
static int	ft_checking_number(char *str, int len);
static int	ft_check_front_zero(char *str);

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
	number = 0;
	if (ft_checking_number(str, num_len))
		number = ft_atoi(str);
	else if (ft_check_front_zero(str))
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

static int	ft_check_front_zero(char *str)
{
	int	i;
	int	len;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	len = ft_strlen(str + i);
	if (str[0] == '-' && len == 10)
	{
		if (ft_strncmp(str + i, "2147483648", len) <= 0)
			return (1);
	}
	return (ft_checking_number(str + i, len));
}
