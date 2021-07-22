/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion_uint_utils.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 12:57:35 by edavid            #+#    #+#             */
/*   Updated: 2021/07/22 14:06:42 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_print_conversion_uint_utils.h"

static int	handle_flags_g_prec_u(int *flags, int precision,
int conv_str_len, char *converted_str)
{
	int	printed_bytes;

	printed_bytes = flags[2];
	if (flags[0])
	{
		while (precision-- - conv_str_len)
		{
			ft_putchar_fd('0', 1);
			flags[2]--;
		}
		ft_putstr_fd(converted_str, 1);
		while (flags[2]-- - conv_str_len)
			ft_putchar_fd(' ', 1);
		return (printed_bytes);
	}
	while (flags[2]-- - precision)
		ft_putchar_fd(' ', 1);
	while (precision-- - conv_str_len)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(converted_str, 1);
	return (printed_bytes);
}

int	handle_prec_g_str_u(int *flags, int precision, int conv_str_len,
char *converted_str)
{
	int	printed_bytes;

	if (flags[2] > precision)
		return (handle_flags_g_prec_u(flags, precision, conv_str_len,
				converted_str));
	printed_bytes = precision;
	while (precision-- - conv_str_len)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(converted_str, 1);
	return (printed_bytes);
}

int	handle_flags_g_str_u(int *flags, int prec, int conv_s_len,
char *conv_str)
{
	int	printed_bytes;

	printed_bytes = flags[2];
	if (flags[0])
	{
		if (flags[1] && prec == -1)
		{
			while (flags[2]-- - conv_s_len)
				ft_putchar_fd('0', 1);
			ft_putstr_fd(conv_str, 1);
			return (printed_bytes);
		}
		ft_putstr_fd(conv_str, 1);
		while (flags[2]-- - conv_s_len)
			ft_putchar_fd(' ', 1);
		return (printed_bytes);
	}
	if (flags[1] && prec == -1)
		while (flags[2]-- - conv_s_len)
			ft_putchar_fd('0', 1);
	else
		while (flags[2]-- - conv_s_len)
			ft_putchar_fd(' ', 1);
	ft_putstr_fd(conv_str, 1);
	return (printed_bytes);
}
