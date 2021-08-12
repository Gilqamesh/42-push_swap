/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_helper1.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:14:14 by edavid            #+#    #+#             */
/*   Updated: 2021/08/12 11:01:04 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HELPER1_H
# define UTILS_HELPER1_H

# include "../../ft_push_swap.h"

int			allocate_helper(t_INT_array *fir_arr, t_INT_array *sec_arr,
				int n, int **helper);
void		init_arrays_helper(t_node_binary *head, int n, t_INT_array *fir_arr,
				t_INT_array *sec_arr);
t_INT_array	fill_unordered(t_push_swap *mystruct, t_INT_array *LIS);
void		set_unique_counter_helper(int *unique_counter, t_INTarrofarr *ARR1,
				t_INTarrofarr *ARR2);
void		combine_helper(int unique_counter, t_INTarrofarr *ARR1,
				t_INTarrofarr *ARR2, t_INT_array *LCS_group_arr);

#endif
