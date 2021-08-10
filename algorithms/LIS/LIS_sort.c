/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:06:01 by edavid            #+#    #+#             */
/*   Updated: 2021/08/10 14:32:36 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_push_swap.h"

static char	*keep_LIS_in_A(t_push_swap *mystruct, t_INT_array2 *LIS_ord_unord)
{
	int				ord_index;
	int				unord_index;
	t_node_binary	*result_lst;
	char			*result_str;

	ord_index = 0;
	unord_index = 0;
	result_lst = NULL;
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

static char	*find_optimal_merge_sequence(t_push_swap *mystruct)
{
	t_node_binary	*tmp_B;
	t_node_binary	*result_lst;
	char			*result_str;
	t_4_int			rotate_ops;
	t_4_int			min_rotate_ops;
	int				i;
	int				j;

	result_lst = NULL;
	while (mystruct->b.n)
	{
		ft_bzero(&min_rotate_ops, sizeof(min_rotate_ops));
		i = -1;
		while (++i <= mystruct->b.n / 2)
		{
			if (!i)
			{
				min_rotate_ops.forward_rot = get_number_of_rotations_for_inclusion(
					&mystruct->a, *(int *)mystruct->b.head->content, 1);
				min_rotate_ops.reverse_rot = get_number_of_rotations_for_inclusion(
					&mystruct->a, *(int *)mystruct->b.head->content, 0);
				min_rotate_ops.forward_rot_B = 0;
				min_rotate_ops.reverse_rot_B = 0;
				if (min_rotate_ops.forward_rot < min_rotate_ops.reverse_rot)
				{
					min_rotate_ops.sum = min_rotate_ops.forward_rot;
					min_rotate_ops.reverse_rot = 0;
				}
				else
				{
					min_rotate_ops.sum = min_rotate_ops.reverse_rot;
					min_rotate_ops.forward_rot = 0;
				}
				continue ;
			}
			tmp_B = mystruct->b.head;
			j = -1;
			while (++j < i)
				tmp_B = tmp_B->next;
			ft_bzero(&rotate_ops, sizeof(rotate_ops));
			rotate_ops.forward_rot = get_number_of_rotations_for_inclusion(&mystruct->a,
			*(int *)tmp_B->content, 1);
			rotate_ops.reverse_rot = get_number_of_rotations_for_inclusion(&mystruct->a,
			*(int *)tmp_B->content, 0);
			rotate_ops.forward_rot_B = i;
			rotate_ops.reverse_rot_B = 0;
			rotate_ops.sum = rotate_ops.forward_rot_B;
			if (rotate_ops.forward_rot < rotate_ops.reverse_rot)
			{
				rotate_ops.sum += rotate_ops.forward_rot;
				if (rotate_ops.forward_rot_B < rotate_ops.forward_rot)
				{
					rotate_ops.sum -= rotate_ops.forward_rot_B;
					rotate_ops.forward_both = rotate_ops.forward_rot_B;
					rotate_ops.forward_rot -= rotate_ops.forward_rot_B;
					rotate_ops.forward_rot_B = 0;
				}
				else
				{
					rotate_ops.sum -= rotate_ops.forward_rot;
					rotate_ops.forward_both = rotate_ops.forward_rot;
					rotate_ops.forward_rot_B -= rotate_ops.forward_rot;
					rotate_ops.forward_rot = 0;
				}
				rotate_ops.reverse_rot = 0;
			}
			else
			{
				rotate_ops.sum += rotate_ops.reverse_rot;
				rotate_ops.forward_rot = 0;
			}
			if (rotate_ops.sum < min_rotate_ops.sum)
				min_rotate_ops = rotate_ops;
		}
		i = 0;
		while (++i < mystruct->b.n / 2)
		{
			tmp_B = mystruct->b.head;
			j = -1;
			while (++j < i)
				tmp_B = tmp_B->prev;
			ft_bzero(&rotate_ops, sizeof(rotate_ops));
			rotate_ops.forward_rot = get_number_of_rotations_for_inclusion(&mystruct->a,
			*(int *)tmp_B->content, 1);
			rotate_ops.reverse_rot = get_number_of_rotations_for_inclusion(&mystruct->a,
			*(int *)tmp_B->content, 0);
			rotate_ops.forward_rot_B = 0;
			rotate_ops.reverse_rot_B = i;
			rotate_ops.sum = rotate_ops.reverse_rot_B;
			if (rotate_ops.forward_rot < rotate_ops.reverse_rot)
			{
				rotate_ops.sum += rotate_ops.forward_rot;
				rotate_ops.reverse_rot = 0;
			}
			else
			{
				rotate_ops.sum += rotate_ops.reverse_rot;
				if (rotate_ops.reverse_rot_B < rotate_ops.reverse_rot)
				{
					rotate_ops.sum -= rotate_ops.reverse_rot_B;
					rotate_ops.reverse_both = rotate_ops.reverse_rot_B;
					rotate_ops.reverse_rot -= rotate_ops.reverse_rot_B;
					rotate_ops.reverse_rot_B = 0;
				}
				else
				{
					rotate_ops.sum -= rotate_ops.reverse_rot;
					rotate_ops.reverse_both = rotate_ops.reverse_rot;
					rotate_ops.reverse_rot_B -= rotate_ops.reverse_rot;
					rotate_ops.reverse_rot = 0;
				}
				rotate_ops.forward_rot = 0;
			}
			if (rotate_ops.sum < min_rotate_ops.sum)
				min_rotate_ops = rotate_ops;
		}
		if (min_rotate_ops.forward_both)
		{
			while (min_rotate_ops.forward_both-- > 0)
			{
				ft_nodbinadd_front(&result_lst,
					ft_nodbinnew(ft_strdup(" rr")));
				stack_rotate(&mystruct->b);
				stack_rotate(&mystruct->a);
			}
		}
		else if (min_rotate_ops.reverse_both)
		{
			while (min_rotate_ops.reverse_both-- > 0)
			{
				ft_nodbinadd_front(&result_lst,
					ft_nodbinnew(ft_strdup(" rrr")));
				stack_revrotate(&mystruct->b);
				stack_revrotate(&mystruct->a);
			}
		}
		if (min_rotate_ops.forward_rot_B)
		{
			while (min_rotate_ops.forward_rot_B-- > 0)
			{
				ft_nodbinadd_front(&result_lst,
					ft_nodbinnew(ft_strdup(" rb")));
				stack_rotate(&mystruct->b);
			}
		}
		else if (min_rotate_ops.reverse_rot_B)
		{
			while (min_rotate_ops.reverse_rot_B-- > 0)
			{
				ft_nodbinadd_front(&result_lst,
					ft_nodbinnew(ft_strdup(" rrb")));
				stack_revrotate(&mystruct->b);
			}
		}
		if (min_rotate_ops.forward_rot)
		{
			while (min_rotate_ops.forward_rot-- > 0)
			{
				ft_nodbinadd_front(&result_lst,
					ft_nodbinnew(ft_strdup(" ra")));
				stack_rotate(&mystruct->a);
			}
		}
		else if (min_rotate_ops.reverse_rot)
		{
			while (min_rotate_ops.reverse_rot-- > 0)
			{
				ft_nodbinadd_front(&result_lst,
					ft_nodbinnew(ft_strdup(" rra")));
				stack_revrotate(&mystruct->a);
			}
		}
		ft_nodbinadd_front(&result_lst, ft_nodbinnew(ft_strdup(" pa")));
		stack_pa(mystruct);
	}
	result_str = ft_nodbinstrjoin_from_back(result_lst);
	ft_nodbinclear(&result_lst, ft_nodbindel, -1);
	return (result_str);
}

char	*LIS_sort3(t_push_swap *mystruct)
{
	t_node_binary	*result_lst;
	char			*result_str;
	t_INT_array2	LIS_ord_unord;

	result_lst = NULL;
	if (is_stack_sorted(&mystruct->a, 0, 0))
		return (construct_minimum_rotations_needed_ops(&mystruct->a, 'a'));
	LIS_ord_unord = find_LIS_of_sublist(mystruct,
		mystruct->a.head, mystruct->a.n);
	ft_nodbinadd_front(&result_lst, ft_nodbinnew(
		keep_LIS_in_A(mystruct, &LIS_ord_unord)));
	destroy_t_INT_array2(&LIS_ord_unord);
	ft_nodbinadd_front(&result_lst, ft_nodbinnew(
		find_optimal_merge_sequence(mystruct)));
	ft_nodbinadd_front(&result_lst,
		ft_nodbinnew(construct_minimum_rotations_needed_ops(&mystruct->a, 'a')));
	result_str = ft_nodbinstrjoin_from_back(result_lst);
	ft_nodbinclear(&result_lst, ft_nodbindel, -1);
	return (result_str);
}
