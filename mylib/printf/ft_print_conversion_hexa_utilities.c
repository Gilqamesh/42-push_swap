/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion_hexa_utilities.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:52:21 by edavid            #+#    #+#             */
/*   Updated: 2021/07/22 14:06:42 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_print_conversion_hexa_utilities.h"

int	handle_flag_g_precision(int *flags, int precision,
int conv_str_len, char *converted_str)
{
	int	printed_bytes;

	printed_bytes = flags[2];
	if (flags[0])
	{
		while (precision - conv_str_len++)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(converted_str, 1);
		while (flags[2]-- - precision)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (flags[2]-- - precision)
			ft_putchar_fd(' ', 1);
		while (precision-- - conv_str_len)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(converted_str, 1);
	}
	return (printed_bytes);
}

void	handle_left_justified(int *flags, int precision, int conv_str_len,
char *converted_str)
{
	if (flags[1] && precision == -1)
	{
		while (flags[2]-- - conv_str_len)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(converted_str, 1);
	}
	else
	{
		ft_putstr_fd(converted_str, 1);
		while (flags[2]-- - conv_str_len)
			ft_putchar_fd(' ', 1);
	}
}
