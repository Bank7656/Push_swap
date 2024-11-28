/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digit_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:17:44 by thacharo          #+#    #+#             */
/*   Updated: 2024/10/21 16:45:22 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_digit(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n = n * (-1);
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}
