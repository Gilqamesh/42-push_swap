/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 11:39:06 by edavid            #+#    #+#             */
/*   Updated: 2021/08/11 17:45:16 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_merge_sort_copy(char **in, t_2_int start_end_indexes,
char **out)
{
	int	i;

	i = start_end_indexes.a - 1;
	while (++i < start_end_indexes.b)
		out[i] = in[i];
}

static void	ft_merge_sort_comb(char **in, t_3_int start_mid_end_indexes,
char **out)
{
	int	i;
	int	j;
	int	k;

	i = start_mid_end_indexes.a;
	j = start_mid_end_indexes.b;
	k = i - 1;
	while (++k < start_mid_end_indexes.c)
	{
		if (i < start_mid_end_indexes.b && (j >= start_mid_end_indexes.c
				|| ft_strcmp(in[i], in[j]) <= 0))
		{
			out[k] = in[i];
			i++;
		}
		else
		{
			out[k] = in[j];
			j++;
		}
	}
}

void	ft_merge_sort_str(char **array, t_2_int start_end_indexes,
char **helper_array)
{
	int	middle;

	if (start_end_indexes.b - start_end_indexes.a < 2)
		return ;
	middle = (start_end_indexes.a + start_end_indexes.b) / 2;
	ft_merge_sort_str(array, (t_2_int){start_end_indexes.a, middle},
		helper_array);
	ft_merge_sort_str(array, (t_2_int){middle, start_end_indexes.b},
		helper_array);
	ft_merge_sort_comb(array, (t_3_int){start_end_indexes.a, middle,
		start_end_indexes.b}, helper_array);
	ft_merge_sort_copy(helper_array, (t_2_int){start_end_indexes.a,
		start_end_indexes.b}, array);
}
