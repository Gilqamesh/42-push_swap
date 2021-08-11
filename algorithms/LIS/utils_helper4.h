/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_helper4.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:06:46 by edavid            #+#    #+#             */
/*   Updated: 2021/08/11 20:21:04 by edavid           ###   ########.fr       */
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

#endif
