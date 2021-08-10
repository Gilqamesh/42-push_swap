/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion_int_utils.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:47:56 by edavid            #+#    #+#             */
/*   Updated: 2021/08/10 15:10:37 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_print_conversion_int_utils.h"
#include <stdlib.h>

void	set_precision_and_negative(int *flags, int *precision, int n,
int *is_n)
{
	if (flags[3] == -3)
		*precision = -1;
	else if (flags[3] == -1)
		*precision = flags[4];
	else
		*precision = flags[3];
	*is_n = 0;
	if (n < 0)
		*is_n = 1;
}

static void	print_part(int is_n, int precision, int conv_str_len,
char *converted_str)
{
	if (is_n)
		ft_putchar_fd('-', 1);
	while (precision - conv_str_len++)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(converted_str, 1);
}

int	handle_prec_g_str_i(int *flags, int precision, int is_n,
char *converted_str)
{
	int	conv_str_len;
	int	printed_bytes;

	conv_str_len = ft_strlen(converted_str);
	if (flags[2] > precision)
	{
		printed_bytes = flags[2];
		if (flags[0])
		{
			print_part(is_n, precision, conv_str_len, converted_str);
			while (flags[2]-- - precision - is_n)
				ft_putchar_fd(' ', 1);
		}
		else
		{
			while (flags[2]-- - precision - is_n)
				ft_putchar_fd(' ', 1);
			print_part(is_n, precision, conv_str_len, converted_str);
		}
		return (printed_bytes);
	}
	printed_bytes = precision + is_n;
	print_part(is_n, precision, conv_str_len, converted_str);
	free(converted_str);
	return (printed_bytes);
}

static int	left_justified(int *flags, int precision, int is_n,
char *conv_str)
{
	int	conv_str_len;
	int	printed_bytes;

	conv_str_len = ft_strlen(conv_str);
	printed_bytes = flags[2];
	if (flags[1] && precision == -1)
	{
		if (is_n)
			ft_putchar_fd('-', 1);
		while (flags[2]-- - conv_str_len - is_n)
			ft_putchar_fd('0', 1);
		ft_putstr_fd(conv_str, 1);
	}
	else
	{
		if (is_n)
			ft_putchar_fd('-', 1);
		ft_putstr_fd(conv_str, 1);
		while (flags[2]-- - conv_str_len - is_n)
			ft_putchar_fd(' ', 1);
	}
	return (printed_bytes);
}

int	handle_flag_g_str_i(int *flags, int precision, int is_n, char *conv_str)
{
	int	printed_bytes;
	int	conv_str_len;

	conv_str_len = ft_strlen(conv_str);
	printed_bytes = flags[2];
	if (flags[0])
		return (left_justified(flags, precision, is_n, conv_str));
	if (flags[1] && precision == -1)
	{
		if (is_n)
			ft_putchar_fd('-', 1);
		while (flags[2]-- - conv_str_len - is_n)
			ft_putchar_fd('0', 1);
	}
	else
	{
		while (flags[2]-- - conv_str_len - is_n)
			ft_putchar_fd(' ', 1);
		if (is_n)
			ft_putchar_fd('-', 1);
	}
	ft_putstr_fd(conv_str, 1);
	free(conv_str);
	return (printed_bytes);
}
