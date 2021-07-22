/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion_hexa_utilities.h               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:05:13 by edavid            #+#    #+#             */
/*   Updated: 2021/07/02 15:02:04 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_CONVERSION_HEXA_UTILITIES_H
# define FT_PRINT_CONVERSION_HEXA_UTILITIES_H

int		handle_flag_g_precision(int *flags, int precision, int conv_str_len,
			char *converted_str);
void	handle_left_justified(int *flags, int precision, int conv_str_len,
			char *converted_str);

#endif
