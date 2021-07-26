/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_routes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 13:58:19 by edavid            #+#    #+#             */
/*   Updated: 2021/07/26 09:34:02 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// int	distance_from_entropy_point_on_stack(t_stack *a, int direction)
// {
	
// }

char	**get_potential_routes(t_push_swap *mystruct)
{
	distance_from_entropy_point_on_stack(&mystruct->a, 1);
}

void	update_entropies(t_push_swap *mystruct, int *entr_a, int *entr_b)
{
	*entr_a = calc_entropy(&mystruct->a);
	*entr_b = calc_entropy(&mystruct->b);
}
