/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:11:01 by edavid            #+#    #+#             */
/*   Updated: 2021/07/22 14:06:42 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

static void	num_precision(char *conv_spec, int *flags,
int *conv_spec_index, char *c)
{
	if (!ft_isdigit(*c))
		flags[3] = -2;
	else
	{
		while (ft_isdigit(*c))
		{
			flags[3] = flags[3] * 10 + *c - '0';
			*c = conv_spec[++(*conv_spec_index)];
		}
		if (flags[3] == 0)
			flags[3] = -2;
	}
}

static char	handle_precision(char *conv_spec, int *flags, va_list ap,
int *conv_spec_index)
{
	char	c;

	c = conv_spec[++(*conv_spec_index)];
	if (c == '*')
	{
		flags[3] = -1;
		flags[4] = va_arg(ap, int);
		if (flags[4] < 0)
			flags[3] = -3;
		else if (flags[4] == 0)
			flags[3] = -2;
		(*conv_spec_index)++;
	}
	else
		num_precision(conv_spec, flags, conv_spec_index, &c);
	return (c);
}

static char	handle_field_width(char *conv_spec, int *flags, va_list ap,
int *conv_spec_index)
{
	char	c;

	flags[2] = va_arg(ap, int);
	if (flags[2] < 0)
	{
		flags[2] *= -1;
		flags[0] = 1;
		flags[1] = 0;
	}
	c = conv_spec[++(*conv_spec_index)];
	return (c);
}

static void	handle_neg_zero_flag(char *conv_spec, int *flags,
int *conv_spec_index, char *c)
{
	while (*c == '-' || *c == '0')
	{
		if (*c == '-')
		{
			flags[0] = 1;
			flags[1] = 0;
		}
		else if (*c == '0' && !flags[0])
			flags[1] = 1;
		*c = conv_spec[++(*conv_spec_index)];
	}
}

int	set_flags(char *conv_spec, int *flags, va_list ap)
{
	int		conv_spec_index;
	char	c;

	conv_spec_index = 0;
	c = conv_spec[conv_spec_index];
	handle_neg_zero_flag(conv_spec, flags, &conv_spec_index, &c);
	while (ft_isdigit(c))
	{
		flags[2] = flags[2] * 10 + c - '0';
		c = conv_spec[++conv_spec_index];
	}
	if (c == '*')
		c = handle_field_width(conv_spec, flags, ap, &conv_spec_index);
	if (c == '.')
		c = handle_precision(conv_spec, flags, ap, &conv_spec_index);
	else
		flags[3] = -3;
	return (conv_spec_index);
}
