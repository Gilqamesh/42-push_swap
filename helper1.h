/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 20:27:48 by edavid            #+#    #+#             */
/*   Updated: 2021/08/11 20:14:52 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER1_H
# define HELPER1_H

# include "ft_push_swap.h"

void	handle_rotations(t_push_swap *mystruct, t_rot_vars *min_rotate_ops,
			t_node_binary **result_lst);
void	initialize_min_rotate_ops(t_push_swap *mystruct,
			t_rot_vars *min_rotate_ops);
void	check_for_min_ops_combo(t_push_swap *mystruct,
			t_rot_vars *min_rotate_ops, t_node_binary *tmp_B);
void	check_for_min_ops_combo2(t_push_swap *mystruct,
			t_rot_vars *min_rotate_ops, t_node_binary *tmp_B);

#endif
