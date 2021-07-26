/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:05:13 by edavid            #+#    #+#             */
/*   Updated: 2021/07/26 16:24:47 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	stack_sa(t_push_swap *mystruct)
{
	if (mystruct->a.n < 2)
		return ;
	if (mystruct->a.n == 2)
		mystruct->a.head = mystruct->a.head->next;
	else if (mystruct->a.n == 3)
		swap_helper_case_3(&mystruct->a);
	else
		swap_helper_case_g3(&mystruct->a);
}

void	stack_sb(t_push_swap *mystruct)
{
	if (mystruct->b.n < 2)
		return ;
	if (mystruct->b.n == 2)
		mystruct->b.head = mystruct->b.head->next;
	else if (mystruct->b.n == 3)
		swap_helper_case_3(&mystruct->b);
	else
		swap_helper_case_g3(&mystruct->b);
}

void	stack_ss(t_push_swap *mystruct)
{
	stack_sa(mystruct);
	stack_sb(mystruct);
}

void	stack_pa(t_push_swap *mystruct)
{
	t_node_binary	*prev_head;
	t_node_binary	*after_head;

	if (!mystruct->b.n)
		return ;
	if (!mystruct->a.n)
		mystruct->a.head = remove_head_from_stack(&mystruct->b);
	else if (mystruct->a.n == 1)
	{
		prev_head = mystruct->a.head;
		mystruct->a.head = remove_head_from_stack(&mystruct->b);
		prev_head->next = mystruct->a.head;
		prev_head->prev = mystruct->a.head;
		mystruct->a.head->next = prev_head;
		mystruct->a.head->prev = prev_head;
	}
	else
		push_helper(&mystruct->a, &mystruct->b);
}

void	stack_pb(t_push_swap *mystruct)
{
	t_node_binary	*prev_head;
	t_node_binary	*after_head;

	if (!mystruct->a.n)
		return ;
	if (!mystruct->b.n)
		mystruct->b.head = remove_head_from_stack(&mystruct->a);
	else if (mystruct->b.n == 1)
	{
		prev_head = mystruct->b.head;
		mystruct->b.head = remove_head_from_stack(&mystruct->a);
		prev_head->next = mystruct->b.head;
		prev_head->prev = mystruct->b.head;
		mystruct->b.head->next = prev_head;
		mystruct->b.head->prev = prev_head;
	}
	else
		push_helper(&mystruct->b, &mystruct->a);
}
