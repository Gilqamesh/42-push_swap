/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:33:04 by edavid            #+#    #+#             */
/*   Updated: 2021/07/22 14:06:42 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_conversions.h"
#include "../libft/libft.h"

static void	handle_left_justified(int *flags)
{
	if (flags[1])
	{
		while (flags[2]-- - 1)
			ft_putchar_fd('0', 1);
		ft_putchar_fd('%', 1);
	}
	else
	{
		ft_putchar_fd('%', 1);
		while (flags[2]-- - 1)
			ft_putchar_fd(' ', 1);
	}
}

static void	handle_right_justified(int *flags, int *printed_bytes)
{
	*printed_bytes = 1;
	if (flags[1])
	{
		while (flags[2]-- - 1)
			ft_putchar_fd('0', 1);
	}
	else
	{
		while (flags[2]-- - 1)
			ft_putchar_fd(' ', 1);
	}
	ft_putchar_fd('%', 1);
}

int	print_conversion_perc(int *flags)
{
	int		printed_bytes;

	if (flags[2] > 1)
	{
		printed_bytes = flags[2];
		if (flags[0])
			handle_left_justified(flags);
		else
			handle_right_justified(flags, &printed_bytes);
	}
	else
	{
		ft_putchar_fd('%', 1);
		printed_bytes = 1;
	}
	return (printed_bytes);
}

int	print_conversion(char conversion, va_list ap, int *flags)
{
	if (conversion == 'c')
		return (print_conversion_c((unsigned char)va_arg(ap, int), flags));
	else if (conversion == 's')
		return (print_conversion_s(va_arg(ap, char *), flags));
	else if (conversion == 'p')
		return (print_conversion_p(va_arg(ap, void *), flags));
	else if (conversion == 'd' || conversion == 'i')
		return (print_conversion_int(va_arg(ap, int), flags));
	else if (conversion == 'u')
		return (print_conversion_uint((unsigned int)va_arg(ap, int), flags));
	else if (conversion == 'x' || conversion == 'X')
		return (print_conversion_hexa((unsigned int)va_arg(ap, int), flags,
				conversion));
	else if (conversion == '%')
		return (print_conversion_perc(flags));
	else
		return (-1);
}
