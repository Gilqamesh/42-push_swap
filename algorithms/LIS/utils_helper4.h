/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_helper4.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:06:46 by edavid            #+#    #+#             */
/*   Updated: 2021/08/12 13:38:05 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HELPER4_H
# define UTILS_HELPER4_H

# include "../../ft_push_swap.h"
void	init_vars(t_stack *stack, t_node_binary **result_lst, int *i,
			t_node_binary **cur);
void	get_rotations(t_stack *stack, t_node_binary **result_lst, int i,
			char stack_name);
// Limits the number of inputs when calculating its LIS
int		get_input_limit_on_LIS(int n_of_inputs);
// Copies 'n' nodes from stack 'src' into 'dest'
void	copy_stack(t_stack *dest, t_stack *src, int n);
// Checks all the possible LIS with find_optimal_merge_sequence and
// chooses the one that took the least amount of operations
char	*find_minimum_sequence_of_all_LIS(t_arrofarrptrs *LIS_ord_unord,
			t_push_swap *mystruct);

#endif
