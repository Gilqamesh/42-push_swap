/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:31:33 by edavid            #+#    #+#             */
/*   Updated: 2021/08/03 20:59:44 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../ft_push_swap.h"

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
	// PRINT_HERE();
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
		// PRINT_HERE();
		while (++i < n)
		{
			first_arr.elements[i] = *(int *)cur->content;
			second_arr.elements[i] = *(int *)cur->content;
			cur = cur->next;
		}
	}
	// ft_printf("n: %d print_arr: ", n);
	// ft_printintarr(first_arr.elements, first_arr.size_elements);
	// PRINT_HERE();
	ft_merge_sort_int(second_arr.elements, (t_2_int){0, ft_abs_int(n)}, helper);
	free(helper);
	// Find LCS of arr and sorted. It will be the LIS
	// PRINT_HERE();
	t_INT_array	LIS;
	// ft_printintarr(first_arr.elements, first_arr.size_elements);
	// ft_printintarr(second_arr.elements, second_arr.size_elements);
	LIS = find_LCS_of_two_sequences(first_arr, second_arr);
	// ft_printf("seq size: %d %d\n", first_arr.size_elements, second_arr.size_elements);
	// ft_printf("LIS.size_elements: %d\n", LIS.size_elements);
	// ft_printintarr(LIS.elements, LIS.size_elements);
	// PRINT_HERE();
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
	// ft_printintarr(LIS.elements, LIS.size_elements);
	// ft_printintarr(unordered.elements, unordered.size_elements);
	return ((t_INT_array2){LIS, unordered});
}

t_INT_array_of_arrays	combine_two_LCS_array(t_INT_array_of_arrays *ARR1, t_INT_array_of_arrays *ARR2)
{
	int			unique_counter;
	int			i;
	int			j;
	char		**arr_str;
	char		**helper;
	int			arr_str_index;
	char		*tmp;
	char		*tmp2;
	t_INT_array	*LCS_group_arr;
	int			LCS_index;

	if (!ARR1 || !ARR2 || (!ARR1->size_arr && !ARR2->size_arr))
	{
		LCS_group_arr = ft_calloc(1, sizeof(*LCS_group_arr));
		return ((t_INT_array_of_arrays){LCS_group_arr, 0});
	}
	// ft_printf("ptr->size_arr: %d %d\n", ARR1->size_arr, ARR2->size_arr);
	arr_str = ft_calloc(ARR1->size_arr + ARR2->size_arr, sizeof(*arr_str));
	helper = ft_calloc(ARR1->size_arr + ARR2->size_arr, sizeof(*helper));
	// PRINT_HERE();
	arr_str_index = 0;
	i = -1;
	while (++i < ARR1->size_arr)
	{
		j = 0;
		arr_str[arr_str_index] = ft_itoa(ARR1->arr[i].elements[j]);
		// PRINT_HERE();
		while (++j < ARR1->arr->size_elements)
		{
			tmp = arr_str[arr_str_index];
			arr_str[arr_str_index] = ft_strjoin(tmp, ".");
			free(tmp);
			arr_str[arr_str_index] = ft_strjoin_free(arr_str[arr_str_index],
				ft_itoa(ARR1->arr[i].elements[j]));
			// PRINT_HERE();
		}
		arr_str_index++;
	}
	i = -1;
	while (++i < ARR2->size_arr)
	{
		j = 0;
		arr_str[arr_str_index] = ft_itoa(ARR2->arr[i].elements[0]);
		// PRINT_HERE();
		while (++j < ARR2->arr->size_elements)
		{
			tmp = arr_str[arr_str_index];
			arr_str[arr_str_index] = ft_strjoin(tmp, ".");
			free(tmp);
			arr_str[arr_str_index] = ft_strjoin_free(arr_str[arr_str_index],
				ft_itoa(ARR2->arr[i].elements[j]));
			// PRINT_HERE();
		}
		arr_str_index++;
	}
	// ft_printf("ARR1->size arr: %d %d\n", ARR1->size_arr, ARR2->size_arr);
	// for (int l = 0; l < ARR1->size_arr + ARR2->size_arr; l++)
		// ft_printf("%s\n", arr_str[l]);
	ft_merge_sort_str(arr_str, (t_2_int){0, ARR1->size_arr + ARR2->size_arr},
		helper);
	free(helper);
	// ft_printf("ARR1->size arr: %d %d\n", ARR1->size_arr, ARR2->size_arr);
	// for (int l = 0; l < ARR1->size_arr + ARR2->size_arr; l++)
	// 	ft_printf("%s\n", arr_str[l]);
	// PRINT_HERE();
	unique_counter = 1;
	i = 0;
	while (++i < ARR1->size_arr + ARR2->size_arr)
		if (ft_strcmp(arr_str[i], arr_str[i - 1]))
			unique_counter++;
	// PRINT_HERE();
	// save all sequences in the table
	LCS_group_arr = malloc(unique_counter * sizeof(*LCS_group_arr));
	// PRINT_HERE();
	i = -1;
	j = 0;
	while (++i < unique_counter)
	{
		LCS_group_arr[i].elements = malloc(ARR1->arr->size_elements
			* sizeof(int));
		// PRINT_HERE();
		LCS_group_arr[i].size_elements = ARR1->arr->size_elements;
		// PRINT_HERE();
		if (!j)
		{
			tmp = arr_str[j];
			j++;
			// PRINT_HERE();
		}
		else
		{
			// PRINT_HERE();
			while (!ft_strcmp(arr_str[j], arr_str[j - 1]))
				j++;
			// PRINT_HERE();
			tmp = arr_str[j];
			j++;
		}
		// PRINT_HERE();
		// ft_printf("tmp: %p\n", tmp);
		// ft_printf("Value of tmp: %s\n", tmp);
		LCS_index = 0;
		// ft_printf("%s, j: %d\n", tmp, j);
		LCS_group_arr[i].elements[0] = ft_atoi(tmp);
		// PRINT_HERE();
		while (++LCS_index < ARR1->arr->size_elements)
		{
			while (*tmp != '.')
				tmp++;
			tmp++;
			LCS_group_arr[i].elements[LCS_index] = ft_atoi(tmp);
		}
		// PRINT_HERE();
	}
	i = -1;
	while (++i < ARR1->size_arr + ARR2->size_arr)
		free(arr_str[i]);
	// PRINT_HERE();
	free(arr_str);
	// PRINT_HERE();
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

	// ft_printf("Size of first_arr and second_arr: %d %d\n", first_arr.size_elements,
	// 	second_arr.size_elements);
	table = malloc((first_arr.size_elements + 1) * sizeof(*table));
	i = -1;
	while (++i < first_arr.size_elements + 1)
		table[i] = malloc((second_arr.size_elements + 1) * sizeof(**table));
	i = -1;
	// PRINT_HERE();
	while (++i < first_arr.size_elements + 1)
	{
		table[i][0].size_arr = 0;
		table[i][0].arr = ft_calloc(1, sizeof(*table[i][0].arr));
	}
	i = 0;
	while (++i < second_arr.size_elements + 1)
	{
		table[0][i].size_arr = 0;
		table[0][i].arr = ft_calloc(1, sizeof(*table[0][i].arr));
	}
	i = 0;
	// PRINT_HERE();
	while (++i < first_arr.size_elements + 1)
	{
		j = 0;
		while (++j < second_arr.size_elements + 1)
		{
			// PRINT_HERE();
			// I think this works
			if (first_arr.elements[i - 1] == second_arr.elements[j - 1])
			{
				// PRINT_HERE();
				if (table[i - 1][j - 1].size_arr)
				{
					table[i][j].size_arr = table[i - 1][j - 1].size_arr;
					table[i][j].arr = malloc(table[i][j].size_arr
						* sizeof(*(table[i][j].arr)));
				}
				else
				{
					table[i][j].size_arr = 1;
					table[i][j].arr = ft_calloc(1, sizeof(*table[i][j].arr));
					table[i][j].arr->elements = malloc(sizeof(int));
					table[i][j].arr->size_elements = 1;
					*table[i][j].arr->elements = first_arr.elements[i - 1];
				}
				k = -1;
				while (++k < table[i - 1][j - 1].size_arr)
				{
					// PRINT_HERE();
					table[i][j].arr[k].size_elements =
						table[i - 1][j - 1].arr[k].size_elements + 1;
					table[i][j].arr[k].elements = malloc(
						(table[i - 1][j - 1].arr[k].size_elements + 1)
						* sizeof(int));
					ft_memcpy(table[i][j].arr[k].elements,
						table[i - 1][j - 1].arr[k].elements,
						table[i - 1][j - 1].arr[k].size_elements * sizeof(int));
					table[i][j].arr[k].elements[table[i - 1][j - 1].arr[k].
						size_elements] = first_arr.elements[i - 1];
				}
			}
			else
			{
				// // PRINT_HERE();
				// table[i + 1][j + 1] will be max of table[i + 1, j] and
				// table[i][j + 1]
				// ERROR HAPPENS HERE
				// ft_printf("i: %d, j: %d\n", i, j);
				// ft_printf("Val: %d\n", table[i][j - 1].arr->size_elements);
				// ft_printf("Val: %d\n", table[i - 1][j].arr->size_elements);
				// ft_printf("%d %d\n", i, j);
				if (!table[i][j - 1].arr->size_elements
					&& !table[i - 1][j].arr->size_elements)
				{
					// PRINT_HERE();
					table[i][j].size_arr = 0;
					table[i][j].arr = ft_calloc(1, sizeof(*table[i][j].arr));
					// PRINT_HERE();
				}
				else if (table[i][j - 1].arr->size_elements
					== table[i - 1][j].arr->size_elements)
					// combine the two
				{
					// PRINT_HERE();
					// ERROR
					// table[i][j - 1].size_array is not updated here
					// NEED TO DEBUG THIS!!!!
					// PRINT_HERE();
					table[i][j] = combine_two_LCS_array(
						&table[i][j - 1], &table[i - 1][j]);
					// PRINT_HERE();
					// PRINT_HERE();
				}
				else if (table[i][j - 1].arr->size_elements
					> table[i - 1][j].arr->size_elements)
					// save table[i + 1][j] into table[i + 1][j + 1]
				{
					// PRINT_HERE();
					table[i][j].size_arr = table[i][j - 1].size_arr;
					table[i][j].arr = malloc(table[i][j - 1].size_arr
						* sizeof(*(table[i][j].arr)));
					k = -1;
					while (++k < table[i][j - 1].size_arr)
					{
						table[i][j].arr[k].size_elements =
							table[i][j - 1].arr[k].size_elements;
						table[i][j].arr[k].elements = malloc(
							table[i][j - 1].arr[k].size_elements * sizeof(int));
						ft_memcpy(table[i][j].arr[k].elements,
							table[i][j - 1].arr[k].elements,
							table[i][j - 1].arr[k].size_elements * sizeof(int));
					}
				}
				else if (table[i][j - 1].arr->size_elements
					< table[i - 1][j].arr->size_elements)
					// save table[i][j + 1] into table[i + 1][j + 1]
				{
					// PRINT_HERE();
					table[i][j].size_arr = table[i - 1][j].size_arr;
					table[i][j].arr = malloc(table[i - 1][j].size_arr
						* sizeof(*(table[i][j].arr)));
					// PRINT_HERE();
					k = -1;
					while (++k < table[i - 1][j].size_arr)
					{
						// PRINT_HERE();
						table[i][j].arr[k].size_elements =
							table[i - 1][j].arr[k].size_elements;
						table[i][j].arr[k].elements = malloc(
							table[i - 1][j].arr[k].size_elements * sizeof(int));
						ft_memcpy(table[i][j].arr[k].elements,
							table[i - 1][j].arr[k].elements,
							table[i - 1][j].arr[k].size_elements * sizeof(int));
					}
					// PRINT_HERE();
				}
			}
			// if (table[i][j].size_arr)
			// 	ft_printintarr(table[i][j].arr->elements, table[i][j].arr->size_elements);
		}
	}
	// PRINT_HERE();
	// ft_printf("In: %s\n", __FILENAME__);
	// ft_printf("This is the end result:\n");
	// ft_printintarr(table[first_arr.size_elements][second_arr.size_elements].arr->elements,
	// 	table[first_arr.size_elements][second_arr.size_elements].arr->size_elements);
	result.size_elements =
		table[first_arr.size_elements][second_arr.size_elements].arr->size_elements;
	result.elements = malloc(result.size_elements * sizeof(int));
	ft_memcpy(result.elements,
		table[first_arr.size_elements][second_arr.size_elements].arr->elements,
		result.size_elements * sizeof(int));
	// ft_printf("result.size_elements: %d\n", result.size_elements);
	// ft_printintarr(result.elements, result.size_elements);
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
t_stack *LIS, char pushed_to_stack)
{
	t_node_binary	*cur_origin;
	int				pushed_counter;
	char			*result;
	int				reverse_needed;

	result = ft_strdup("");
	cur_origin = original_stack->head;
	pushed_counter = 0;
	reverse_needed = 0;
	while (pushed_counter != original_stack->n - LIS->n)
	{
		if (*(int *)cur_origin->content == *(int *)LIS->head->content)
		{
			if (pushed_to_stack == 'b')
				result = ft_strjoin_free(result, ft_strjoin(" r", "a"));
			else
				result = ft_strjoin_free(result, ft_strjoin(" r", "b"));
			LIS->head = LIS->head->next;
			reverse_needed++;
		}
		else
		{
			if (pushed_to_stack == 'a')
				result = ft_strjoin_free(result, ft_strjoin(" p", "a"));
			else
				result = ft_strjoin_free(result, ft_strjoin(" p", "b"));
			pushed_counter++;	
		}
		cur_origin = cur_origin->next;
	}
	// CHECK IF THIS IS CORRECT OR NOT
	while (reverse_needed--)
	{
		if (pushed_to_stack == 'b')
				result = ft_strjoin_free(result, ft_strjoin(" rr", "a"));
			else
				result = ft_strjoin_free(result, ft_strjoin(" rr", "b"));
			LIS->head = LIS->head->prev;
	}
	return (result);
}

char	*construct_minimum_rotations_needed_ops(t_stack *stack, char stack_name)
{
	char			*result;
	t_node_binary	*min;
	t_node_binary	*cur;
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
	result = ft_strdup("");
	if (i > stack->n / 2)
	{
		i = stack->n - i;
		if (stack_name == 'a')
			while (i-- > 0)
				result = ft_strjoin_free(result, ft_strdup(" rra"));
		else
			while (i-- > 0)
				result = ft_strjoin_free(result, ft_strdup(" rrb"));
	}
	else
	{
		if (stack_name == 'a')
			while (i-- > 0)
				result = ft_strjoin_free(result, ft_strdup(" ra"));
		else
			while (i-- > 0)
				result = ft_strjoin_free(result, ft_strdup(" rb"));
	}
	return (result);
}

char	*merge_LIS_groups(t_stack *from_stack, t_stack *to_stack,
char pushed_to_stack)
{
	char			*result;
	int				i;
	int				reverse_needed;

	result = ft_strdup("");
	reverse_needed = 0;
	while (from_stack->n)
	{
		stack_push(from_stack, to_stack);
		if (!is_stack_sorted(to_stack, 0))
		{
			stack_push(to_stack, from_stack);
			if (pushed_to_stack == 'a')
				result = ft_strjoin_free(result, ft_strdup(" ra"));
			else
				result = ft_strjoin_free(result, ft_strdup(" rb"));
			to_stack->head = to_stack->head->next;
			reverse_needed++;
		}
		else
		{
			if (pushed_to_stack == 'a')
				result = ft_strjoin_free(result, ft_strdup(" pa"));
			else
				result = ft_strjoin_free(result, ft_strdup(" pb"));
		}
	}
	// rotate back to_stack so that its sorted from min element
	// Maybe this can be worked around by adding the rotated elements from
	// to_stack
	// the LIS_group[0]
	while (reverse_needed--)
	{
		if (pushed_to_stack == 'a')
			result = ft_strjoin_free(result, ft_strdup(" rra"));
		else
			result = ft_strjoin_free(result, ft_strdup(" rrb"));
		to_stack->head = to_stack->head->prev;
	}
	return (result);
}
