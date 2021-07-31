/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:31:33 by edavid            #+#    #+#             */
/*   Updated: 2021/07/31 16:48:42 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../ft_push_swap.h"

t_INT_array2	find_LIS_of_sublist(t_push_swap *mystruct, t_node_binary *head,
int n)
{
	t_LCS_group	first_seq;
	t_LCS_group	second_seq;
	t_INT_array	unordered;
	int			*helper;
	int			i;
	int			j;
	int			found;

	first_seq.elements = malloc(n * sizeof(*first_seq.elements));
	first_seq.size_elements = n;
	second_seq.elements = malloc(n * sizeof(*second_seq.elements));
	helper = malloc(n * sizeof(*helper));
	second_seq.size_elements = n;
	PRINT_HERE();
	if (!first_seq.elements || !second_seq.elements || !helper)
		ft_error(mystruct);
	i = -1;
	if (n < 0)
	{
		while (++i < -n)
		{
			first_seq.elements[i++] = *(int *)head->content;
			second_seq.elements[i++] = *(int *)head->content;
			head = head->prev;
		}
	}
	else
	{
		PRINT_HERE();
		while (++i < n)
		{
			first_seq.elements[i++] = *(int *)head->content;
			second_seq.elements[i++] = *(int *)head->content;
			head = head->next;
		}
	}
	PRINT_HERE();
	ft_merge_sort_int(second_seq.elements, (t_2_int){0, ft_abs_int(n)}, helper);
	free(helper);
	// Find LCS of arr and sorted. It will be the LIS
	PRINT_HERE();
	t_LCS_group	LIS;
	LIS = find_LCS_of_two_sequences(first_seq, second_seq);
	PRINT_HERE();
	unordered.size_elements = 0;
	unordered.elements = malloc((first_seq.size_elements - LIS.size_elements)
		* sizeof(int));
	i = -1;
	while (++i < first_seq.size_elements)
	{
		j = -1;
		found = 0;
		while (++j < LIS.size_elements)
		{
			if (first_seq.elements[i] == LIS.elements[j])
			{
				found = 1;
				break ;
			}
		}
		if (!found)
			unordered.elements[unordered.size_elements++]
				= first_seq.elements[i];
	}
	free(first_seq.elements);
	free(second_seq.elements);
	return ((t_INT_array2){LIS, unordered});
}

static t_LCS_array	combine_two_LCS_array(t_LCS_array *ptr1, t_LCS_array *ptr2)
{
	int			unique_counter;
	int			i;
	int			j;
	char		**arr_str;
	char		**helper;
	int			arr_str_index;
	char		*tmp;
	char		*tmp2;
	t_LCS_group	*LCS_group_arr;
	int			LCS_index;

	if (!ptr1->size_arr && !ptr2->size_arr)
	{
		LCS_group_arr = ft_calloc(1, sizeof(*LCS_group_arr));
		return ((t_LCS_array){LCS_group_arr, 0});
	}
	ft_printf("ptr->size_arr: %d %d\n", ptr1->size_arr, ptr2->size_arr);
	arr_str = ft_calloc(ptr1->size_arr + ptr2->size_arr, sizeof(*arr_str));
	helper = ft_calloc(ptr1->size_arr + ptr2->size_arr, sizeof(*helper));
	PRINT_HERE();
	arr_str_index = 0;
	i = -1;
	while (++i < ptr1->size_arr)
	{
		j = 0;
		arr_str[arr_str_index] = ft_itoa(ptr1->arr[i].elements[j]);
		PRINT_HERE();
		while (++j < ptr1->arr->size_elements)
		{
			tmp = arr_str[arr_str_index];
			tmp2 = ft_itoa(ptr1->arr[i].elements[j]);
			PRINT_HERE();
			arr_str[arr_str_index] = ft_strjoin(tmp, tmp2);
			PRINT_HERE();
			free(tmp);
			free(tmp2);
			PRINT_HERE();
		}
		arr_str_index++;
	}
	i = -1;
	while (++i < ptr2->size_arr)
	{
		j = 0;
		arr_str[arr_str_index] = ft_itoa(ptr2->arr[i].elements[j]);
		PRINT_HERE();
		while (++j < ptr2->arr->size_elements)
		{
			tmp = arr_str[arr_str_index];
			tmp2 = ft_itoa(ptr2->arr[i].elements[j]);
			PRINT_HERE();
			arr_str[arr_str_index] = ft_strjoin(tmp, ".");
			arr_str[arr_str_index] = ft_strjoin(tmp, tmp2);
			free(tmp);
			free(tmp2);
			PRINT_HERE();
		}
		arr_str_index++;
	}
	ft_merge_sort_str(arr_str, (t_2_int){0, ptr1->size_arr + ptr2->size_arr},
		helper);
	ft_printf("ptr1->size arr: %d %d\n", ptr1->size_arr, ptr2->size_arr);
	for (int l = 0; l < ptr1->size_arr + ptr2->size_arr; l++)
		ft_printf("%s\n", arr_str[l]);
	PRINT_HERE();
	unique_counter = 1;
	i = 0;
	while (++i < ptr1->size_arr + ptr2->size_arr)
		if (ft_strcmp(arr_str[i], arr_str[i - 1]))
			unique_counter++;
	PRINT_HERE();
	// save all sequences in the table
	LCS_group_arr = malloc(unique_counter * sizeof(*LCS_group_arr));
	PRINT_HERE();
	i = -1;
	j = 0;
	while (++i < unique_counter)
	{
		LCS_group_arr[i].elements = malloc(ptr1->arr->size_elements
			* sizeof(int));
		PRINT_HERE();
		LCS_group_arr[i].size_elements = ptr1->arr->size_elements;
		PRINT_HERE();
		if (!j)
		{
			tmp = arr_str[j];
			PRINT_HERE();
		}
		else
		{
			j++;
			PRINT_HERE();
			while (!ft_strcmp(arr_str[j], arr_str[j - 1]))
				;
			PRINT_HERE();
			tmp = arr_str[j];
		}
		LCS_index = 0;
		PRINT_HERE();
		ft_printf("tmp: %p\n", tmp);
		ft_printf("Value of tmp: %s\n", tmp);
		LCS_group_arr[i].elements[LCS_index] = ft_atoi(tmp);
		PRINT_HERE();
		while (++LCS_index < ptr1->arr->size_elements)
			while (*tmp++ != '.')
				LCS_group_arr[i].elements[LCS_index] = ft_atoi(tmp);
		PRINT_HERE();
	}
	i = -1;
	while (++i < ptr1->size_arr + ptr2->size_arr)
		free(arr_str[i]);
	PRINT_HERE();
	free(arr_str);
	free(helper);
	PRINT_HERE();
	return ((t_LCS_array){LCS_group_arr, unique_counter});
}

t_LCS_group	find_LCS_of_two_sequences(t_LCS_group first_seq,
t_LCS_group second_seq)
{
	t_LCS_array	**table;
	t_LCS_group	result;
	int			i;
	int			j;
	int			k;

	table = malloc((first_seq.size_elements + 1) * sizeof(*table));
	i = -1;
	while (++i < first_seq.size_elements + 1)
		table[i] = malloc((second_seq.size_elements + 1) * sizeof(**table));
	i = -1;
	PRINT_HERE();
	while (++i < first_seq.size_elements + 1)
		table[i][0].arr = ft_calloc(1, sizeof(*table[i][0].arr));
	i = 0;
	while (++i < second_seq.size_elements + 1)
		table[0][i].arr = ft_calloc(1, sizeof(*table[0][i].arr));
	i = 0;
	PRINT_HERE();
	while (++i < first_seq.size_elements + 1)
	{
		j = 0;
		while (++j < second_seq.size_elements + 1)
		{
			PRINT_HERE();
			if (first_seq.elements[i - 1] == second_seq.elements[j - 1])
			{
				PRINT_HERE();
				// append table[i][j] with first_seq.elements[i - 1]
				// and set table[i + 1][j + 1] to it
				table[i][j].size_arr = table[i - 1][j - 1].size_arr;
				table[i][j].arr = malloc(table[i - 1][j - 1].size_arr
					* sizeof(*(table[i][j].arr)));
				k = -1;
				while (++k < table[i - 1][j - 1].size_arr)
				{
					PRINT_HERE();
					table[i][j].arr[k].size_elements =
						table[i][j].arr[k].size_elements + 1;
					table[i - 1][j - 1].arr[k].elements = malloc(
						(table[i - 1][j - 1].arr[k].size_elements + 1)
						* sizeof(int));
					ft_memcpy(table[i][j].arr[k].elements,
						table[i - 1][j - 1].arr[k].elements,
						table[i - 1][j - 1].arr[k].size_elements * sizeof(int));
					table[i][j].arr[k].elements[table[i - 1][j - 1].arr[k].
						size_elements] = first_seq.elements[i - 1];
				}
			}
			else
			{
				PRINT_HERE();
				// table[i + 1][j + 1] will be max of table[i + 1, j] and
				// table[i][j + 1]
				// ERROR HAPPENS HERE
				ft_printf("i: %d, j: %d\n", i, j);
				ft_printf("Val: %d\n", table[i][j - 1].arr->size_elements);
				ft_printf("Val: %d\n", table[i - 1][j].arr->size_elements);
				if (table[i][j - 1].arr->size_elements
					== table[i - 1][j].arr->size_elements)
					// combine the two
				{
					PRINT_HERE();
					// ERROR
					// table[i][j - 1].size_array is not updated here
					table[i][j] = combine_two_LCS_array(
						&table[i][j - 1], &table[i - 1][j]);
					PRINT_HERE();
				}
				else if (table[i][j - 1].arr->size_elements
					> table[i - 1][j].arr->size_elements)
					// save table[i + 1][j] into table[i + 1][j + 1]
				{
					PRINT_HERE();
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
					table[i][j].size_arr = table[i - 1][j].size_arr;
					table[i][j].arr = malloc(table[i - 1][j].size_arr
						* sizeof(*(table[i][j].arr)));
					k = -1;
					while (++k < table[i - 1][j].size_arr)
					{
						PRINT_HERE();
						table[i][j].arr[k].size_elements =
							table[i - 1][j].arr[k].size_elements;
						table[i][j].arr[k].elements = malloc(
							table[i - 1][j].arr[k].size_elements * sizeof(int));
						ft_memcpy(table[i][j].arr[k].elements,
							table[i - 1][j].arr[k].elements,
							table[i - 1][j].arr[k].size_elements * sizeof(int));
					}
				}
			}
		}
	}
	PRINT_HERE();
	result.size_elements =
		table[first_seq.size_elements][second_seq.size_elements].arr->size_elements;
	result.elements = malloc(result.size_elements * sizeof(int));
	ft_memcpy(result.elements,
		table[first_seq.size_elements][second_seq.size_elements].arr->elements,
		result.size_elements * sizeof(int));
	return (result);
}

void	construct_stack_from_arr(t_stack *stack, t_INT_array *arr)
{
	int				i;
	int				*tmp;
	t_node_binary	*cur;

	*stack = (t_stack){(t_node_binary *)0, arr->size_elements};
	i = arr->size_elements;
	while (i--)
	{
		tmp = malloc(sizeof(*tmp));
		*tmp = arr->elements[i];
		cur = ft_nodbinnew(tmp);
		ft_nodbinadd_back(&stack->head, cur);
	}
	stack->head->prev = cur;
	cur->next = stack->head;
}

char	*construct_seq_of_operations(t_stack *original_stack, 
t_stack *pushed_stack, char pushed_to_stack)
{
	t_node_binary	*cur_origin;
	t_node_binary	*cur_pushed;
	char			*result;
	int				i;

	result = ft_strdup("");
	i = -1;
	cur_origin = original_stack->head;
	cur_pushed = pushed_stack->head;
	while (++i < original_stack->n)
	{
		if (*(int *)cur_origin->content == *(int *)cur_pushed)
		{
			if (pushed_to_stack == 'a')
				result = ft_strjoin_free(result, ft_strjoin(" p", "b"));
			else
				result = ft_strjoin_free(result, ft_strjoin(" p", "a"));
			cur_pushed = cur_pushed->next;
		}
		else
		{
			if (pushed_to_stack == 'b')
				result = ft_strjoin_free(result, ft_strjoin(" r", "a"));
			else
				result = ft_strjoin_free(result, ft_strjoin(" p", "b"));
		}
		cur_origin = cur_origin->next;
	}
	return (result);
}
