/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_helper2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:58:01 by edavid            #+#    #+#             */
/*   Updated: 2021/08/11 16:38:03 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_helper2.h"
#include "utils_helper3.h"

void	set_unique_counter_helper_helper(t_INTarrofarr *ARR1,
t_INTarrofarr *ARR2, int *i, int *j)
{
	int	compared_value;

	compared_value = ft_intarrcmp(&ARR1->arr[*i], &ARR2->arr[*j]);
	if (!compared_value)
	{
		(*i)++;
		(*j)++;
	}
	else if (compared_value < 0)
		(*i)++;
	else
		(*j)++;
}

void	combine_helper_helper(t_INTarrofarr *ARR1,
t_INTarrofarr *ARR2, t_INT_array *LCS_g_arr, t_3_int *i_j_k)
{
	int	compared_value;

	compared_value = ft_intarrcmp(&ARR1->arr[i_j_k->a], &ARR2->arr[i_j_k->b]);
	if (!compared_value)
	{
		LCS_g_arr[i_j_k->c].size_elements = ARR1->arr[i_j_k->a].size_elements;
		LCS_g_arr[i_j_k->c].elements = ARR1->arr[i_j_k->a].elements;
		i_j_k->a++;
		i_j_k->b++;
	}
	else if (compared_value < 0)
	{
		LCS_g_arr[i_j_k->c].size_elements = ARR1->arr[i_j_k->a].size_elements;
		LCS_g_arr[i_j_k->c].elements = ARR1->arr[i_j_k->a].elements;
		i_j_k->a++;
	}
	else
	{
		LCS_g_arr[i_j_k->c].size_elements
			= ARR2->arr[i_j_k->b].size_elements;
		LCS_g_arr[i_j_k->c].elements
			= ARR2->arr[i_j_k->b].elements;
		i_j_k->b++;
	}
}

void	init_table(t_list **alloced_ptrs, t_INTarrofarr ***table,
t_INT_array fir_arr, t_INT_array sec_arr)
{
	int	i;

	*alloced_ptrs = NULL;
	*table = ft_lstmallocwrapper(alloced_ptrs,
			(fir_arr.size_elements + 1) * sizeof(**table), true);
	i = -1;
	while (++i < fir_arr.size_elements + 1)
		(*table)[i] = ft_lstmallocwrapper(alloced_ptrs,
				(sec_arr.size_elements + 1) * sizeof(***table), true);
	i = -1;
	while (++i < fir_arr.size_elements + 1)
	{
		(*table)[i][0].size_arr = 0;
		(*table)[i][0].arr = ft_lstmallocwrapper(alloced_ptrs,
				sizeof(*(*table)[i][0].arr), true);
	}
	i = 0;
	while (++i < sec_arr.size_elements + 1)
	{
		(*table)[0][i].size_arr = 0;
		(*table)[0][i].arr = ft_lstmallocwrapper(alloced_ptrs,
				sizeof(*(*table)[0][i].arr), true);
	}
}

void	fill_table(t_INTarrofarr **table, t_INT_array fir_arr,
t_INT_array sec_arr, t_list **alloced_ptrs)
{
	t_3_int	ijk;

	ijk.a = 0;
	while (++ijk.a < fir_arr.size_elements + 1)
	{
		ijk.b = 0;
		while (++ijk.b < sec_arr.size_elements + 1)
		{
			if (fir_arr.elements[ijk.a - 1] == sec_arr.elements[ijk.b - 1])
				append_cell(ijk, alloced_ptrs, table, fir_arr);
			else
				select_longest_cell(ijk, alloced_ptrs, table);
		}
	}
}
