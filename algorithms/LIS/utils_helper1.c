/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_helper1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:14:40 by edavid            #+#    #+#             */
/*   Updated: 2021/08/12 11:00:51 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_helper1.h"
#include "utils_helper2.h"

int	allocate_helper(t_INT_array *fir_arr, t_INT_array *sec_arr,
int n, int **helper)
{
	n = ft_abs_int(n);
	fir_arr->elements = malloc(n * sizeof(*fir_arr->elements));
	fir_arr->size_elements = n;
	sec_arr->elements = malloc(n * sizeof(*sec_arr->elements));
	*helper = malloc(n * sizeof(**helper));
	sec_arr->size_elements = n;
	if (!fir_arr->elements || !sec_arr->elements || !helper)
		return (0);
	return (1);
}

void	init_arrays_helper(t_node_binary *head, int n, t_INT_array *fir_arr,
t_INT_array *sec_arr)
{
	t_node_binary	*cur;
	int				i;

	cur = head;
	i = -1;
	if (n < 0)
	{
		while (++i < -n)
		{
			fir_arr->elements[i] = *(int *)cur->content;
			sec_arr->elements[i] = *(int *)cur->content;
			cur = cur->prev;
		}
	}
	else
	{
		while (++i < n)
		{
			fir_arr->elements[i] = *(int *)cur->content;
			sec_arr->elements[i] = *(int *)cur->content;
			cur = cur->next;
		}
	}
}

t_INT_array	fill_unordered(t_push_swap *mystruct, t_INT_array *LIS)
{
	t_node_binary	*tmp;
	t_3_int			i_j_k;
	t_INT_array		unordered;

	unordered.size_elements = mystruct->a.n - LIS->size_elements;
	unordered.elements = malloc((mystruct->a.n - LIS->size_elements)
			* sizeof(int));
	tmp = mystruct->a.head;
	i_j_k.a = -1;
	i_j_k.b = 0;
	i_j_k.c = 0;
	while (++i_j_k.a < mystruct->a.n)
	{
		if (*(int *)tmp->content != LIS->elements[i_j_k.b])
			unordered.elements[i_j_k.c++] = *(int *)tmp->content;
		else
			i_j_k.b++;
		tmp = tmp->next;
	}
	return (unordered);
}

void	set_unique_counter_helper(int *unique_counter, t_INTarrofarr *ARR1,
t_INTarrofarr *ARR2)
{
	int	i;
	int	j;
	int	compared_value;

	*unique_counter = 0;
	i = 0;
	j = 0;
	while (i < ARR1->size_arr || j < ARR2->size_arr)
	{
		if (i < ARR1->size_arr && j < ARR2->size_arr)
			set_unique_counter_helper_helper(ARR1, ARR2, &i, &j);
		else if (i < ARR1->size_arr)
			i++;
		else if (j < ARR2->size_arr)
			j++;
		(*unique_counter)++;
	}
}

void	combine_helper(int unique_counter, t_INTarrofarr *ARR1,
t_INTarrofarr *ARR2, t_INT_array *LCS_group_arr)
{
	t_3_int	i_j_k;

	ft_bzero(&i_j_k, sizeof(i_j_k));
	i_j_k.c = -1;
	while (++i_j_k.c < unique_counter)
	{
		if (i_j_k.a < ARR1->size_arr && i_j_k.b < ARR2->size_arr)
			combine_helper_helper(ARR1, ARR2, LCS_group_arr, &i_j_k);
		else if (i_j_k.a < ARR1->size_arr)
		{
			LCS_group_arr[i_j_k.c].size_elements
				= ARR1->arr[i_j_k.a].size_elements;
			LCS_group_arr[i_j_k.c].elements
				= ARR1->arr[i_j_k.a].elements;
			i_j_k.a++;
		}
		else
		{
			LCS_group_arr[i_j_k.c].size_elements
				= ARR2->arr[i_j_k.b].size_elements;
			LCS_group_arr[i_j_k.c].elements
				= ARR2->arr[i_j_k.b].elements;
			i_j_k.b++;
		}
	}
}
