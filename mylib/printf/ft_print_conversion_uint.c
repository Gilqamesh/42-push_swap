/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion_uint.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 12:55:24 by edavid            #+#    #+#             */
/*   Updated: 2021/07/22 14:06:42 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_conversions.h"
#include "ft_print_conversion_uint_utils.h"

static void	set_prec(int *flags, int *prec)
{
	if (flags[3] == -3)
		*prec = -1;
	else if (flags[3] == -1)
		*prec = flags[4];
	else
		*prec = flags[3];
}

int	print_conversion_uint(unsigned int n, int *flags)
{
	char	*conv_str;
	int		conv_s_len;
	int		prec;
	int		printed_bytes;

	set_prec(flags, &prec);
	conv_str = ft_utoa(n);
	if (flags[3] == -2 && !n)
		shift_str(&conv_str);
	conv_s_len = ft_strlen(conv_str);
	if (prec > conv_s_len)
		return (handle_prec_g_str_u(flags, prec, conv_s_len, conv_str));
	if (flags[2] > conv_s_len)
		return (handle_flags_g_str_u(flags, prec, conv_s_len, conv_str));
	else
	{
		ft_putstr_fd(conv_str, 1);
		printed_bytes = conv_s_len;
	}
	return (printed_bytes);
}
