/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:05:00 by thacharo          #+#    #+#             */
/*   Updated: 2024/11/26 12:36:09 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	number;

	sign = 0;
	number = 0;
	i = 0;
	if (nptr == NULL)
		return (0);
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	while ((nptr[i] == '-' || nptr[i] == '+'))
	{
		if (sign != 0)
			return (0);
		if (nptr[i++] == '-')
			sign = -1;
		else
			sign = 1;
	}
	if (sign == 0)
		sign = 1;
	while (ft_isdigit(nptr[i]))
		number = (number * 10) + nptr[i++] - 48;
	return (number * sign);
}
