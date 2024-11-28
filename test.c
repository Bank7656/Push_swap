#include "push_swap.h"

int	main(void)
{
	t_list *node1;
	t_list *node2;
	t_stack *stack1;
	t_stack *stack2;

	node1 = (t_list *)malloc(sizeof(t_list));
	if (!(node1))
		return (0);
	stack1 = (t_stack *)malloc(sizeof(t_stack));
	if (!(stack1))
		return (0);
	stack1 -> number = 5;
	stack1 -> index = 0;

	node1 -> content = stack1;	

	node2 = (t_list *)malloc(sizeof(t_list));
	if (!(node2))
		return (0);
	stack2 = (t_stack *)malloc(sizeof(t_stack));
	if (!(stack2))
		return (0);
	stack2 -> number = 20;
	stack2 -> index = 1;

	node2 -> content = stack2;	

	node1 -> next = node2;

	t_list *ptr;

	ptr = node1;
	while (ptr != NULL)
	{
		printf("%i:%zu\n", ((t_stack*)(ptr -> content)) -> number, ((t_stack*)(ptr -> content)) -> index);
		ptr = ptr -> next;
	}
	return (0);
}