/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:17:05 by thacharo          #+#    #+#             */
/*   Updated: 2024/12/30 18:43:16 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// Need to protect from stdin and handle INT_MAX, INT_MIN or more
int	ft_get_num_list(char *str)
{
	int	num_len;
	int	number;

	num_len = ft_strlen(str);
	if (num_len < 10)
		number = ft_atoi(str);
	return (number);
}

void	ft_get_list(t_data **data, char *str)
{
	t_node *last_node;
	t_node *temp_node;

	if ((*data) -> head_a == NULL)
	{
		(*data) -> head_a = create_node(data, str);
		(*data) -> tail_a = (*data) -> head_a;
	}
	else
	{
		temp_node = create_node(data, str);
		last_node = (*data) -> head_a;
		while (last_node -> next != NULL)
			last_node = last_node -> next;
		last_node -> next = temp_node;
		temp_node -> prev = last_node;
		(*data) -> tail_a = temp_node;
	}
}

// Also need to handle duplicate number in the list
int	ft_get_stack(t_data **data, int ac, char **argv)
{
	int	i;
	int	j;
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

void ft_sort_index(t_node **lst)
{
	int		idx;
	t_node *tmp1;
	t_node *tmp2;

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

int main(int argc, char **argv)
{
	t_data *data;

	if (argc < 2)
		return (0);
	ft_create_stack(&data);
	if (ft_input_handling(argc, argv + 1))
		close_program(&data);
	if (ft_get_stack(&data, argc, argv + 1))
		close_program(&data);

	// Before
	// printf("Before sort\n");
	ft_sort_index(&(data -> head_a));
	// ft_print_doubly_list(data);
	(data) -> stack_a.max = (data) -> stack_a.length;
    (data) -> stack_b.max = (data) -> stack_b.length;
	
	// Sort
	ft_sort_stack(&data);
	
	// After Sort
	// printf("After sort\n");
	// ft_print_doubly_list(data);
	
	// Clear
	ft_clear_data(&data);
	return (0);
}