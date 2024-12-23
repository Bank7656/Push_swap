/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:17:05 by thacharo          #+#    #+#             */
/*   Updated: 2024/12/23 14:36:18 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_create_stack(t_data **data)
{
	(*data) = (t_data *)malloc(sizeof(t_data));
	if (*data == NULL)
		close_program(data);
	(*data) -> head_a = NULL;
	(*data) -> head_b = NULL;
	(*data) -> tail_a = NULL;
	(*data) -> tail_b = NULL;
	(*data) -> stack_a.name = 'A';
	(*data) -> stack_b.name = 'B';
	(*data) -> stack_a.length = 0;
	(*data) -> stack_b.length = 0;
	(*data) -> stack_a.median = 0;
	(*data) -> stack_b.median = 0;
}

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

int	ft_get_stack(t_data **data, int ac, char **argv)
{
	int	i;
	int	j;
	char	**words;

	i = -1;
	j = 0;
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
	return (0);
}

void ft_sort_stack(t_node **lst)
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
	printf("Before sort\n");
	ft_sort_stack(&(data -> head_a));
	ft_print_doubly_list(data);
	// rotate(&data, "ra");
	// reverse_rotate(&data, "rra");
	for (int i = 0; i < 12 ; i++)
	{
		printf("%i times pushed\n", i + 1);
		push(&data, "pb");
		// ft_print_doubly_list(data);
		printf("Stack A\n");
		ft_print_forward_stack(data -> head_a);
		ft_print_reverse_stack(data -> head_a);
		printf("Stack B\n");
		ft_print_forward_stack(data -> head_b);
		ft_print_reverse_stack(data -> head_b);
	}
	for (int i = 0; i < 12 ; i++)
	{
		printf("%i times pushed back\n", i + 1);
		push(&data, "pa");
		// ft_print_doubly_list(data);
		printf("Stack A\n");
		ft_print_forward_stack(data -> head_a);
		ft_print_reverse_stack(data -> head_a);
		printf("Stack B\n");
		ft_print_forward_stack(data -> head_b);
		ft_print_reverse_stack(data -> head_b);
	}
	// swap(&data, "sa");
	ft_clear_data(&data);
	
	return (0);
}