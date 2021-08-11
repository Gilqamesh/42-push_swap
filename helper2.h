/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:43:13 by edavid            #+#    #+#             */
/*   Updated: 2021/08/11 20:59:56 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER2_H
# define HELPER2_H

# include "ft_push_swap.h"

void	init_b_i(t_push_swap *mystruct, int *size_of_b, int *i);
void	handle_rotate(t_rot_vars *rotate_ops, t_rot_vars *min_rotate_ops);
void	handle_rotate2(t_rot_vars *rotate_ops, t_rot_vars *min_rotate_ops);
void	handle_rotation_helper1(t_push_swap *mystruct,
			t_rot_vars *min_rotate_ops, t_node_binary **result_lst);
void	handle_rotation_helper2(t_push_swap *mystruct,
			t_rot_vars *min_rotate_ops, t_node_binary **result_lst);

#endif
