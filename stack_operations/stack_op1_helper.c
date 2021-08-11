/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op1_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:13:02 by edavid            #+#    #+#             */
/*   Updated: 2021/08/11 23:05:01 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

static void	remove_head_helper(t_stack *stack)
{
	t_node_binary	*after_head;
	t_node_binary	*prev_head;

	after_head = stack->head->next;
	prev_head = stack->head->prev;
	prev_head->next = after_head;
	after_head->prev = prev_head;
	stack->head = after_head;
}

t_node_binary	*remove_head_from_stack(t_stack *stack)
{
	t_node_binary	*r;

	if (!stack->n)
		return ((t_node_binary *)0);
	r = stack->head;
	if (stack->n == 1)
		stack->head = (t_node_binary *)0;
	else if (stack->n == 2)
	{
		stack->head = stack->head->prev;
		stack->head->next = stack->head;
		stack->head->prev = stack->head;
	}
	else
		remove_head_helper(stack);
	stack->n--;
	r->next = r;
	r->prev = r;
	return (r);
}

void	push_helper(t_stack *pushed, t_stack *popped)
{
	t_node_binary	*prev_head;
	t_node_binary	*cur_head;

	prev_head = pushed->head->prev;
	cur_head = pushed->head;
	pushed->head = remove_head_from_stack(popped);
	cur_head->prev = pushed->head;
	prev_head->next = pushed->head;
	pushed->head->prev = prev_head;
	pushed->head->next = cur_head;
}

void	stack_swap(t_stack *stack)
{
	if (stack->n < 2)
		return ;
	swap_nodbin_content(stack->head, stack->head->next);
}
