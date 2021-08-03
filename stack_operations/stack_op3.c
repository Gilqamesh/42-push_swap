/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:27:29 by edavid            #+#    #+#             */
/*   Updated: 2021/08/03 17:10:06 by edavid           ###   ########.fr       */
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

void	stack_push(t_stack *from, t_stack *to)
{
	t_node_binary	*cur_head;

	if (!from->n)
		return ;
	if (!to->n)
		to->head = remove_head_from_stack(from);
	else if (to->n == 1)
	{
		cur_head = to->head;
		to->head = remove_head_from_stack(from);
		cur_head->next = to->head;
		cur_head->prev = to->head;
		to->head->next = cur_head;
		to->head->prev = cur_head;
	}
	else
		push_helper(to, from);
	to->n++;
}
