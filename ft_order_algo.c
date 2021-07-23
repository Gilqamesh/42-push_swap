/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 10:15:47 by edavid            #+#    #+#             */
/*   Updated: 2021/07/23 19:40:51 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	update_entropies(t_push_swap *mystruct, int *entr_a, int *entr_b)
{
	*entr_a = calc_entropy(&mystruct->a);
	*entr_b = calc_entropy(&mystruct->b);
}

void	order_stack_algo(t_push_swap *mystruct)
{
	int	entropy_of_a;
	int	entropy_of_b;

	// Find possible rotations of stack_a when applying either sa or pb
	// would reduce the most entropy, while also taking account into
	// the number of operation that would let us make that move.
	// Perhaps if there are more solutions that are close, we could run
	// multiple threads on them and see which is more optimal after some search
	// depth after which we could choose it as our main route again.
	
}
