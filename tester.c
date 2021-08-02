/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 17:55:15 by edavid            #+#    #+#             */
/*   Updated: 2021/08/02 20:32:05 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int main(int argc, char **argv)
{
	t_list		*arguments;
	t_INT_array	intArr;
	t_INT_array	intArrSorted;
	t_INT_array	LCSRes;
	int			i;
	int			*helper;

	arguments = (t_list *)0;
	i = 0;
	while (++i < argc)
		ft_lstadd_back(&arguments, ft_lstnew(ft_intdup(ft_atoi(argv[i]))));
	intArr = construct_intarr_from_lst(arguments);
	intArrSorted.elements = malloc(intArr.size_elements * sizeof(int));
	ft_memcpy(intArrSorted.elements, intArr.elements, intArr.size_elements * sizeof(int));
	helper = malloc(intArr.size_elements * sizeof(int));
	intArrSorted.size_elements = intArr.size_elements;
	ft_merge_sort_int(intArrSorted.elements, (t_2_int){0, intArr.size_elements}, helper);
	free(helper);
	LCSRes = find_LCS_of_two_sequences(intArr, intArrSorted);
	ft_printintarr(LCSRes.elements, LCSRes.size_elements);
	// TEST COMBINE_TWO_LCS_ARRAY FUNCTION
	// t_INT_array_of_arrays	arr1, arr2, result;

	// arr1 = (t_INT_array_of_arrays){&intArr, 1};
	// arr2 = (t_INT_array_of_arrays){&intArrSorted, 1};
	// result = combine_two_LCS_array(&arr1, &arr2);
	// for (int i = 0; i < result.size_arr; i++)
	// 	ft_printintarr(result.arr[i].elements, result.arr[i].size_elements);
	ft_lstclear(&arguments, ft_lstdel);
	return (0);
}
