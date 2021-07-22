/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 15:43:59 by edavid            #+#    #+#             */
/*   Updated: 2021/07/22 14:06:42 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "../libft/libft.h"
#include "ft_conversions.h"

static char	*alloc_null_str(void)
{
	char	*str;

	str = malloc(1);
	if (!str)
		return ((char *)0);
	*str = '\0';
	return (str);
}

static void	handle_precision(int *index, char *format)
{
	(*index)++;
	if (format[*index] == '*')
		(*index)++;
	else
		while (ft_isdigit(format[*index]))
			(*index)++;
}

char	*malloc_conv_spec(char *format, int *format_index)
{
	int		index;
	int		format_len;
	char	*conversion_specifier;

	if (!*format)
		return (alloc_null_str());
	index = 0;
	while (format[index] == '-' || format[index] == '0')
		index++;
	while (ft_isdigit(format[index]))
		index++;
	if (format[index] == '*')
		index++;
	if (format[index] == '.')
		handle_precision(&index, format);
	format_len = index + 1;
	conversion_specifier = malloc(format_len + 1);
	index = -1;
	while (++index < format_len)
		conversion_specifier[index] = format[index];
	conversion_specifier[index] = '\0';
	*format_index += format_len;
	return (conversion_specifier);
}

int	is_valid_conv_spec(char *conv_spec)
{
	if (*conv_spec == '%')
		return (1);
	while (*conv_spec == '-' || *conv_spec == '0')
		conv_spec++;
	while (ft_isdigit(*conv_spec))
		conv_spec++;
	if (*conv_spec == '*')
		conv_spec++;
	if (*conv_spec == '.')
	{
		conv_spec++;
		if (*conv_spec == '*')
			conv_spec++;
		else
			while (ft_isdigit(*conv_spec))
				conv_spec++;
	}
	if (*conv_spec == '\0' || (*conv_spec != 'c' && *conv_spec != 's'
			&& *conv_spec != 'p' && *conv_spec != 'd' && *conv_spec != 'i'
			&& *conv_spec != 'u' && *conv_spec != 'x' && *conv_spec != 'X'
			&& *conv_spec != '%'))
		return (0);
	return (1);
}

int	handle_conversion_spec(char *conv_spec, va_list ap)
{
	int		*flags;
	int		conversion_index;
	int		printed_bytes;

	flags = ft_calloc(5, sizeof(int));
	conversion_index = set_flags(conv_spec, flags, ap);
	printed_bytes = print_conversion(conv_spec[conversion_index], ap, flags);
	free(flags);
	return (printed_bytes);
}
