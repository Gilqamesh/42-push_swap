/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_helper3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:32:57 by edavid            #+#    #+#             */
/*   Updated: 2021/08/11 17:05:34 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_helper3.h"

static void	copy_cell(t_3_int ijk, t_list **alloced_ptrs,
t_INTarrofarr **table, t_INT_array fir_arr)
{
	ijk.c = -1;
	while (++ijk.c < table[ijk.a - 1][ijk.b - 1].size_arr)
	{
		table[ijk.a][ijk.b].arr[ijk.c].size_elements
			= table[ijk.a - 1][ijk.b - 1].arr[ijk.c].size_elements + 1;
		table[ijk.a][ijk.b].arr[ijk.c].elements = ft_lstmallocwrapper(
				alloced_ptrs,
				(table[ijk.a - 1][ijk.b - 1].arr[ijk.c].size_elements
					+ 1) * sizeof(int), true);
		ft_memcpy(table[ijk.a][ijk.b].arr[ijk.c].elements,
			table[ijk.a - 1][ijk.b - 1].arr[ijk.c].elements,
			table[ijk.a - 1][ijk.b - 1].arr[ijk.c].size_elements * sizeof(int));
		table[ijk.a][ijk.b].arr[ijk.c].elements[table[ijk.a - 1][ijk.b - 1]
			.arr[ijk.c].size_elements] = fir_arr.elements[ijk.a - 1];
	}
}

void	append_cell(t_3_int ijk, t_list **alloced_ptrs,
t_INTarrofarr **table, t_INT_array fir_arr)
{
	if (table[ijk.a - 1][ijk.b - 1].size_arr)
	{
		table[ijk.a][ijk.b].size_arr = table[ijk.a - 1][ijk.b - 1].size_arr;
		table[ijk.a][ijk.b].arr = ft_lstmallocwrapper(alloced_ptrs,
				table[ijk.a][ijk.b].size_arr * sizeof(*(table[ijk.a][ijk.b]
						.arr)), true);
	}
	else
	{
		table[ijk.a][ijk.b].size_arr = 1;
		table[ijk.a][ijk.b].arr = ft_lstmallocwrapper(alloced_ptrs,
				sizeof(*table[ijk.a][ijk.b].arr), true);
		table[ijk.a][ijk.b].arr->elements = ft_lstmallocwrapper(
				alloced_ptrs, sizeof(int), true);
		table[ijk.a][ijk.b].arr->size_elements = 1;
		*table[ijk.a][ijk.b].arr->elements = fir_arr.elements[ijk.a - 1];
	}
	copy_cell(ijk, alloced_ptrs, table, fir_arr);
}

static void	select_above_cell(t_3_int ijk, t_list **alloced_ptrs,
t_INTarrofarr **table)
{
	table[ijk.a][ijk.b].size_arr = table[ijk.a][ijk.b - 1].size_arr;
	table[ijk.a][ijk.b].arr = ft_lstmallocwrapper(alloced_ptrs,
			table[ijk.a][ijk.b - 1].size_arr * sizeof(*(table[ijk.a][ijk.b]
					.arr)), true);
	ijk.c = -1;
	while (++ijk.c < table[ijk.a][ijk.b - 1].size_arr)
	{
		table[ijk.a][ijk.b].arr[ijk.c].size_elements
			= table[ijk.a][ijk.b - 1].arr[ijk.c].size_elements;
		table[ijk.a][ijk.b].arr[ijk.c].elements
			= table[ijk.a][ijk.b - 1].arr[ijk.c].elements;
	}
}

static void	select_cell_to_left(t_3_int ijk, t_list **alloced_ptrs,
t_INTarrofarr **table)
{
	table[ijk.a][ijk.b].size_arr = table[ijk.a - 1][ijk.b].size_arr;
	table[ijk.a][ijk.b].arr = ft_lstmallocwrapper(alloced_ptrs,
			table[ijk.a - 1][ijk.b].size_arr * sizeof(*(table[ijk.a][ijk.b]
					.arr)), true);
	ijk.c = -1;
	while (++ijk.c < table[ijk.a - 1][ijk.b].size_arr)
	{
		table[ijk.a][ijk.b].arr[ijk.c].size_elements
			= table[ijk.a - 1][ijk.b].arr[ijk.c].size_elements;
		table[ijk.a][ijk.b].arr[ijk.c].elements
			= table[ijk.a - 1][ijk.b].arr[ijk.c].elements;
	}
}

void	select_longest_cell(t_3_int ijk, t_list **alloced_ptrs,
t_INTarrofarr **table)
{
	if (!table[ijk.a][ijk.b - 1].arr->size_elements
		&& !table[ijk.a - 1][ijk.b].arr->size_elements)
	{
		table[ijk.a][ijk.b].size_arr = 0;
		table[ijk.a][ijk.b].arr = ft_lstmallocwrapper(alloced_ptrs,
				sizeof(*table[ijk.a][ijk.b].arr), true);
	}
	else if (table[ijk.a][ijk.b - 1].arr->size_elements
		== table[ijk.a - 1][ijk.b].arr->size_elements)
		table[ijk.a][ijk.b] = combine_two_LCS_array(
				&table[ijk.a][ijk.b - 1], &table[ijk.a - 1][ijk.b],
				alloced_ptrs);
	else if (table[ijk.a][ijk.b - 1].arr->size_elements
		> table[ijk.a - 1][ijk.b].arr->size_elements)
		select_above_cell(ijk, alloced_ptrs, table);
	else if (table[ijk.a][ijk.b - 1].arr->size_elements
		< table[ijk.a - 1][ijk.b].arr->size_elements)
		select_cell_to_left(ijk, alloced_ptrs, table);
}
