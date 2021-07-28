/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op1_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:13:02 by edavid            #+#    #+#             */
/*   Updated: 2021/07/28 11:13:25 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	swap_helper_case_3(t_stack *stack)
{
	t_node_binary	*cur_head;
	t_node_binary	*after_head;
	t_node_binary	*before_head;
	t_node_binary	*before_before_head;

	cur_head = stack->head;
	before_head = cur_head->prev;
	after_head = cur_head->next;
	cur_head->next = before_head;
	cur_head->prev = after_head;
	before_head->next = after_head;
	before_head->prev = cur_head;
	after_head->next = cur_head;
	after_head->prev = before_head;
	swap_nodbin_ptrs(&stack->head, &stack->head->prev);
}

void	swap_helper_case_g3(t_stack *stack)
{
	t_node_binary	*cur_head;
	t_node_binary	*after_head;
	t_node_binary	*before_head;
	t_node_binary	*after_after_head;

	cur_head = stack->head;
	after_head = cur_head->next;
	before_head = cur_head->prev;
	after_after_head = after_head->next;
	after_after_head->prev = cur_head;
	before_head->next = after_head;
	cur_head->next = after_after_head;
	cur_head->prev = after_head;
	after_head->next = cur_head;
	after_head->prev = before_head;
	swap_nodbin_ptrs(&stack->head, &stack->head->prev);
}

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
