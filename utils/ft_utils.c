/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 13:20:25 by edavid            #+#    #+#             */
/*   Updated: 2021/08/03 15:59:56 by edavid           ###   ########.fr       */
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

int	is_stack_sorted(t_stack *stack, int check_for_both_dirs)
{
	t_node_binary	*head;
	t_node_binary	*min;
	int				i;

	if (!stack->n)
		return (1);
	head = stack->head;
	min = head;
	i = 0;
	while (++i < stack->n)
	{
		head = head->next;
		if (*(int *)head->content < *(int *)min->content)
			min = head;
	}
	head = min;
	i = 0;
	while (++i < stack->n)
	{
		if (*(int *)head->content > *(int *)head->next->content)
		{
			i = -1;
			if (!check_for_both_dirs)
				return (0);
			else
				break ;
		}
		head = head->next;
	}
	if (i != -1)
		return (1);
	i = 0;
	while (++i < stack->n)
	{
		if (*(int *)head->content > *(int *)head->prev->content)
			return (0);
		head = head->prev;
	}
	return (-1);
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

void	destroy_t_INT_array2(t_INT_array2 *arr)
{
	if (arr->arr1.elements)
		free(arr->arr1.elements);
	if (arr->arr2.elements)
		free(arr->arr2.elements);
	ft_bzero(arr, sizeof(*arr));
}

t_node_binary	*get_min_from_stack(t_stack *stack)
{
	int				i;
	t_node_binary	*min;
	t_node_binary	*cur;

	i = 0;
	cur = stack->head;
	min = stack->head;
	while (++i < stack->n)
	{
		cur = cur->next;
		if (*(int *)cur->content < *(int *)min->content)
			min = cur;
	}
	return (min);
}
