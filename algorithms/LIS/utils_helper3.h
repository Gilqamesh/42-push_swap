/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_helper3.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 16:32:33 by edavid            #+#    #+#             */
/*   Updated: 2021/08/11 16:37:06 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HELPER3_H
# define UTILS_HELPER3_H

# include "../../ft_push_swap.h"
void	append_cell(t_3_int ijk, t_list **alloced_ptrs,
			t_INTarrofarr **table, t_INT_array fir_arr);
void	select_longest_cell(t_3_int ijk, t_list **alloced_ptrs,
			t_INTarrofarr **table);

#endif
