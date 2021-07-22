/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 14:18:21 by edavid            #+#    #+#             */
/*   Updated: 2021/07/02 15:03:36 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
int		ft_printf(const char *format, ...);
char	*malloc_conv_spec(char *format, int *format_index);
int		is_valid_conv_spec(char *conv_spec);
int		handle_conversion_spec(char *conv_spec, va_list ap);
int		set_flags(char *conv_spec, int *flags, va_list ap);

#endif
