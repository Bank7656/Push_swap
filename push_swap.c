/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 04:20:37 by thacharo          #+#    #+#             */
/*   Updated: 2024/11/28 14:36:55 by thacharo         ###   ########.fr       */
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
				|| av[i][j] == '-') || av[i][j] == '+')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_get_number_list(t_list **lst, char *str, int *idx)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
	{
		ft_lstclear(lst, free);
		exit(0);
	}
	stack -> number = ft_atoi(str);
	stack -> index = *idx;
	ft_lstadd_back(lst, ft_lstnew((void *)stack));
	(*idx)++;
}

int	ft_get_stack(t_list **head, int ac, char **av)
{
	int		i;
	int		j;
	int		idx;
	char	**words;

	i = 0;
	idx = 0;
	while (i < ac - 1)
	{
		if (ft_strchr(av[i], ' '))
		{
			words = ft_split(av[i], ' ');
			j = 0;
			while (words[j] != NULL)
				ft_get_number_list(head, words[j++], &idx);
		}
		else
			ft_get_number_list(head, av[i], &idx);
		i++;
	}
	return (idx);
}

void	ft_print_list(t_list **lst)
{
	t_list *ptr;
	ptr = *lst;
	while (ptr != NULL)
	{
		ft_printf("Number: %i Index: %i\n",
			((t_stack *)(ptr -> content))->number,
			((t_stack *)(ptr -> content))->index);
		ptr = ptr -> next;
	}
}

void ft_sort_index(t_list **lst, int len)
{
	int		idx;	
	int		prev;
	int		check;
	int		num_tmp0;
	int		num_tmp1;
	int		num_tmp2;
	t_list *tmp1;
	t_list *tmp2;
	t_list *trav;

	// 0 to n index.
	idx = 0;

	// Comparison pointers.
	tmp1 = (*lst);

	// For skipping condition for the first loop
	check = 0;

	// Looping n times.
	while (idx < len)
	{
		tmp2 = tmp1;	
		num_tmp1 = ((t_stack *)(tmp1 -> content)) -> number;
		num_tmp0 = num_tmp1;
		while (tmp2 != NULL)
		{

			num_tmp2 = ((t_stack *)(tmp2 -> content)) -> number;
			if (num_tmp2 < num_tmp0)
			{
				if (check)
				{
					if (num_tmp2 > prev)
						num_tmp0 = num_tmp2;
				}
				else
					num_tmp0 = num_tmp2;
			}
			// Move tmp2 until end of the list.
			tmp2 = tmp2 -> next;			
		}	
		
		// Start checking previous lowest number.
		check = 1;
	
		prev = num_tmp0; // Last lowest from current loop will use to the next one.

		// If lowest number is at head, move to the next node
		if (prev == num_tmp1)
			tmp1 = tmp1 -> next;	

		// Loop whole list for assign index
		trav = (*lst);
		while (trav != NULL)
		{
			if (((t_stack *)(trav -> content)) -> number == num_tmp0)
			{
				((t_stack *)(trav -> content)) -> index = idx;
				break;	
			}
			
			trav = trav -> next;
		}
		// return;
		idx++;
	}
}

int	main(int argc, char *argv[])
{
	int		len;
	t_list	*stack;
	t_list	*ptr;

	stack = NULL;
	if (ft_input_handling(argc, argv + 1))
	{
		ft_printf("Invalid input\n");
		return (EXIT_SUCCESS);
	}
	ft_printf("Valid input\n");
	len = ft_get_stack(&stack, argc, argv + 1);
	ft_sort_index(&stack, len);
	ft_print_list(&stack);
	ft_lstclear(&stack, free);
	return (EXIT_SUCCESS);
}
