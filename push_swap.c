#include "push_swap.h"

void	ft_clear_data(t_data **data)
{
	if (data == NULL)
		return ;
	if ((*data) -> stack_a != NULL)
	{
		if ((*data) -> stack_a -> name)
			free((*data) -> stack_a -> name);
		free((*data) -> stack_a);
	}
	if ((*data) -> stack_b != NULL)
	{
		if ((*data) -> stack_b -> name)
			free((*data) -> stack_b -> name);
		free((*data) -> stack_b);
	}
	free(*data);
	// Need to free lst_a and lst_b toooo >_<
}

void	ft_create_stack(t_data **data)
{
	(*data) = (t_data *)malloc(sizeof(t_data));
	if (*data == NULL)
		exit(0);
	(*data) -> lst_a = NULL;
	(*data) -> lst_b = NULL;
	(*data) -> stack_a = (t_stack *)malloc(sizeof(t_stack));
	(*data) -> stack_b = (t_stack *)malloc(sizeof(t_stack));
	(*data) -> stack_a -> name = NULL;
	(*data) -> stack_b -> name = NULL;
	if ((*data) -> stack_a == NULL || (*data) -> stack_b == NULL)
	{
		ft_clear_data(data);
		exit(0);
	}
	(*data) -> stack_a -> name = ft_strdup("A");
	(*data) -> stack_b -> name = ft_strdup("B");
	if ((*data) -> stack_a -> name == NULL || (*data) -> stack_b -> name == NULL)
	{
		ft_clear_data(data);
		exit(0);
	}
	(*data) -> stack_a -> length = 0;
	(*data) -> stack_b -> length = 0;
	(*data) -> stack_a -> median = 0;
	(*data) -> stack_b -> median = 0;
}

int	ft_get_stack(t_node **lst, int ac, char **argv)
{
	int	i;
	int	j;
	char	**words;

	i = 0;
	j = 0;
	while (i < ac - 1)
	{
		if (ft_strchr(argv[i], ' '))
		{
			words = ft_split(argv[i], ' ');
			j = 0;
			while (words[j] != NULL)
			{
				// get_lst
				free(words[j++]);
			}
			free(words);
		}
		else
			// get_lst
		i++;
	}
}

int main(int argc, char **argv)
{
	t_data *data;

	if (argc < 2)
		return (0);
	ft_create_stack(&data);
	
	if (ft_input_handling(argc, argv + 1))
	{
		ft_putstr_fd("Error\n", 2);
		ft_clear_data(&data);
		return (0);
	}

	if (ft_get_stack(&(data -> lst_a), argc, argv + 1))
	{
		ft_putstr_fd("Error\n", 2);
		ft_clear_data(&data);
		return (0);
	}

	ft_clear_data(&data);
	return (0);
}