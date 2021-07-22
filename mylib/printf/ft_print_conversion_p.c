/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion_p.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:33:26 by edavid            #+#    #+#             */
/*   Updated: 2021/07/22 14:06:42 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft/libft.h"
#include "ft_conversions.h"

static void	handle_edge_case(int *flags, int addr_len,
int null_pp, int *printed_spaces)
{
	if (flags[2] > addr_len + 2 - null_pp)
	{
		while (flags[2]-- > addr_len + 2 - null_pp)
		{
			ft_putchar_fd(' ', 1);
			(*printed_spaces)++;
		}
	}
}

int	print_conversion_p(void *arg_pointer, int *flags)
{
	int	addr_len;
	int	printed_spaces;
	int	null_pp;

	null_pp = 0;
	if (!arg_pointer && flags[3] == -2)
		null_pp = 1;
	printed_spaces = 0;
	addr_len = digits_in_hexa((unsigned long)arg_pointer);
	if (flags[0])
	{
		write(1, "0x", 2);
		if (!null_pp)
			print_ultoh((unsigned long)arg_pointer, 's');
		handle_edge_case(flags, addr_len, null_pp, &printed_spaces);
	}
	else
	{
		handle_edge_case(flags, addr_len, null_pp, &printed_spaces);
		write(1, "0x", 2);
		if (!null_pp)
			print_ultoh((unsigned long)arg_pointer, 's');
	}
	return (addr_len + printed_spaces + 2);
}
