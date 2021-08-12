/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_helper4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:07:08 by edavid            #+#    #+#             */
/*   Updated: 2021/08/12 14:15:57 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_helper1.h"
#include "utils_helper4.h"
#include "utils_helper5.h"

void	init_vars(t_stack *stack, t_node_binary **result_lst, int *i,
t_node_binary **cur)
{
	t_node_binary	*min;

	min = get_min_from_stack(stack);
	*cur = stack->head;
	*i = -1;
	while (++(*i) < stack->n)
	{
		if (*cur == min)
			break ;
		*cur = (*cur)->next;
	}
	*result_lst = NULL;
}

void	get_rotations(t_stack *stack, t_node_binary **result_lst, int i,
char stack_name)
{
	if (i > stack->n / 2)
	{
		i = stack->n - i;
		if (stack_name == 'a')
			while (i-- > 0)
				ft_nodbinadd_front(result_lst, ft_nodbinnew(ft_strdup(" rra")));
		else
			while (i-- > 0)
				ft_nodbinadd_front(result_lst, ft_nodbinnew(ft_strdup(" rrb")));
	}
	else
	{
		if (stack_name == 'a')
			while (i-- > 0)
				ft_nodbinadd_front(result_lst, ft_nodbinnew(ft_strdup(" ra")));
		else
			while (i-- > 0)
				ft_nodbinadd_front(result_lst, ft_nodbinnew(ft_strdup(" rb")));
	}
}

int	get_input_limit_on_LIS(int n_of_inputs)
{
	if (n_of_inputs > 200)
		return (200);
	return (n_of_inputs);
}

void	copy_stack(t_stack *dest, t_stack *src, int n)
{
	t_node_binary	*head;
	t_node_binary	*last;
	t_node_binary	*tmp;

	dest->head = NULL;
	dest->n = src->n;
	if (!n)
		return ;
	head = src->head;
	while (n-- > 0)
	{
		tmp = ft_nodbinnew(ft_intdup(*(int *)head->content));
		ft_nodbinadd_back(&dest->head, tmp);
		head = head->next;
		if (!n)
			last = tmp;
	}
	dest->head->prev = last;
	last->next = dest->head;
}

char	*find_minimum_sequence_of_all_LIS(t_arrofarrptrs *LIS_ord_unord,
t_push_swap *mystruct)
{
	char			*res_str;
	int				min_index;
	t_INT_array2	int_arr;

	min_index = get_min_index_of_LIS(mystruct, LIS_ord_unord);
	int_arr.arr1 = LIS_ord_unord->table.arr[min_index];
	int_arr.arr2 = fill_unordered(mystruct,
			LIS_ord_unord->table.arr + min_index);
	res_str = keep_LIS_in_A(mystruct, &int_arr);
	free(int_arr.arr2.elements);
	return (res_str);
}
