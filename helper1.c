/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 20:28:24 by edavid            #+#    #+#             */
/*   Updated: 2021/08/11 23:06:36 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper1.h"
#include "helper2.h"

void	handle_rotations(t_push_swap *mystruct, t_rot_vars *min_rotate_ops,
t_node_binary **result_lst)
{
	handle_rotation_helper1(mystruct, min_rotate_ops, result_lst);
	handle_rotation_helper2(mystruct, min_rotate_ops, result_lst);
	if (min_rotate_ops->forward_rot)
	{
		while (min_rotate_ops->forward_rot-- > 0)
		{
			ft_nodbinadd_front(result_lst,
				ft_nodbinnew(ft_strdup(" ra")));
			stack_rotate(&mystruct->a);
		}
	}
	else if (min_rotate_ops->reverse_rot)
	{
		while (min_rotate_ops->reverse_rot-- > 0)
		{
			ft_nodbinadd_front(result_lst,
				ft_nodbinnew(ft_strdup(" rra")));
			stack_revrotate(&mystruct->a);
		}
	}
}

void	initialize_min_rotate_ops(t_push_swap *mystruct,
t_rot_vars *min_rotate_ops)
{
	ft_bzero(min_rotate_ops, sizeof(*min_rotate_ops));
	min_rotate_ops->forward_rot = get_number_of_rotations_for_inclusion(
			&mystruct->a, *(int *)mystruct->b.head->content, 1);
	min_rotate_ops->reverse_rot = mystruct->a.n - min_rotate_ops->forward_rot;
	if (min_rotate_ops->forward_rot < min_rotate_ops->reverse_rot)
	{
		min_rotate_ops->sum = min_rotate_ops->forward_rot;
		min_rotate_ops->reverse_rot = 0;
	}
	else
	{
		min_rotate_ops->sum = min_rotate_ops->reverse_rot;
		min_rotate_ops->forward_rot = 0;
	}
}

static void	helper_fn(t_push_swap *mystruct, t_2_int i_dir,
t_node_binary *tmp_B, t_rot_vars *rotate_ops)
{
	int	j;

	tmp_B = mystruct->b.head;
	j = -1;
	if (i_dir.b)
		while (++j < i_dir.a)
			tmp_B = tmp_B->next;
	else
		while (++j < i_dir.a)
			tmp_B = tmp_B->prev;
	ft_bzero(rotate_ops, sizeof(*rotate_ops));
	rotate_ops->forward_rot = get_number_of_rotations_for_inclusion(
			&mystruct->a, *(int *)tmp_B->content, 1);
	rotate_ops->reverse_rot = mystruct->a.n - rotate_ops->forward_rot;
}

void	check_for_min_ops_combo(t_push_swap *mystruct,
t_rot_vars *min_rotate_ops, t_node_binary *tmp_B)
{
	int			i;
	int			j;
	int			size_of_b;
	t_rot_vars	rotate_ops;

	init_b_i(mystruct, &size_of_b, &i);
	while (++i <= size_of_b / 2)
	{
		helper_fn(mystruct, (t_2_int){i, 1}, tmp_B, &rotate_ops);
		rotate_ops.forward_rot_B = i;
		rotate_ops.sum = rotate_ops.forward_rot_B;
		if (rotate_ops.forward_rot < rotate_ops.reverse_rot)
			handle_rotate(&rotate_ops, min_rotate_ops);
		else
		{
			rotate_ops.sum += rotate_ops.reverse_rot;
			rotate_ops.forward_rot = 0;
		}
		if (rotate_ops.sum < min_rotate_ops->sum)
			*min_rotate_ops = rotate_ops;
	}
}

void	check_for_min_ops_combo2(t_push_swap *mystruct,
t_rot_vars *min_rotate_ops, t_node_binary *tmp_B)
{
	int			i;
	int			j;
	int			size_of_b;
	t_rot_vars	rotate_ops;

	init_b_i(mystruct, &size_of_b, &i);
	while (++i < size_of_b / 2)
	{
		helper_fn(mystruct, (t_2_int){i, 0}, tmp_B, &rotate_ops);
		rotate_ops.reverse_rot_B = i;
		rotate_ops.sum = rotate_ops.reverse_rot_B;
		if (rotate_ops.forward_rot < rotate_ops.reverse_rot)
		{
			rotate_ops.sum += rotate_ops.forward_rot;
			rotate_ops.reverse_rot = 0;
		}
		else
			handle_rotate2(&rotate_ops, min_rotate_ops);
	}
}
