/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper1.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 20:27:48 by edavid            #+#    #+#             */
/*   Updated: 2021/08/10 20:48:13 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER1
# define HELPER1

void	handle_rotations(t_push_swap *mystruct, t_4_int *min_rotate_ops,
	t_node_binary **result_lst);
void	initialize_min_rotate_ops(t_push_swap *mystruct,
	t_4_int *min_rotate_ops);
void	check_for_min_ops_combo(t_push_swap *mystruct,
	t_4_int *min_rotate_ops, t_node_binary *tmp_B);
void	check_for_min_ops_combo2(t_push_swap *mystruct,
	t_4_int *min_rotate_ops, t_node_binary *tmp_B);

#endif
