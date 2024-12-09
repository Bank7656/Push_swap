/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 04:20:37 by thacharo          #+#    #+#             */
/*   Updated: 2024/12/03 14:57:33 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_input_handling(int ac, char **av)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (i < ac - 1)
	{
		j = 0;
		len = ft_strlen(av[i]);
		while (j < len)
		{
			if (!(ft_isdigit(av[i][j]) || av[i][j] == ' '
				|| av[i][j] == '-' || av[i][j] == '+'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_get_number_list(t_stack **stack, char *str, int *idx)
{
	t_data *data;
	t_list *new_data;
	t_list *temp_head;
	t_list *temp_tail;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL || str[0] == 0 || idx < 0)
	{
		ft_printf("Error\n");
		exit(0);
	}
	// Don't forget to protect number that more than INT_MAX
	data -> number = ft_atoi(str);
	data -> index = -1;
	new_data = ft_lstnew((void *)data);
	ft_lstadd_back(&((*stack) -> head), new_data);
	(*idx)++;
}

int ft_midpoint(int n)
{
	int	midpoint;

	if (n % 2 == 0)
	{
		midpoint = n / 2 - 1;
	}
	else
		midpoint = n / 2;

	return (midpoint);
}

void ft_get_stack(t_stack **stack, int ac, char **av)
{
	int		i;
	int		j;
	int		idx;
	char	**words;
	t_list 	*temp;
	
	i = 0;
	idx = 0;
	while (i < ac - 1)
	{
		if (ft_strchr(av[i], ' '))
		{
			words = ft_split(av[i], ' ');
			j = 0;
			while (words[j] != NULL)
			{
				ft_get_number_list(stack, words[j], &idx);
				free(words[j++]);
			}
			free(words);
		}
		else
			ft_get_number_list(stack, av[i], &idx);
		i++;
	}
	(*stack) -> midpoint = ft_midpoint(idx);
	(*stack) -> length = idx;
	temp = (*stack) -> head;
	while (temp -> next != NULL)
		temp = temp -> next;
	(*stack) -> tail = temp;
}

void	ft_print_list(t_stack **lst)
{
	t_list *ptr;
	int stack_number;
	int stack_index;
	
	ptr = (*lst) -> head;
	while (ptr != NULL)
	{
		stack_number = ((t_data *)(ptr -> content)) -> number;
		stack_index = ((t_data *)(ptr -> content)) -> index;
		ft_printf("Number: %i Index: %i\n", stack_number, stack_index);
		ptr = ptr -> next;
	}
	return ;
}

t_stack	*ft_create_stack(char stack_name)
{
	t_stack *temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (temp == NULL)
	{
		// if stack b can't create pls free stack_a
		exit(0);
	}
	temp -> length = 0;
	temp -> midpoint = 0;
	temp -> name = stack_name;
	temp -> head = NULL;
	temp -> tail = NULL;
	return (temp);
}

int	ft_check_duplicate(t_list **lst)
{
	int		number1;
	int		number2;
	t_list *trav1;
	t_list *trav2;

	trav1 = *lst;
	while (trav1 != NULL)
	{
		trav2 = trav1 -> next;
		number1 = ((t_data *)(trav1 -> content)) -> number;
		while (trav2 != NULL)
		{
			number2 = ((t_data *)(trav2 -> content)) -> number;
			// ft_printf("Check %i %i\n", number1, number2);
			if (number1 == number2)
			{
				return (1);	
			}
			trav2 = trav2 -> next;
		}
		trav1 = trav1 -> next;
	}
	return (0);
}

int	ft_check_sort(t_list **lst)
{
	int		number1;
	int		number2;
	t_list *trav1;
	t_list *trav2;

	trav1 = *lst;
	while (trav1 != NULL)
	{
		trav2 = trav1 -> next;
		number1 = ((t_data *)(trav1 -> content)) -> number;
		while (trav2 != NULL)
		{
			number2 = ((t_data *)(trav2 -> content)) -> number;
			// ft_printf("Check %i %i\n", number1, number2);
			if (number1 > number2)
			{
				ft_printf("Not sorted\n");
				return (0);	
			}
			trav2 = trav2 -> next;
		}
		trav1 = trav1 -> next;
	}
	ft_printf("Sorted\n");
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack  *stack_a;
	t_stack  *stack_b;

	if (argc < 2)
		return (EXIT_SUCCESS);
	if (ft_input_handling(argc, argv + 1))
	{
		ft_printf("Invalid input\n");
		return (EXIT_SUCCESS);
	}
	ft_printf("Valid input\n");
	
	// Create Stack from an input
	stack_a = ft_create_stack('a');
	stack_b = ft_create_stack('b');
	
	// Assgin value from stdin to the list
	ft_get_stack(&stack_a, argc, argv + 1);
	if (ft_check_duplicate(&(stack_a -> head)))
	{
		ft_lstclear(&(stack_a -> head), free);
		ft_printf("Error\n");
		exit(0);
	}

	// Sorting number index in the stack from low to high
	ft_sort_index(&(stack_a -> head));

	// swap(&(stack_a -> head), &(stack_b -> head), "ss");
	// push(&(stack_a -> head), &(stack_b -> head), "pa");
	// rotate(&stack_a, &stack_b, "ra");
	// reverse_rotate(&stack_a, &stack_b, "rra");

	ft_printf("Before Sort\n");
	ft_printf("Stack A\n");
	ft_print_list(&(stack_a));
	ft_printf("Stack B\n");
	ft_print_list(&(stack_b));
	
	ft_sort_stack(&(stack_a), &(stack_b));
	
	// Print Stack
	ft_printf("After Sort\n");
	ft_printf("Stack A\n");
	ft_print_list(&(stack_a));
	ft_printf("Stack B\n");
	ft_print_list(&(stack_b));
	ft_printf("Median: %i\n", stack_a -> midpoint);
	
	ft_check_sort(&(stack_a -> head));
	// ft_printf("Stack length %i\n", stack_a -> length);
	// Clear Stack
	ft_lstclear(&(stack_a -> head), free);
	ft_lstclear(&(stack_b -> head), free);
	free(stack_a);
	free(stack_b);
	return (EXIT_SUCCESS);
}
