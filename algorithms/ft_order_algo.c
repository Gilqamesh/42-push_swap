/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_order_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 10:15:47 by edavid            #+#    #+#             */
/*   Updated: 2021/07/26 19:21:10 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	order_stack_algo(t_push_swap *mystruct)
{
	char	**potential_routes;

	// Find possible rotations of stack_a when applying either sa or pb
	// would reduce the most entropy, while also taking account into
	// the number of operation that would let us make that move.
	// Perhaps if there are more solutions that are close, we could run
	// multiple threads on them and see which is more optimal after some search
	// depth after which we could choose it as our main route again.
	//
	// When searching for a possible sequence of operations:
	// - (ra (+ rb)) * n (+ rb * m) + pb // ra until found el then rb until
									// pb would not increase E(b), then pb
	// - (rra (+ rrb)) * n (+ rrb * m) + pb // rra until found el then then rrb
									// until pb would not increase E(b), then pb
	// - (ra (+ rb)) * n + pb (+ ra/rra * m) + pa // ra until found el then pb,
									// then ra/rra until pa would not increase
									// E(a), then pa
	// - (rra (+ rrb)) * n + pb (+ ra/rra * m) + pa // rra until found el then
									// pb, then ra/rra until pa would not
									// increase E(a), then pa
	// - (ra ( + rb)) * n + sa(/ss)
	// - (rra ( + rrb)) * n + sa(/ss)
	potential_routes = get_potential_routes(mystruct);
}
