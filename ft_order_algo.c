/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 10:15:47 by edavid            #+#    #+#             */
/*   Updated: 2021/07/23 11:18:24 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	update_entropies(t_push_swap *mystruct, int *entr_a, int *entr_b)
{
	*entr_a = calc_entropy(&mystruct->a);
	*entr_b = calc_entropy(&mystruct->b);
}

void	order_stack_algo(t_push_swap *mystruct)
{
	int	entropy_of_a;
	int	entropy_of_b;

	update_entropies(mystruct, &entropy_of_a, &entropy_of_b);
	while (!entropy_of_a && !entropy_of_b)
	{
		// check for swap, push and rotate functions and apply the one that
		// reduces entropy the most
		// change of entropy for push: -2, -1, 0, 1, +2
		// change of entropy for swap: -2 <= swap <= +2
		// change of entropy for rot: -2, -1, 0, 1, +2
		// these values are for each stack individually
		// problem: what if there is no operation that decreases entropy?
		update_entropies(mystruct, &entropy_of_a, &entropy_of_b);
	}
	/* entropy of a and b are 0 */
	// rotate a and use (pa) to push the remaining elements to a
	// rotate a to final position
}
