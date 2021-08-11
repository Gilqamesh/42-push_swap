/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_helper2.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:56:45 by edavid            #+#    #+#             */
/*   Updated: 2021/08/11 16:20:17 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HELPER2_H
# define UTILS_HELPER2_H

# include "../../ft_push_swap.h"
void	set_unique_counter_helper_helper(t_INTarrofarr *ARR1,
			t_INTarrofarr *ARR2, int *i, int *j);
void	combine_helper_helper(t_INTarrofarr *ARR1,
			t_INTarrofarr *ARR2, t_INT_array *LCS_group_arr, t_3_int *i_j_k);
void	init_table(t_list **alloced_ptrs, t_INTarrofarr ***table,
			t_INT_array fir_arr, t_INT_array sec_arr);
void	fill_table(t_INTarrofarr **table, t_INT_array fir_arr,
			t_INT_array sec_arr, t_list **alloced_ptrs);

#endif
