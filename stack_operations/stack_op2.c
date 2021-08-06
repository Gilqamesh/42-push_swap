/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:20:23 by edavid            #+#    #+#             */
/*   Updated: 2021/08/06 20:21:58 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	stack_ra(t_push_swap *mystruct)
{
	if (mystruct->a.n > 1)
		mystruct->a.head = mystruct->a.head->next;
}

void	stack_rb(t_push_swap *mystruct)
{
	if (mystruct->b.n > 1)
		mystruct->b.head = mystruct->b.head->next;
}

void	stack_rr(t_push_swap *mystruct)
{
	stack_ra(mystruct);
	stack_rb(mystruct);
}

void	stack_rotate(t_stack *stack)
{
	if (stack->n > 1)
		stack->head = stack->head->next;
}

void	stack_revrotate(t_stack *stack)
{
	if (stack->n > 1)
		stack->head = stack->head->prev;
}
