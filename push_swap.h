/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 22:34:22 by thacharo          #+#    #+#             */
/*   Updated: 2024/11/24 22:43:50 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#endif

#define EXIT_SUCCESS 0;
#define EXIT_FAILURE 1;

#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack {
	int				number;
	size_t			index;
	struct s_stack	*next;
} t_stack;


