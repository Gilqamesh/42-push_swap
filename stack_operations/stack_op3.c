/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:27:29 by edavid            #+#    #+#             */
/*   Updated: 2021/07/27 14:10:52 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	stack_rra(t_push_swap *mystruct)
{
	if (mystruct->a.n > 1)
		mystruct->a.head = mystruct->a.head->prev;
}

void	stack_rrb(t_push_swap *mystruct)
{
	if (mystruct->b.n > 1)
		mystruct->b.head = mystruct->b.head->prev;
}

void	stack_rrr(t_push_swap *mystruct)
{
	stack_rra(mystruct);
	stack_rrb(mystruct);
}
