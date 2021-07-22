/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 14:20:43 by edavid            #+#    #+#             */
/*   Updated: 2021/07/22 14:06:42 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"
#include "ft_printf.h"
#include "ft_conversions.h"

static void	set_vars_zero(int *format_index, int *n_of_printed)
{
	*format_index = 0;
	*n_of_printed = 0;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		format_index;
	int		n_of_printed;
	char	*conversion_specifier;

	set_vars_zero(&format_index, &n_of_printed);
	va_start(ap, format);
	while (format[format_index])
	{
		if (format[format_index] == '%')
		{
			format_index++;
			if (!is_valid_conv_spec((char *)format + format_index))
				continue ;
			conversion_specifier = malloc_conv_spec((char *)format
					+ format_index, &format_index);
			n_of_printed += handle_conversion_spec(conversion_specifier, ap);
			free(conversion_specifier);
			continue ;
		}
		ft_putchar_fd(*(format + format_index++), 1);
		n_of_printed++;
	}
	va_end(ap);
	return (n_of_printed);
}
