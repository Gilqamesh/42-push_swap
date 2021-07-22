/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:38:01 by edavid            #+#    #+#             */
/*   Updated: 2021/07/22 15:34:48 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_push_swap.h"

static int	contains_non_numeric(char *str)
{
	while (*str)
		if (!ft_isdigit(*str++))
			return (1);
	return (0);
}

static int	is_str_valid_integer(char *str)
{
	int	res;

	if (*str == '+')
		str++;
	if (*str == '-')
		if (contains_non_numeric(str + 1) || !*str)
			ft_error();
	else
		if (contains_non_numeric(str) || !*str)
			ft_error();
	res = ft_atoi(str);
	if (res == INT_MIN && ft_strncmp(str, "-2147483648", 11))
		ft_error();
	if (res == INT_MAX && ft_strncmp(str, "2147483647", 10))
		ft_error();
}

void	parse_input(int argc, char **argv)
{
	while (--argc > 0)
		if (!is_str_valid_integer(argv[argc]))
			ft_error();
}
