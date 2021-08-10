/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 20:28:24 by edavid            #+#    #+#             */
/*   Updated: 2021/08/10 20:48:37 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include "helper1.h"

void	handle_rotations(t_push_swap *mystruct, t_4_int *min_rotate_ops,
t_node_binary **result_lst)
{
	if (min_rotate_ops->forward_both)
	{
		while (min_rotate_ops->forward_both-- > 0)
		{
			ft_nodbinadd_front(result_lst,
				ft_nodbinnew(ft_strdup(" rr")));
			stack_rotate(&mystruct->b);
			stack_rotate(&mystruct->a);
		}
	}
	else if (min_rotate_ops->reverse_both)
	{
		while (min_rotate_ops->reverse_both-- > 0)
		{
			ft_nodbinadd_front(result_lst,
				ft_nodbinnew(ft_strdup(" rrr")));
			stack_revrotate(&mystruct->b);
			stack_revrotate(&mystruct->a);
		}
	}
	if (min_rotate_ops->forward_rot_B)
	{
		while (min_rotate_ops->forward_rot_B-- > 0)
		{
			ft_nodbinadd_front(result_lst,
				ft_nodbinnew(ft_strdup(" rb")));
			stack_rotate(&mystruct->b);
		}
	}
	else if (min_rotate_ops->reverse_rot_B)
	{
		while (min_rotate_ops->reverse_rot_B-- > 0)
		{
			ft_nodbinadd_front(result_lst,
				ft_nodbinnew(ft_strdup(" rrb")));
			stack_revrotate(&mystruct->b);
		}
	}
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
t_4_int *min_rotate_ops)
{
	ft_bzero(&min_rotate_ops, sizeof(min_rotate_ops));
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

void	check_for_min_ops_combo(t_push_swap *mystruct,
t_4_int *min_rotate_ops, t_node_binary *tmp_B)
{
	int		i;
	int		j;
	int		size_of_b;
	t_4_int	rotate_ops;

	size_of_b = mystruct->b.n;
	if (size_of_b > 250)
		size_of_b = 250;
	i = 0;
	while (++i <= size_of_b / 2)
	{
		tmp_B = mystruct->b.head;
		j = -1;
		while (++j < i)
			tmp_B = tmp_B->next;
		ft_bzero(&rotate_ops, sizeof(rotate_ops));
		rotate_ops.forward_rot = get_number_of_rotations_for_inclusion(
			&mystruct->a, *(int *)tmp_B->content, 1);
		rotate_ops.reverse_rot = mystruct->a.n - rotate_ops.forward_rot;
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
		if (rotate_ops.sum < min_rotate_ops->sum)
			*min_rotate_ops = rotate_ops;
	}
}

void	check_for_min_ops_combo2(t_push_swap *mystruct,
t_4_int *min_rotate_ops, t_node_binary *tmp_B)
{
	int		i;
	int		j;
	int		size_of_b;
	t_4_int	rotate_ops;

	size_of_b = mystruct->b.n;
	if (size_of_b > 250)
		size_of_b = 250;
	i = 0;
	while (++i < size_of_b / 2)
	{
		tmp_B = mystruct->b.head;
		j = -1;
		while (++j < i)
			tmp_B = tmp_B->prev;
		ft_bzero(&rotate_ops, sizeof(rotate_ops));
		rotate_ops.forward_rot = get_number_of_rotations_for_inclusion(&mystruct->a,
			*(int *)tmp_B->content, 1);
		rotate_ops.reverse_rot = mystruct->a.n - rotate_ops.forward_rot;
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
		if (rotate_ops.sum < min_rotate_ops->sum)
			*min_rotate_ops = rotate_ops;
	}
}
