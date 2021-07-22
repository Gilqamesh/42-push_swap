/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion_uint_utils.h                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 13:27:28 by edavid            #+#    #+#             */
/*   Updated: 2021/07/02 15:03:14 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_CONVERSION_UINT_UTILS_H
# define FT_PRINT_CONVERSION_UINT_UTILS_H

int	handle_prec_g_str_u(int *flags, int precision, int conv_str_len,
		char *converted_str);
int	handle_flags_g_str_u(int *flags, int prec, int conv_s_len,
		char *conv_str);

#endif
