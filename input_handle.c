/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:24:26 by thacharo          #+#    #+#             */
/*   Updated: 2025/01/08 22:05:16 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_arg(char *arg);
static int	check_front_sign(const char *str, int index);

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

static int	ft_check_arg(char *arg)
{
	int	i;
	int	sign;
	int	is_number_in_arg;

	i = -1;
	sign = 0;
	is_number_in_arg = 0;
	while (arg[++i] != '\0')
	{
		if (!(ft_isdigit(arg[i]) || arg[i] == ' '
				|| arg[i] == '+' || arg[i] == '-'))
			return (1);
		else if (arg[i] == '-' || arg[i] == '+')
		{
			if (check_front_sign(arg, i))
				return (1);
			if (sign++)
				return (1);
		}
		else if (ft_isdigit(arg[i]))
			is_number_in_arg = 1;
	}
	if (!(is_number_in_arg))
		return (1);
	return (0);
}

static int	check_front_sign(const char *str, int index)
{
	if (index == 0)
		return (0);
	if (ft_isdigit(str[index - 1]))
		return (1);
	return (0);
}
