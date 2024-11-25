/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 04:20:37 by thacharo          #+#    #+#             */
/*   Updated: 2024/11/26 04:22:04 by thacharo         ###   ########.fr       */
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
			if (!(ft_isdigit(av[i][j]) || av[i][j] == ' ' || av[i][j] == '-') || av[i][j] == '+')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_get_number(t_list **lst, char *str, int *idx)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
	{
		// Free
		exit(0);
	}
	stack -> number = ft_atoi(str);
	stack -> index = *idx;
	ft_lstadd_back(lst, ft_lstnew((void *)stack));
	(*idx)++;
}

void ft_get_stack(t_list **head, int ac, char **av)
{
	int	i;
	int	j;
	int idx;
	char	**words;

	i = 0;
	idx = 0;
	while (i < ac - 1)
	{
		if (ft_strchr(av[i], ' '))
		{
			words = ft_split(av[i], ' ');
			j = 0;
			while (words[j][0] != '\0')
				ft_get_number(head, words[j++], &idx);
		}
		else
			ft_get_number(head, av[i], &idx);
		i++;
	}
	return ;
}

int main(int argc, char *argv[])
{
	t_list *stack;
	t_list *ptr;

	stack = NULL;
	if (ft_input_handling(argc, argv + 1))
	{
		printf("Invalid input\n");
		return (EXIT_SUCCESS);
	}
	printf("Valid input\n");
	ft_get_stack(&stack, argc, argv + 1);
	ptr = stack;
	while (ptr != NULL)
	{
		printf("Number:%i Index: %zu\n", ((t_stack *)(ptr -> content)) ->  number, ((t_stack *)(ptr -> content)) -> index);
		ptr = ptr -> next;
	}
	ft_lstclear(&stack, free);
	return (EXIT_SUCCESS);
}
