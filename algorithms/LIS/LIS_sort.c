/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:06:01 by edavid            #+#    #+#             */
/*   Updated: 2021/08/11 23:13:32 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_push_swap.h"
#include "../../helper1.h"
#include "utils_helper4.h"

static void	init_indexes(int *ord_index, int *unord_index,
t_node_binary **result_lst)
{
	*ord_index = 0;
	*unord_index = 0;
	*result_lst = NULL;
}

static char	*keep_LIS_in_A(t_push_swap *mystruct, t_INT_array2 *LIS_ord_unord)
{
	int				ord_index;
	int				unord_index;
	t_node_binary	*result_lst;
	char			*result_str;

	init_indexes(&ord_index, &unord_index, &result_lst);
	while (unord_index < LIS_ord_unord->arr2.size_elements)
	{
		if (LIS_ord_unord->arr1.elements[ord_index]
			== *(int *)mystruct->a.head->content)
		{
			ord_index++;
			ft_nodbinadd_front(&result_lst, ft_nodbinnew(ft_strdup(" ra")));
			stack_ra(mystruct);
		}
		else
		{
			unord_index++;
			ft_nodbinadd_front(&result_lst, ft_nodbinnew(ft_strdup(" pb")));
			stack_pb(mystruct);
		}
	}
	result_str = ft_nodbinstrjoin_from_back(result_lst);
	ft_nodbinclear(&result_lst, ft_nodbindel, -1);
	return (result_str);
}

static void	helper_function(t_push_swap *mystruct, t_node_binary **result_lst)
{
	t_node_binary		*tmp_B;
	t_rot_vars			min_rotate_ops;

	initialize_min_rotate_ops(mystruct, &min_rotate_ops);
	check_for_min_ops_combo(mystruct, &min_rotate_ops, tmp_B);
	check_for_min_ops_combo2(mystruct, &min_rotate_ops, tmp_B);
	handle_rotations(mystruct, &min_rotate_ops, result_lst);
}

static char	*find_optimal_merge_sequence(t_push_swap *mystruct)
{
	t_node_binary	*tmp_B;
	t_node_binary	*result_lst;
	char			*result_str;
	int				i;
	int				j;

	result_lst = NULL;
	while (mystruct->b.n)
	{
		helper_function(mystruct, &result_lst);
		ft_nodbinadd_front(&result_lst, ft_nodbinnew(ft_strdup(" pa")));
		stack_pa(mystruct);
	}
	result_str = ft_nodbinstrjoin_from_back(result_lst);
	ft_nodbinclear(&result_lst, ft_nodbindel, -1);
	return (result_str);
}

char	*LIS_sort(t_push_swap *mystruct)
{
	t_node_binary	*result_lst;
	char			*result_str;
	t_INT_array2	LIS_ord_unord;

	result_lst = NULL;
	if (is_stack_sorted(&mystruct->a))
		return (construct_minimum_rotations_needed_ops(&mystruct->a, 'a'));
	LIS_ord_unord = find_LIS_of_sublist(mystruct,
			mystruct->a.head, get_input_limit_on_LIS(mystruct->a.n));
	if (LIS_ord_unord.arr1.size_elements < 3)
		ft_nodbinadd_front(&result_lst, ft_nodbinnew(three_sort(mystruct)));
	else
		ft_nodbinadd_front(&result_lst, ft_nodbinnew(
				keep_LIS_in_A(mystruct, &LIS_ord_unord)));
	destroy_t_INT_array2(&LIS_ord_unord);
	ft_nodbinadd_front(&result_lst, ft_nodbinnew(
			find_optimal_merge_sequence(mystruct)));
	ft_nodbinadd_front(&result_lst,
		ft_nodbinnew(construct_minimum_rotations_needed_ops(
				&mystruct->a, 'a')));
	result_str = ft_nodbinstrjoin_from_back(result_lst);
	ft_nodbinclear(&result_lst, ft_nodbindel, -1);
	return (result_str);
}
