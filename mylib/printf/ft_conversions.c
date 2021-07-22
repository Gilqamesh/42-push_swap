/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:31:19 by edavid            #+#    #+#             */
/*   Updated: 2021/07/22 14:06:42 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft/libft.h"
#include "ft_conversions.h"

static void	positive_width(int *printed_bytes, int *flags, unsigned char c)
{
	*printed_bytes = flags[2] + 1;
	if (flags[0])
	{
		write(1, &c, 1);
		while (flags[2]--)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while (flags[2]--)
			ft_putchar_fd(' ', 1);
		write(1, &c, 1);
	}
}

int	print_conversion_c(unsigned char c, int *flags)
{
	int	printed_bytes;

	if (--flags[2] > 0)
		positive_width(&printed_bytes, flags, c);
	else
	{
		printed_bytes = 1;
		write(1, &c, 1);
	}
	return (printed_bytes);
}
