/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_helper5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:42:09 by edavid            #+#    #+#             */
/*   Updated: 2021/08/12 14:15:49 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_helper1.h"
#include "utils_helper4.h"
#include "utils_helper5.h"

static char	*init_struct(t_push_swap *tmp_mystruct, t_push_swap *mystruct,
t_arrofarrptrs *LIS_ord_unord, int i)
{
	t_INT_array2	int_arr;
	char			*tmp;

	copy_stack(&tmp_mystruct->a, &mystruct->a, mystruct->a.n);
	copy_stack(&tmp_mystruct->b, &mystruct->b, mystruct->b.n);
	int_arr = (t_INT_array2){LIS_ord_unord->table.arr[i],
		fill_unordered(tmp_mystruct, LIS_ord_unord->table.arr + i)};
	tmp = keep_LIS_in_A(tmp_mystruct, &int_arr);
	free(int_arr.arr2.elements);
	return (tmp);
}

static void	free_helper(char *tmp, t_push_swap *tmp_mystruct)
{
	free(tmp);
	ft_nodbinclear(&tmp_mystruct->a.head, ft_nodbindel, tmp_mystruct->a.n);
	ft_nodbinclear(&tmp_mystruct->b.head, ft_nodbindel, tmp_mystruct->b.n);
}

int	get_min_index_of_LIS(t_push_swap *mystruct, t_arrofarrptrs *LIS_ord_unord)
{
	int				i;
	t_push_swap		tmp_mystruct;
	char			*tmp;
	t_3_int			min_ind_res;

	i = -1;
	while (++i < LIS_ord_unord->table.size_arr)
	{
		tmp = init_struct(&tmp_mystruct, mystruct, LIS_ord_unord, i);
		tmp = ft_strjoin_free(tmp, find_optimal_merge_sequence(&tmp_mystruct));
		if (!i)
			min_ind_res = (t_3_int){ft_n_of_words_by_delim(tmp, ' '), 0};
		else
		{
			min_ind_res.c = ft_n_of_words_by_delim(tmp, ' ');
			if (min_ind_res.c < min_ind_res.a)
			{
				min_ind_res.a = min_ind_res.c;
				min_ind_res.b = i;
			}
		}
		free_helper(tmp, &tmp_mystruct);
	}
	return (min_ind_res.b);
}
