/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 23:03:44 by thacharo          #+#    #+#             */
/*   Updated: 2025/01/05 14:08:00 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	ft_check_duplicate(t_data **data);
static void	ft_get_list(t_data **data, char *str);

void	ft_create_stack(t_data **data)
{
	(*data) = (t_data *)malloc(sizeof(t_data));
	if (*data == NULL)
		close_program(data);
	(*data)->head_a = NULL;
	(*data)->head_b = NULL;
	(*data)->tail_a = NULL;
	(*data)->tail_b = NULL;
	(*data)->stack_a.length = 0;
	(*data)->stack_b.length = 0;
	(*data)->stack_a.max = 0;
	(*data)->stack_b.max = 0;
}

int	ft_get_stack(t_data **data, int ac, char **argv)
{
	int		i;
	int		j;
	char	**words;

	i = -1;
	while (++i < ac - 1)
	{
		if (ft_strchr(argv[i], ' '))
		{
			words = ft_split(argv[i], ' ');
			j = 0;
			while (words[j] != NULL)
			{
				ft_get_list(data, words[j]);
				free(words[j++]);
			}
			free(words);
		}
		else
			ft_get_list(data, argv[i]);
	}
	ft_get_stack_length(data);
	return (0);
}

static void	ft_get_list(t_data **data, char *str)
{
	t_node	*last_node;
	t_node	*temp_node;

	if ((*data)->head_a == NULL)
	{
		(*data)->head_a = create_node(data, str);
		(*data)->tail_a = (*data)->head_a;
	}
	else
	{
		temp_node = create_node(data, str);
		last_node = (*data)->head_a;
		while (last_node -> next != NULL)
			last_node = last_node -> next;
		last_node -> next = temp_node;
		temp_node -> prev = last_node;
		(*data)->tail_a = temp_node;
		if (ft_check_duplicate(data))
			close_program(data);
	}
}

static int	ft_check_duplicate(t_data **data)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = (*data)->head_a;
	while (tmp1 != NULL)
	{
		tmp2 = tmp1 -> next;
		while (tmp2 != NULL)
		{
			if (tmp1 -> number == tmp2 -> number)
				return (1);
			tmp2 = tmp2 -> next;
		}
		tmp1 = tmp1 -> next;
	}
	return (0);
}

void	ft_get_stack_length(t_data **data)
{
	t_node	*ptr;

	(*data)->stack_a.length = 0;
	(*data)->stack_b.length = 0;
	ptr = (*data)->head_a;
	while (ptr != NULL)
	{
		(*data)->stack_a.length++;
		ptr = ptr -> next;
	}
	ptr = (*data)->head_b;
	while (ptr != NULL)
	{
		(*data)->stack_b.length++;
		ptr = ptr -> next;
	}
}
