/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:43:29 by edavid            #+#    #+#             */
/*   Updated: 2021/08/11 23:09:49 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper2.h"

void	init_b_i(t_push_swap *mystruct, int *size_of_b, int *i)
{
	*size_of_b = mystruct->b.n;
	if (*size_of_b > 500)
		*size_of_b = 500;
	*i = 0;
}

void	handle_rotate(t_rot_vars *rotate_ops, t_rot_vars *min_rotate_ops)
{
	rotate_ops->sum += rotate_ops->forward_rot;
	if (rotate_ops->forward_rot_B < rotate_ops->forward_rot)
	{
		rotate_ops->sum -= rotate_ops->forward_rot_B;
		rotate_ops->forward_both = rotate_ops->forward_rot_B;
		rotate_ops->forward_rot -= rotate_ops->forward_rot_B;
		rotate_ops->forward_rot_B = 0;
	}
	else
	{
		rotate_ops->sum -= rotate_ops->forward_rot;
		rotate_ops->forward_both = rotate_ops->forward_rot;
		rotate_ops->forward_rot_B -= rotate_ops->forward_rot;
		rotate_ops->forward_rot = 0;
	}
	rotate_ops->reverse_rot = 0;
}

void	handle_rotate2(t_rot_vars *rotate_ops, t_rot_vars *min_rotate_ops)
{
	rotate_ops->sum += rotate_ops->reverse_rot;
	if (rotate_ops->reverse_rot_B < rotate_ops->reverse_rot)
	{
		rotate_ops->sum -= rotate_ops->reverse_rot_B;
		rotate_ops->reverse_both = rotate_ops->reverse_rot_B;
		rotate_ops->reverse_rot -= rotate_ops->reverse_rot_B;
		rotate_ops->reverse_rot_B = 0;
	}
	else
	{
		rotate_ops->sum -= rotate_ops->reverse_rot;
		rotate_ops->reverse_both = rotate_ops->reverse_rot;
		rotate_ops->reverse_rot_B -= rotate_ops->reverse_rot;
		rotate_ops->reverse_rot = 0;
	}
	rotate_ops->forward_rot = 0;
	if (rotate_ops->sum < min_rotate_ops->sum)
		*min_rotate_ops = *rotate_ops;
}

void	handle_rotation_helper1(t_push_swap *mystruct,
t_rot_vars *min_rotate_ops, t_node_binary **result_lst)
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
}

void	handle_rotation_helper2(t_push_swap *mystruct,
t_rot_vars *min_rotate_ops, t_node_binary **result_lst)
{
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
}
