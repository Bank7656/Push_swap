#include "push_swap.h"

void	ft_clear_data(t_data **data)
{
	t_node *temp;

	if (data == NULL)
		return ;
	// Need to free lst_a and lst_b toooo >_<
	while ((*data) -> lst_a != NULL)
	{
		temp = (*data) -> lst_a;
		(*data) -> lst_a = (*data) -> lst_a -> next;
		free(temp);
	}
	free(*data);
}

void	close_program(t_data **data)
{
	ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
	ft_clear_data(data);
	exit (0);
}