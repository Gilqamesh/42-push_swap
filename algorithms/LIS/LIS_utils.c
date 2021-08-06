/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:31:33 by edavid            #+#    #+#             */
/*   Updated: 2021/08/06 23:56:19 by edavid           ###   ########.fr       */
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

t_INT_array_of_arrays	combine_two_LCS_array(t_INT_array_of_arrays *ARR1,
t_INT_array_of_arrays *ARR2, t_list **alloced_ptrs)
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
		return ((t_INT_array_of_arrays){LCS_group_arr, 0});
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
	return ((t_INT_array_of_arrays){LCS_group_arr, unique_counter});
}

t_INT_array	find_LCS_of_two_sequences(t_INT_array first_arr,
t_INT_array second_arr)
{
	t_INT_array_of_arrays	**table;
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
		// ft_printf("%d\n", i);
		j = 0;
		while (++j < second_arr.size_elements + 1)
		{
			if (first_arr.elements[i - 1] == second_arr.elements[j - 1])
			// Append the end
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
					// Set to empty array
				{
					table[i][j].size_arr = 0;
					table[i][j].arr = ft_lstmallocwrapper(&alloced_ptrs,
						sizeof(*table[i][j].arr), true);
				}
				else if (table[i][j - 1].arr->size_elements
					== table[i - 1][j].arr->size_elements)
					// combine the two
				{
					table[i][j] = combine_two_LCS_array(
						&table[i][j - 1], &table[i - 1][j], &alloced_ptrs);
				}
				else if (table[i][j - 1].arr->size_elements
					> table[i - 1][j].arr->size_elements)
					// save table[i + 1][j] into table[i + 1][j + 1]
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
					// save table[i][j + 1] into table[i + 1][j + 1]
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
	// Could choose between multiple unique LIS solutions
	// Not sure how this affects the final n sequence of ops
	result.size_elements =
		table[first_arr.size_elements][second_arr.size_elements].arr->size_elements;
	result.elements = malloc(result.size_elements * sizeof(int));
	ft_memcpy(result.elements,
		table[first_arr.size_elements][second_arr.size_elements].arr->elements,
		result.size_elements * sizeof(int));
	ft_lstmallocfree(&alloced_ptrs);
	return (result);
}

void	construct_stack_from_arr(t_stack *stack, t_INT_array *arr,
int direction)
{
	int				i;
	int				*tmp;
	t_node_binary	*cur;

	*stack = (t_stack){(t_node_binary *)0, 0};
	if (direction >= 0)
		i = arr->size_elements - 1;
	else
		i = 0;
	while (1)
	{
		tmp = malloc(sizeof(*tmp));
		*tmp = arr->elements[i];
		cur = ft_nodbinnew(tmp);
		ft_nodbinadd_back(&stack->head, cur);
		stack->n++;
		if (direction >= 0)
		{
			if (--i < 0)
				break ;
		}
		else
		{
			if (++i == arr->size_elements)
				break ;
		}
	}
	stack->head->prev = cur;
	cur->next = stack->head;
}

char	*construct_seq_of_operations(t_stack *original_stack, 
t_stack *LIS, char pushed_to_stack, t_stack *unordered_stack,
t_stack *LIS_group, int cur_LIS_group_index)
{
	t_node_binary	*result_lst;
	int				pushed_counter;
	char			*result;
	int				reverse_needed;
	int				condition;
	int				tmp;
	int				i;
	t_node_binary	*tmpptr;

	// ft_printf("In construct_seq_of_operations:\n");
	// ft_nodbinprint_int(original_stack->head, original_stack->n);
	// ft_nodbinprint_int(LIS->head, LIS->n);
	// ft_nodbinprint_int(unordered_stack->head, unordered_stack->n);
	// ft_printf("\n");
	pushed_counter = 0;
	reverse_needed = 0;
	result_lst = NULL;
	condition = original_stack->n - LIS->n;
	while (pushed_counter < condition)
	{
		if (*(int *)original_stack->head->content == *(int *)LIS->head->content)
		{
			if (pushed_to_stack == 'b')
				ft_nodbinadd_front(&result_lst, ft_nodbinnew(ft_strdup(" ra")));
			else
				ft_nodbinadd_front(&result_lst, ft_nodbinnew(ft_strdup(" rb")));
			stack_rotate(LIS);
			stack_rotate(original_stack);
			reverse_needed++;
		}
		else
		{
			if (pushed_counter < condition - 1
				&& *(int *)original_stack->head->next->content != *(int *)LIS->head->content
				&& *(int *)original_stack->head->content < *(int *)original_stack->head->next->content)
			{
				stack_swap(original_stack);
				if (pushed_to_stack == 'b')
					ft_nodbinadd_front(&result_lst, ft_nodbinnew(ft_strdup(" sa")));
				else
					ft_nodbinadd_front(&result_lst, ft_nodbinnew(ft_strdup(" sb")));
			}
			else
			{
				if (pushed_to_stack == 'b')
					ft_nodbinadd_front(&result_lst, ft_nodbinnew(ft_strdup(" pb")));
				else
					ft_nodbinadd_front(&result_lst, ft_nodbinnew(ft_strdup(" pa")));
				stack_push(original_stack, unordered_stack);
				pushed_counter++;
			}
		}
	}
	// TODO:
	// find min path between r and rr maybe
	if (reverse_needed <= LIS->n / 2)
	{
		while (reverse_needed-- > 0)
		{
			if (pushed_to_stack == 'b')
				ft_nodbinadd_front(&result_lst, ft_nodbinnew(ft_strdup(" rra")));
			else
				ft_nodbinadd_front(&result_lst, ft_nodbinnew(ft_strdup(" rrb")));
			stack_revrotate(original_stack);
			stack_revrotate(LIS);
		}
	}
	else
	{
		reverse_needed = LIS->n - reverse_needed;
		while (reverse_needed-- > 0)
		{
			if (pushed_to_stack == 'b')
				ft_nodbinadd_front(&result_lst, ft_nodbinnew(ft_strdup(" ra")));
			else
				ft_nodbinadd_front(&result_lst, ft_nodbinnew(ft_strdup(" rb")));
			stack_rotate(original_stack);
			stack_rotate(LIS);
		}
		tmp = LIS_group[cur_LIS_group_index].n;
		tmpptr = LIS_group[cur_LIS_group_index].head;
		i = cur_LIS_group_index + 1;
		while (--i > 0)
		{
			LIS_group[i].n = LIS_group[i - 1].n;
			LIS_group[i].head = LIS_group[i - 1].head;
		}
		LIS_group[0].n = tmp;
		LIS_group[0].head = tmpptr;
	}
	result = ft_nodbinstrjoin_from_back(result_lst);
	// ft_printf("Result in construct_seq_of_operations: %s\n", result);
	ft_nodbinclear(&result_lst, ft_nodbindel, -1);
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

// Currently operating under the assumption that both LIS are sorted from
// the top.
// char	*merge_LIS_groups(t_push_swap *mystruct, t_stack *from_stack,
// t_stack *to_stack, char pushed_to_stack, t_stack *LIS_group,
// int cur_LIS_group_index)
// {
// 	char			*result;
// 	int				i;
// 	int				reverse_needed;
// 	t_node_binary	*min;
// 	t_node_binary	*cur;
// 	t_stack			tmp;

// 	result = ft_strdup("");
// 	while (from_stack->n)
// 	{
// 		// PRINT_HERE();
// 		// ft_printf("%d\n", from_stack->n);
// 		// if (get_relative_position(mystruct, *(int *)from_stack->head->content)
// 		// 	< get_relative_position(mystruct, *(int *)to_stack->head->content))
// 		// if (! *(int *)from_stack->head->content > *(int *)to_stack->head->content)
// 		stack_push(from_stack, to_stack);
// 		if (!is_stack_sorted(to_stack, 0, 0))
// 		{
// 			stack_push(to_stack, from_stack);
// 			if (pushed_to_stack == 'a')
// 				result = ft_strjoin_free(result, ft_strdup(" ra"));
// 			else
// 				result = ft_strjoin_free(result, ft_strdup(" rb"));
// 			to_stack->head = to_stack->head->next;
// 		}
// 		else
// 		{
// 			// ft_printf("hey\n");
// 			// stack_push(from_stack, to_stack);
// 			if (pushed_to_stack == 'a')
// 				result = ft_strjoin_free(result, ft_strdup(" pa"));
// 			else
// 				result = ft_strjoin_free(result, ft_strdup(" pb"));
// 		}
// 	}
// 	// If rotating to the next LIS would take less operations with
// 	// Forward rotate rather than reverse, do that and also
// 	// In that case we will have to swap our current merged LIS group
// 	// with the bottom one as it'll reside there now.
// 	min = get_min_from_stack(to_stack);
// 	cur = to_stack->head;
// 	reverse_needed = -1;
// 	while (++reverse_needed < to_stack->n)
// 	{
// 		if (cur == min)
// 			break ;
// 		cur = cur->next;
// 	}
// 	// Idea: instead of just rotating, why not push the elements that can be
// 	// pushed to 'from_stack' somehow in the meanwhile
// 	if (reverse_needed > to_stack->n / 2)
// 	{
// 		reverse_needed = to_stack->n - reverse_needed;
// 		while (reverse_needed-- > 0)
// 		{
// 			if (pushed_to_stack == 'a')
// 				result = ft_strjoin_free(result, ft_strdup(" rra"));
// 			else
// 				result = ft_strjoin_free(result, ft_strdup(" rrb"));
// 			to_stack->head = to_stack->head->prev;
// 		}
// 	}
// 	else
// 	{
// 		while (reverse_needed-- > 0)
// 		{
// 			if (pushed_to_stack == 'a')
// 				result = ft_strjoin_free(result, ft_strdup(" ra"));
// 			else
// 				result = ft_strjoin_free(result, ft_strdup(" rb"));
// 			to_stack->head = to_stack->head->next;
// 		}
// 		// PRINT_HERE();
// 		// INSERTING FROM THE BOTTOM
// 		tmp = LIS_group[cur_LIS_group_index];
// 		i = cur_LIS_group_index + 1;
// 		while (--i > 0)
// 			LIS_group[i] = LIS_group[i - 1];
// 		LIS_group[0] = tmp;
// 	}
	
	
// 	// while (reverse_needed--)
// 	// {
// 	// 	if (pushed_to_stack == 'a')
// 	// 		result = ft_strjoin_free(result, ft_strdup(" rra"));
// 	// 	else
// 	// 		result = ft_strjoin_free(result, ft_strdup(" rrb"));
// 	// 	to_stack->head = to_stack->head->prev;
// 	// }
// 	return (result);
// }

int	get_relative_position(t_push_swap *mystruct, int element)
{
	int	i;

	i = -1;
	while (++i < mystruct->relative_pos.n)
	{
		if (mystruct->relative_pos.number_pos[i].a == element)
			return (mystruct->relative_pos.number_pos[i].b);
	}
	return (-1);
}

// With big stack
char	*merge_LIS_groups2(t_stack *from, t_stack *to, char pushed_to_stack,
t_stack *LIS_group, int cur_LIS_group_index, t_stack *from_stack)
{
	char			*result;
	int				reverse_needed;
	int				tmp;
	int				i;
	t_node_binary	*result_lst;

	// ft_printf("Merge_LIS_groups2\n");
	// ft_nodbinprint_int(from->head, from->n);
	// ft_nodbinprint_int(to->head, to->n);
	// ft_printf("\n");
	reverse_needed = 0;
	i = LIS_group[cur_LIS_group_index].n;
	result_lst = NULL;
	while (from_stack->n)
	{
		if (*(int *)from->head->content < *(int *)to->head->content
			|| !i)
		{
			if (pushed_to_stack == 'a')
				ft_nodbinadd_front(&result_lst,
					ft_nodbinnew(ft_strdup(" pa")));
			else
				ft_nodbinadd_front(&result_lst,
					ft_nodbinnew(ft_strdup(" pb")));
			stack_push(from, to);
			from_stack->n--;
			i++;
			LIS_group[cur_LIS_group_index].n++;
		}
		else
		{
			if (pushed_to_stack == 'a')
				ft_nodbinadd_front(&result_lst,
					ft_nodbinnew(ft_strdup(" ra")));
			else
				ft_nodbinadd_front(&result_lst,
					ft_nodbinnew(ft_strdup(" rb")));
			stack_rotate(to);
			reverse_needed++;
			i--;
		}
	}
	if (reverse_needed <= LIS_group[cur_LIS_group_index].n / 2)
	{
		while (reverse_needed-- > 0)
		{
			if (pushed_to_stack == 'a')
				ft_nodbinadd_front(&result_lst,
					ft_nodbinnew(ft_strdup(" rra")));
			else
				ft_nodbinadd_front(&result_lst,
					ft_nodbinnew(ft_strdup(" rrb")));
			to->head = to->head->prev;
		}
	}
	else
	{
		reverse_needed = LIS_group[cur_LIS_group_index].n - reverse_needed;
		while (reverse_needed-- > 0)
		{
			if (pushed_to_stack == 'a')
				ft_nodbinadd_front(&result_lst,
					ft_nodbinnew(ft_strdup(" ra")));
			else
				ft_nodbinadd_front(&result_lst,
					ft_nodbinnew(ft_strdup(" rb")));
			to->head = to->head->next;
		}
		// INSERTING FROM THE BOTTOM
		tmp = LIS_group[cur_LIS_group_index].n;
		i = cur_LIS_group_index + 1;
		while (--i > 0)
			LIS_group[i].n = LIS_group[i - 1].n;
		LIS_group[0].n = tmp;
	}
	result = ft_nodbinstrjoin_from_back(result_lst);
	ft_nodbinclear(&result_lst, ft_nodbindel, -1);
	return (result);
}

char	*push_unordered_away(t_push_swap *mystruct, t_INT_array2 *ord_unord,
char direction_from, char to_stack, char direction_to)
{
	int				cur_ord;
	int				cur_unord;
	t_node_binary	*result_lst;
	char			*result_str;

	result_lst = NULL;
	cur_unord = 0;
	cur_ord = 0;
	if (to_stack == 'b')
	while (cur_unord < ord_unord->arr2.size_elements)
	{
			if (*(int *)mystruct->a.head->content
				== ord_unord->arr2.elements[cur_unord])
			{
				// if (mystruct->a.n > 1 && cur_unord < ord_unord->arr2.size_elements - 1
				// 	&& *(int *)mystruct->a.head->next->content
				// 	== ord_unord->arr2.elements[cur_unord + 1]
				// 	&& *(int *)mystruct->a.head->content
				// 	> *(int *)mystruct->a.head->next->content)
				// {
				// 	if (mystruct->b.n > 1 && *(int *)mystruct->b.head->content
				// 		< *(int *)mystruct->b.head->next->content)
				// 	{
				// 		stack_ss(mystruct);
				// 		ft_nodbinadd_front(&result_lst,
				// 			ft_nodbinnew(ft_strdup(" ss")));
				// 	}
				// 	else
				// 	{
				// 		stack_sa(mystruct);
				// 		ft_nodbinadd_front(&result_lst,
				// 			ft_nodbinnew(ft_strdup(" sa")));
				// 	}
				// 	int	tmp = ord_unord->arr2.elements[cur_unord];
				// 	ord_unord->arr2.elements[cur_unord] = ord_unord->arr2.elements[cur_unord + 1];
				// 	ord_unord->arr2.elements[cur_unord + 1] = tmp;
				// }
				// else
				{
					stack_pb(mystruct);
					ft_nodbinadd_front(&result_lst, ft_nodbinnew(ft_strdup(" pb")));
					cur_unord++;
				}
			}
			else
			{
				stack_ra(mystruct);
				ft_nodbinadd_front(&result_lst, ft_nodbinnew(ft_strdup(" ra")));
			}
	}
	else
	while (cur_ord < ord_unord->arr1.size_elements)
	{
		if (*(int *)mystruct->b.head->content
			!= ord_unord->arr2.elements[cur_unord])
		{
			stack_pa(mystruct);
			// not efficient
			int ra_counter = 0;
			int rra_counter = 0;
			while (!is_stack_sorted(&mystruct->a, 0, 0))
			{
				stack_pb(mystruct);
				stack_ra(mystruct);
				ra_counter++;
				// if (direction_to == 'u')
				// {
				// 	stack_ra(mystruct);
				// 	ft_nodbinadd_front(&result_lst,
				// 		ft_nodbinnew(ft_strdup(" ra")));
				// }
				// else
				// {
				// 	stack_rra(mystruct);
				// 	ft_nodbinadd_front(&result_lst,
				// 		ft_nodbinnew(ft_strdup(" rra")));
				// }
				stack_pa(mystruct);
			}
			stack_pb(mystruct);
			int tmp = ra_counter;
			while (tmp--)
				stack_rra(mystruct);
			stack_pa(mystruct);
			while (!is_stack_sorted(&mystruct->a, 0, 0))
			{
				stack_pb(mystruct);
				stack_rra(mystruct);
				rra_counter++;
				stack_pa(mystruct);
			}
			stack_pb(mystruct);
			tmp = rra_counter;
			while (tmp--)
				stack_ra(mystruct);
			if (ra_counter > rra_counter)
			{
				while (rra_counter--)
				{
					stack_rra(mystruct);
					ft_nodbinadd_front(&result_lst,
						ft_nodbinnew(ft_strdup(" rra")));
				}
			}
			else
			{
				while (ra_counter--)
				{
					stack_ra(mystruct);
					ft_nodbinadd_front(&result_lst,
						ft_nodbinnew(ft_strdup(" ra")));
				}
			}
			stack_pa(mystruct);
			//
			ft_nodbinadd_front(&result_lst, ft_nodbinnew(ft_strdup(" pa")));
			cur_ord++;
		}
		else
		{
			if (direction_from == 'u')
			{
				stack_rrb(mystruct);
				ft_nodbinadd_front(&result_lst,
					ft_nodbinnew(ft_strdup(" rrb")));
				cur_unord++;
			}
			else
			{
				if (mystruct->b.n > 1 && cur_unord < ord_unord->arr2.size_elements - 1
					&& *(int *)mystruct->b.head->next->content
					== ord_unord->arr2.elements[cur_unord + 1]
					&& *(int *)mystruct->b.head->content
					> *(int *)mystruct->b.head->next->content)
				{
					// int	tmp = ord_unord->arr2.elements[cur_unord];
					// ord_unord->arr2.elements[cur_unord] = ord_unord->arr2.elements[cur_unord + 1];
					// ord_unord->arr2.elements[cur_unord + 1] = tmp;
					stack_sb(mystruct);
					ft_nodbinadd_front(&result_lst,
						ft_nodbinnew(ft_strdup(" sb")));
				}
				else
				{
					stack_rb(mystruct);
					ft_nodbinadd_front(&result_lst,
						ft_nodbinnew(ft_strdup(" rb")));
					cur_unord++;
				}
			}
			// cur_unord++;
		}
	}
	result_str = ft_nodbinstrjoin_from_back(result_lst);
	ft_nodbinclear(&result_lst, ft_nodbindel, -1);
	return (result_str);
}
