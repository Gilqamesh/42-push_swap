/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:31:33 by edavid            #+#    #+#             */
/*   Updated: 2021/08/10 14:44:49 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../ft_push_swap.h"
#include <time.h>
#include <stdio.h>

t_INT_array2	find_LIS_of_sublist(t_push_swap *mystruct, t_node_binary *head,
int n)
{
	t_INT_array		first_arr;
	t_INT_array		second_arr;
	t_INT_array		unordered;
	t_node_binary	*cur;
	int				*helper;
	int				i;
	int				j;
	int				found;

	first_arr.elements = malloc((n > 0 ? n : -n) * sizeof(*first_arr.elements));
	first_arr.size_elements = n > 0 ? n : -n;
	second_arr.elements = malloc((n > 0 ? n : -n) * sizeof(*second_arr.elements));
	helper = malloc((n > 0 ? n : -n) * sizeof(*helper));
	second_arr.size_elements = n > 0 ? n : -n;
	if (!first_arr.elements || !second_arr.elements || !helper)
		ft_error(mystruct);
	cur = head;
	i = -1;
	if (n < 0)
	{
		while (++i < -n)
		{
			first_arr.elements[i] = *(int *)cur->content;
			second_arr.elements[i] = *(int *)cur->content;
			cur = cur->prev;
		}
	}
	else
	{
		while (++i < n)
		{
			first_arr.elements[i] = *(int *)cur->content;
			second_arr.elements[i] = *(int *)cur->content;
			cur = cur->next;
		}
	}
	ft_merge_sort_int(second_arr.elements, (t_2_int){0, ft_abs_int(n)}, helper);
	free(helper);
	t_INT_array	LIS;
	LIS = find_LCS_of_two_sequences(first_arr, second_arr);
	unordered.size_elements = 0;
	unordered.elements = malloc((first_arr.size_elements - LIS.size_elements)
		* sizeof(int));
	i = -1;
	while (++i < first_arr.size_elements)
	{
		j = -1;
		found = 0;
		while (++j < LIS.size_elements)
		{
			if (first_arr.elements[i] == LIS.elements[j])
			{
				found = 1;
				break ;
			}
		}
		if (!found)
			unordered.elements[unordered.size_elements++]
				= first_arr.elements[i];
	}
	free(first_arr.elements);
	free(second_arr.elements);
	return ((t_INT_array2){LIS, unordered});
}

t_INTarrofarr	combine_two_LCS_array(t_INTarrofarr *ARR1,
t_INTarrofarr *ARR2, t_list **alloced_ptrs)
{
	int				unique_counter;
	int				i;
	int				j;
	int				compared_value;
	t_INT_array		*LCS_group_arr;
	int				LCS_index;

	if (!ARR1 || !ARR2 || (!ARR1->size_arr && !ARR2->size_arr))
	{
		LCS_group_arr = ft_lstmallocwrapper(alloced_ptrs, sizeof(*LCS_group_arr),
			true);
		return ((t_INTarrofarr){LCS_group_arr, 0});
	}
	unique_counter = 0;
	i = 0;
	j = 0;
	while (1)
	{
		if (i < ARR1->size_arr && j < ARR2->size_arr)
		{
			compared_value = ft_intarrcmp(&ARR1->arr[i], &ARR2->arr[j]);
			if (!compared_value)
			{
				i++;
				j++;	
			}
			else if (compared_value < 0)
				i++;
			else
				j++;
			unique_counter++;
		}
		else if (i < ARR1->size_arr)
		{
			unique_counter++;
			i++;
		}
		else if (j < ARR2->size_arr)
		{
			unique_counter++;
			j++;
		}
		else
			break ;
	}
	LCS_group_arr = ft_lstmallocwrapper(alloced_ptrs,
		unique_counter * sizeof(*LCS_group_arr), true);
	i = 0;
	j = 0;
	LCS_index = -1;
	while (++LCS_index < unique_counter)
	{
		if (i < ARR1->size_arr && j < ARR2->size_arr)
		{
			compared_value = ft_intarrcmp(&ARR1->arr[i], &ARR2->arr[j]);
			if (!compared_value)
			{
				LCS_group_arr[LCS_index].size_elements
					= ARR1->arr[i].size_elements;
				LCS_group_arr[LCS_index].elements
					= ARR1->arr[i].elements;
				i++;
				j++;	
			}
			else if (compared_value < 0)
			{
				LCS_group_arr[LCS_index].size_elements
					= ARR1->arr[i].size_elements;
				LCS_group_arr[LCS_index].elements
					= ARR1->arr[i].elements;
				i++;
			}
			else
			{
				LCS_group_arr[LCS_index].size_elements
					= ARR2->arr[j].size_elements;
				LCS_group_arr[LCS_index].elements
					= ARR2->arr[j].elements;
				j++;
			}
		}
		else if (i < ARR1->size_arr)
		{
			LCS_group_arr[LCS_index].size_elements
				= ARR1->arr[i].size_elements;
			LCS_group_arr[LCS_index].elements
				= ARR1->arr[i].elements;
			i++;
		}
		else
		{
			LCS_group_arr[LCS_index].size_elements
				= ARR2->arr[j].size_elements;
			LCS_group_arr[LCS_index].elements
				= ARR2->arr[j].elements;
			j++;
		}
	}
	return ((t_INTarrofarr){LCS_group_arr, unique_counter});
}

t_INT_array	find_LCS_of_two_sequences(t_INT_array first_arr,
t_INT_array second_arr)
{
	t_INTarrofarr	**table;
	t_INT_array				result;
	int						i;
	int						j;
	int						k;
	t_list					*alloced_ptrs;

	alloced_ptrs = NULL;
	table = ft_lstmallocwrapper(&alloced_ptrs,
		(first_arr.size_elements + 1) * sizeof(*table), true);
	i = -1;
	while (++i < first_arr.size_elements + 1)
		table[i] = ft_lstmallocwrapper(&alloced_ptrs,
			(second_arr.size_elements + 1) * sizeof(**table), true);
	i = -1;
	while (++i < first_arr.size_elements + 1)
	{
		table[i][0].size_arr = 0;
		table[i][0].arr = ft_lstmallocwrapper(&alloced_ptrs,
			sizeof(*table[i][0].arr), true);
	}
	i = 0;
	while (++i < second_arr.size_elements + 1)
	{
		table[0][i].size_arr = 0;
		table[0][i].arr = ft_lstmallocwrapper(&alloced_ptrs,
			sizeof(*table[0][i].arr), true);
	}
	i = 0;
	while (++i < first_arr.size_elements + 1)
	{
		j = 0;
		while (++j < second_arr.size_elements + 1)
		{
			if (first_arr.elements[i - 1] == second_arr.elements[j - 1])
			{
				if (table[i - 1][j - 1].size_arr)
				{
					table[i][j].size_arr = table[i - 1][j - 1].size_arr;
					table[i][j].arr = ft_lstmallocwrapper(&alloced_ptrs,
						table[i][j].size_arr * sizeof(*(table[i][j].arr)),
						true);
				}
				else
				{
					table[i][j].size_arr = 1;
					table[i][j].arr = ft_lstmallocwrapper(&alloced_ptrs,
						sizeof(*table[i][j].arr), true);
					table[i][j].arr->elements = ft_lstmallocwrapper(
						&alloced_ptrs, sizeof(int), true);
					table[i][j].arr->size_elements = 1;
					*table[i][j].arr->elements = first_arr.elements[i - 1];
				}
				k = -1;
				while (++k < table[i - 1][j - 1].size_arr)
				{
					table[i][j].arr[k].size_elements =
						table[i - 1][j - 1].arr[k].size_elements + 1;
					table[i][j].arr[k].elements = ft_lstmallocwrapper(
						&alloced_ptrs, (table[i - 1][j - 1].arr[k].size_elements
						+ 1) * sizeof(int), true);
					ft_memcpy(table[i][j].arr[k].elements,
						table[i - 1][j - 1].arr[k].elements,
						table[i - 1][j - 1].arr[k].size_elements * sizeof(int));
					table[i][j].arr[k].elements[table[i - 1][j - 1].arr[k].
						size_elements] = first_arr.elements[i - 1];
				}
			}
			else
			{
				if (!table[i][j - 1].arr->size_elements
					&& !table[i - 1][j].arr->size_elements)
				{
					table[i][j].size_arr = 0;
					table[i][j].arr = ft_lstmallocwrapper(&alloced_ptrs,
						sizeof(*table[i][j].arr), true);
				}
				else if (table[i][j - 1].arr->size_elements
					== table[i - 1][j].arr->size_elements)
					table[i][j] = combine_two_LCS_array(
						&table[i][j - 1], &table[i - 1][j], &alloced_ptrs);
				else if (table[i][j - 1].arr->size_elements
					> table[i - 1][j].arr->size_elements)
				{
					table[i][j].size_arr = table[i][j - 1].size_arr;
					table[i][j].arr = ft_lstmallocwrapper(&alloced_ptrs,
						table[i][j - 1].size_arr * sizeof(*(table[i][j].arr)),
						true);
					k = -1;
					while (++k < table[i][j - 1].size_arr)
					{
						table[i][j].arr[k].size_elements =
							table[i][j - 1].arr[k].size_elements;
						table[i][j].arr[k].elements
							= table[i][j - 1].arr[k].elements;
					}
				}
				else if (table[i][j - 1].arr->size_elements
					< table[i - 1][j].arr->size_elements)
				{
					table[i][j].size_arr = table[i - 1][j].size_arr;
					table[i][j].arr = ft_lstmallocwrapper(&alloced_ptrs,
						table[i - 1][j].size_arr * sizeof(*(table[i][j].arr)),
						true);
					k = -1;
					while (++k < table[i - 1][j].size_arr)
					{
						table[i][j].arr[k].size_elements =
							table[i - 1][j].arr[k].size_elements;
						table[i][j].arr[k].elements
							= table[i - 1][j].arr[k].elements;
					}
				}
			}
		}
	}
	result.size_elements =
		table[first_arr.size_elements][second_arr.size_elements].arr[0].size_elements;
	result.elements = malloc(result.size_elements * sizeof(int));
	ft_memcpy(result.elements,
		table[first_arr.size_elements][second_arr.size_elements].arr[0].elements,
		result.size_elements * sizeof(int));
	ft_lstmallocfree(&alloced_ptrs);
	return (result);
}

char	*construct_minimum_rotations_needed_ops(t_stack *stack, char stack_name)
{
	char			*result;
	t_node_binary	*min;
	t_node_binary	*cur;
	t_node_binary	*result_lst;
	int				i;

	min = stack->head;
	cur = stack->head;
	i = 0;
	while (++i < stack->n)
	{
		cur = cur->next;
		if (*(int *)cur->content < *(int *)min->content)
			min = cur;
	}
	cur = stack->head;
	i = -1;
	while (++i < stack->n)
	{
		if (cur == min)
			break ;
		cur = cur->next;
	}
	result_lst = NULL;
	if (i > stack->n / 2)
	{
		i = stack->n - i;
		if (stack_name == 'a')
			while (i-- > 0)
				ft_nodbinadd_front(&result_lst, ft_nodbinnew(ft_strdup(" rra")));
		else
			while (i-- > 0)
				ft_nodbinadd_front(&result_lst, ft_nodbinnew(ft_strdup(" rrb")));
	}
	else
	{
		if (stack_name == 'a')
			while (i-- > 0)
				ft_nodbinadd_front(&result_lst, ft_nodbinnew(ft_strdup(" ra")));
		else
			while (i-- > 0)
				ft_nodbinadd_front(&result_lst, ft_nodbinnew(ft_strdup(" rb")));
	}
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
			&& (num < *(int *)cur->content || num > *(int *)cur->prev->content))
			|| (*(int *)cur->content > *(int *)cur->prev->content
			&& num < *(int *)cur->content && num > *(int *)cur->prev->content))
			break ;
		rotations++;
		if (dir)
			cur = cur->next;
		else
			cur = cur->prev;
	}
	return (rotations);
}
