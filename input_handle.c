#include "push_swap.h"

static  int	ft_check_arg(char *arg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg[i] != '\0')
	{
		if (!(ft_isdigit(arg[i]) || arg[i] == ' ' || arg[i] == '+' || arg[i] == '-'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_input_handling(int ac, char **argv)
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		if (ft_check_arg(argv[i]))
			return (1);
		i++;
	}
	return (0);	
}