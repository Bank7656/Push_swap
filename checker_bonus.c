/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:38:08 by thacharo          #+#    #+#             */
/*   Updated: 2025/01/06 02:46:49 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	ft_is_sorted(t_data *data);
static int	ft_check_operation(const char *str);
static void	ft_sort_index(t_node **lst);
static void	ft_do_operation(t_data **data, char *str);

int main(int argc, char *argv[])
{
	char	*word;
    t_data	*data;

    if (argc < 2)
        return (0);
	ft_create_stack(&data);
	if (ft_input_handling(argc, argv + 1))
		close_program(&data);
	if (ft_get_stack(&data, argc, argv + 1))
		close_program(&data);
	ft_sort_index(&(data -> head_a));
	while (1)
	{
		word = get_next_line(0);
		if (word == NULL)
			break;
		if (!(ft_check_operation(word)))
		{
			free(word);
			close_program(&data);
			return (0);
		}
		ft_do_operation(&data, word);
		ft_get_stack_length(&data);
		free(word);
	}
	if (ft_is_sorted(data) && data -> stack_b.length == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_clear_data(&data);
    return (0);
}

static void	ft_sort_index(t_node **lst)
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

static int	ft_is_sorted(t_data *data)
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

static void	ft_do_operation(t_data **data, char *str)
{
	char	*operation;

	operation = ft_strtrim(str, "\n");
	if (operation == NULL)
		close_program(data);
	if ((ft_strncmp(operation, "sa", -1) == 0) 
	|| (ft_strncmp(str, "sb", -1) == 0)
	|| (ft_strncmp(operation, "ss", -1) == 0))
		swap(data, operation);
	else if ((ft_strncmp(operation, "pa", -1) == 0)
	|| (ft_strncmp(operation, "pb", -1) == 0))
		push(data, operation);
	else if ((ft_strncmp(operation, "ra", -1) == 0)
	|| (ft_strncmp(operation, "rb", -1) == 0)
	|| (ft_strncmp(operation, "rr", -1) == 0))
		rotate(data, operation);
	else if ((ft_strncmp(operation, "rra", -1) == 0)
	|| (ft_strncmp(operation, "rrb", -1) == 0)
	|| (ft_strncmp(operation, "rrr", -1) == 0))
		reverse_rotate(data, operation);
	free(operation);
	return ;
}

static int	ft_check_operation(const char *str)
{
	if (ft_strncmp(str, "sa\n", -1) == 0)
		return (1);
	else if (ft_strncmp(str, "sb\n", -1) == 0)
		return (1);
	else if (ft_strncmp(str, "ss\n", -1) == 0)
		return (1);
	else if (ft_strncmp(str, "pa\n", -1) == 0)
		return (1);
	else if (ft_strncmp(str, "pb\n", -1) == 0)
		return (1);
	else if (ft_strncmp(str, "ra\n", -1) == 0)
		return (1);
	else if (ft_strncmp(str, "rb\n", -1) == 0)
		return (1);
	else if (ft_strncmp(str, "rr\n", -1) == 0)
		return (1);
	else if (ft_strncmp(str, "rra\n", -1) == 0)
		return (1);
	else if (ft_strncmp(str, "rrb\n", -1) == 0)
		return (1);
	else if (ft_strncmp(str, "rrr\n", -1) == 0)
		return (1);
	else
		return (0);
}
