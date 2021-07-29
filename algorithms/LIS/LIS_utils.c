/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 12:31:33 by edavid            #+#    #+#             */
/*   Updated: 2021/07/29 16:47:01 by edavid           ###   ########.fr       */
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
		while (++i < n)
		{
			first_seq.elements[i++] = *(int *)head->content;
			second_seq.elements[i++] = *(int *)head->content;
			head = head->next;
		}
	}
	ft_merge_sort_int(second_seq.elements, (t_2_int){0, ft_abs_int(n)}, helper);
	free(helper);
	// Find LCS of arr and sorted. It will be the LIS
	t_LCS_group	LIS;
	LIS = find_LCS_of_two_sequences(first_seq, second_seq);
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

	arr_str = ft_calloc(ptr1->size_arr + ptr2->size_arr, sizeof(*arr_str));
	helper = ft_calloc(ptr1->size_arr + ptr2->size_arr, sizeof(*helper));
	arr_str_index = 0;
	i = -1;
	while (++i < ptr1->size_arr)
	{
		j = 0;
		arr_str[arr_str_index] = ft_itoa(ptr1->arr[i].elements[j]);
		while (++j < ptr1->arr->size_elements)
		{
			tmp = arr_str[arr_str_index];
			tmp2 = ft_itoa(ptr1->arr[i].elements[j]);
			arr_str[arr_str_index] = ft_strjoin(tmp, tmp2);
			free(tmp);
			free(tmp2);
		}
		arr_str_index++;
	}
	i = -1;
	while (++i < ptr2->size_arr)
	{
		j = 0;
		arr_str[arr_str_index] = ft_itoa(ptr2->arr[i].elements[j]);
		while (++j < ptr2->arr->size_elements)
		{
			tmp = arr_str[arr_str_index];
			tmp2 = ft_itoa(ptr2->arr[i].elements[j]);
			arr_str[arr_str_index] = ft_strjoin(tmp, ".");
			arr_str[arr_str_index] = ft_strjoin(tmp, tmp2);
			free(tmp);
			free(tmp2);
		}
		arr_str_index;
	}
	ft_merge_sort_str(arr_str, (t_2_int){0, ptr1->size_arr + ptr2->size_arr},
		helper);
	unique_counter = 1;
	i = 0;
	while (++i < ptr1->size_arr + ptr2->size_arr)
		if (ft_strcmp(arr_str[i], arr_str[i - 1]))
			unique_counter++;
	// save all sequences in the table
	LCS_group_arr = malloc(unique_counter * sizeof(*LCS_group_arr));
	i = -1;
	j = 0;
	while (++i < unique_counter)
	{
		LCS_group_arr[i].elements = malloc(ptr1->arr->size_elements
			* sizeof(int));
		LCS_group_arr[i].size_elements = ptr1->arr->size_elements;
		if (!j)
			tmp = arr_str[j];
		else
		{
			while (!ft_strcmp(arr_str[++j], arr_str[j - 1]))
				;
			tmp = arr_str[j];
		}
		LCS_index = 0;
		LCS_group_arr[i].elements[LCS_index] = ft_atoi(tmp);
		while (++LCS_index < ptr1->arr->size_elements)
			while (*tmp++ != '.')
				LCS_group_arr[i].elements[LCS_index] = ft_atoi(tmp);
	}
	i = -1;
	while (++i < ptr1->size_arr + ptr2->size_arr)
		free(arr_str[i]);
	free(arr_str);
	free(helper);
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
	while (++i < second_seq.size_elements)
		table[i] = ft_calloc(second_seq.size_elements + 1, sizeof(**table));
	i = 0;
	while (++i < first_seq.size_elements + 1)
	{
		j = 0;
		while (++j < second_seq.size_elements + 1)
		{
			if (first_seq.elements[i - 1] == second_seq.elements[j - 1])
			{
				// append table[i][j] with first_seq.elements[i - 1]
				// and set table[i + 1][j + 1] to it
				table[i + 1][j + 1].size_arr = table[i][j].size_arr;
				table[i + 1][j + 1].arr = malloc(table[i][j].size_arr
					* sizeof(*(table[i + 1][j + 1].arr)));
				k = -1;
				while (++k < table[i][j].size_arr)
				{
					table[i + 1][j + 1].arr[k].size_elements =
						table[i][j].arr[k].size_elements + 1;
					table[i + 1][j + 1].arr[k].elements = malloc(
						table[i][j].arr[k].size_elements + 1 * sizeof(int));
					ft_memcpy(table[i + 1][j + 1].arr[k].elements,
						table[i][j].arr[k].elements,
						table[i][j].arr[k].size_elements * sizeof(int));
					table[i + 1][j + 1].arr[k].elements[table[i][j].arr[k].
						size_elements] = first_seq.elements[i - 1];
				}
			}
			else
			{
				// table[i + 1][j + 1] will be max of table[i + 1, j] and
				// table[i][j + 1]
				if (table[i + 1][j].arr->size_elements
					== table[i][j + 1].arr->size_elements)
					// combine the two
					table[i + 1][j + 1] = combine_two_LCS_array(
						&table[i + 1][j],&table[i][j + 1]);
				else if (table[i + 1][j].arr->size_elements
					> table[i][j + 1].arr->size_elements)
					// save table[i + 1][j] into table[i + 1][j + 1]
				{
					table[i + 1][j + 1].size_arr = table[i + 1][j].size_arr;
					table[i + 1][j + 1].arr = malloc(table[i + 1][j].size_arr
						* sizeof(*(table[i + 1][j + 1].arr)));
					k = -1;
					while (++k < table[i + 1][j].size_arr)
					{
						table[i + 1][j + 1].arr[k].size_elements =
							table[i + 1][j].arr[k].size_elements;
						table[i + 1][j + 1].arr[k].elements = malloc(
							table[i + 1][j].arr[k].size_elements * sizeof(int));
						ft_memcpy(table[i + 1][j + 1].arr[k].elements,
							table[i + 1][j].arr[k].elements,
							table[i + 1][j].arr[k].size_elements * sizeof(int));
					}
				}
				else if (table[i + 1][j].arr->size_elements
					< table[i][j + 1].arr->size_elements)
					// save table[i][j + 1] into table[i + 1][j + 1]
				{
					table[i + 1][j + 1].size_arr = table[i][j + 1].size_arr;
					table[i + 1][j + 1].arr = malloc(table[i][j + 1].size_arr
						* sizeof(*(table[i + 1][j + 1].arr)));
					k = -1;
					while (++k < table[i][j + 1].size_arr)
					{
						table[i + 1][j + 1].arr[k].size_elements =
							table[i][j + 1].arr[k].size_elements;
						table[i + 1][j + 1].arr[k].elements = malloc(
							table[i][j + 1].arr[k].size_elements * sizeof(int));
						ft_memcpy(table[i + 1][j + 1].arr[k].elements,
							table[i][j + 1].arr[k].elements,
							table[i][j + 1].arr[k].size_elements * sizeof(int));
					}
				}
			}
		}
	}
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
	t_node_binary	*head;

	*stack = (t_stack){(t_node_binary *)0, 0};
	i = -1;
	while (++i < arr->size_elements)
	{
		tmp = malloc(sizeof(*tmp));
		*tmp = arr->elements[i];
		ft_nodbinadd_front(&stack->head, ft_nodbinnew(tmp));
		if (!i)
			head = stack->head;
	}
	head->
}
