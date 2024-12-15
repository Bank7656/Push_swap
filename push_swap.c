#include "push_swap.h"

void	ft_create_stack(t_data **data)
{
	(*data) = (t_data *)malloc(sizeof(t_data));
	if (*data == NULL)
		close_program(data);
	(*data) -> lst_a = NULL;
	(*data) -> lst_b = NULL;
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

void	ft_get_list(t_data **data, char *str, int *idx)
{
	t_node *last_node;
	t_node *temp_node;

	if ((*data) -> lst_a == NULL)
		(*data) -> lst_a = create_node(data, str, idx);
	else
	{
		temp_node = create_node(data, str, idx);
		last_node = (*data) -> lst_a;
		while (last_node -> next != NULL)
			last_node = last_node -> next;
		last_node -> next = temp_node;
		temp_node -> prev = last_node;
	}
}

int	ft_get_stack(t_data **data, int ac, char **argv)
{
	int	i;
	int	j;
	int	idx;
	char	**words;

	i = 0;
	j = 0;
	idx = 0;	
	while (i < ac - 1)
	{
		if (ft_strchr(argv[i], ' '))
		{
			words = ft_split(argv[i], ' ');
			j = 0;
			while (words[j] != NULL)
			{
				ft_get_list(data, words[j], &idx);
				free(words[j++]);
			}
			free(words);
		}
		else
			ft_get_list(data, argv[i], &idx);
		i++;
	}
	return (0);
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
	ft_print_doubly_list(data -> lst_a);
	ft_clear_data(&data);
	return (0);
}