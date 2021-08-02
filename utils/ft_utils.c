/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 13:20:25 by edavid            #+#    #+#             */
/*   Updated: 2021/08/02 18:19:23 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_push_swap.h"

void	swap_nodbin_ptrs(t_node_binary **a, t_node_binary **b)
{
	t_node_binary	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	is_sublist_ordered(t_node_binary *p, int n)
{
	return (0);
}

int	is_stack_sorted(t_stack *stack)
{
	t_node_binary	*head;
	int				min;
	int				i;

	if (!stack->n)
		return (1);
	head = stack->head;
	min = *(int *)head->content;
	i = 0;
	while (++i < stack->n)
	{
		head = head->next;
		if (*(int *)head->content < min)
			min = *(int *)head->content;
	}
	while (*(int *)head->content != min)
		head = head->next;
	i = 0;
	while (++i < stack->n)
	{
		if (*(int *)head->content > *(int *)head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

/* Allocates and returns a t_INT_array that is the result of going over the
** t_list from *head
*/
t_INT_array	construct_intarr_from_lst(t_list *lst)
{
	int	*result_arr;
	int	arrLen;

	arrLen = 0;
	if (!lst)
		return ((t_INT_array){(int *)0, 0});
	result_arr = (int *)0;
	while (lst)
	{
		result_arr = ft_realloc(result_arr, ++arrLen * sizeof(*result_arr));
		result_arr[arrLen - 1] = *(int *)lst->content;
		lst = lst->next;
	}
	return ((t_INT_array){result_arr, arrLen});
}

