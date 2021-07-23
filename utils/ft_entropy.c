/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entropy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 10:01:02 by edavid            #+#    #+#             */
/*   Updated: 2021/07/23 10:45:08 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

int	calc_entropy(t_stack *stack)
{
	int	entropy;
	int	i;

	entropy = 0;
	i = -1;
	while (++i < stack->n - 1)
		if (stack->arr[i] < stack->arr[i + 1])
			entropy++;
	if (stack->n > 2 && stack->arr[0] < stack->arr[stack->n - 1])
		entropy++;
	return (entropy);
}
