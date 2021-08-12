/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:31:33 by edavid            #+#    #+#             */
/*   Updated: 2021/08/12 14:16:35 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils_helper1.h"
#include "utils_helper2.h"
#include "utils_helper4.h"
#include "../../ft_push_swap.h"

t_arrofarrptrs	find_LIS_of_sublist(t_push_swap *mystruct, t_node_binary *head,
int n)
{
	t_INT_array		fir_arr;
	t_INT_array		sec_arr;
	int				*helper;
	t_arrofarrptrs	LIS;

	if (!allocate_helper(&fir_arr, &sec_arr, n, &helper))
		ft_error(mystruct);
	init_arrays_helper(head, n, &fir_arr, &sec_arr);
	ft_merge_sort_int(sec_arr.elements, (t_2_int){0, ft_abs_int(n)}, helper);
	free(helper);
	LIS = find_LCS_of_two_sequences(fir_arr, sec_arr);
	free(fir_arr.elements);
	free(sec_arr.elements);
	return (LIS);
}

t_INTarrofarr	combine_two_LCS_array(t_INTarrofarr *ARR1,
t_INTarrofarr *ARR2, t_list **alloced_ptrs)
{
	int				unique_counter;
	int				i;
	int				j;
	int				compared_value;
	t_INT_array		*LCS_g_a;

	if (!ARR1 || !ARR2 || (!ARR1->size_arr && !ARR2->size_arr))
	{
		LCS_g_a = ft_lstmallocwrapper(alloced_ptrs, sizeof(*LCS_g_a),
				true);
		return ((t_INTarrofarr){LCS_g_a, 0});
	}
	set_unique_counter_helper(&unique_counter, ARR1, ARR2);
	LCS_g_a = ft_lstmallocwrapper(alloced_ptrs,
			unique_counter * sizeof(*LCS_g_a), true);
	combine_helper(unique_counter, ARR1, ARR2, LCS_g_a);
	return ((t_INTarrofarr){LCS_g_a, unique_counter});
}

t_arrofarrptrs	find_LCS_of_two_sequences(t_INT_array fir_arr,
t_INT_array sec_arr)
{
	t_INTarrofarr	**table;
	t_list			*alloced_ptrs;

	init_table(&alloced_ptrs, &table, fir_arr, sec_arr);
	fill_table(table, fir_arr, sec_arr, &alloced_ptrs);
	return ((t_arrofarrptrs){table[fir_arr.size_elements]
		[sec_arr.size_elements], alloced_ptrs});
}

char	*construct_minimum_rotations_needed_ops(t_stack *stack, char stack_name)
{
	char			*result;
	t_node_binary	*cur;
	t_node_binary	*result_lst;
	int				i;

	init_vars(stack, &result_lst, &i, &cur);
	get_rotations(stack, &result_lst, i, stack_name);
	result = ft_nodbinstrjoin_from_back(result_lst);
	ft_nodbinclear(&result_lst, ft_nodbindel, -1);
	return (result);
}

int	get_number_of_rotations_for_inclusion(t_stack *stack, int num,
int dir)
{
	int				rotations;
	t_node_binary	*cur;

	if (stack->n < 2)
		return (0);
	cur = stack->head;
	rotations = 0;
	while (1)
	{
		if ((*(int *)cur->content < *(int *)cur->prev->content
				&& (num < *(int *)cur->content || num
					> *(int *)cur->prev->content))
			|| (*(int *)cur->content > *(int *)cur->prev->content
				&& num < *(int *)cur->content && num
				> *(int *)cur->prev->content))
			break ;
		rotations++;
		if (dir)
			cur = cur->next;
		else
			cur = cur->prev;
	}
	return (rotations);
}
