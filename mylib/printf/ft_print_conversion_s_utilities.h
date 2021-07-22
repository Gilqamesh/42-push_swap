/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion_s_utilities.h                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:30:45 by edavid            #+#    #+#             */
/*   Updated: 2021/07/02 15:03:01 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_CONVERSION_S_UTILITIES_H
# define FT_PRINT_CONVERSION_S_UTILITIES_H

void	set_precision(int *precision, int *flags, int str_len);
int		handle_no_precision(int *flags, int str_len, char *str);
int		handle_flags_g_prec(int *flags, int precision, int str_len,
			char *str);
int		handle_flags_l_str(int *flags, int str_len, char *str);

#endif
