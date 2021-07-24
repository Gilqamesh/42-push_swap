/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:38:01 by edavid            #+#    #+#             */
/*   Updated: 2021/07/24 15:22:05 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "ft_push_swap.h"

static int	contains_non_numeric(char *str)
{
	while (*str)
		if (!ft_isdigit(*str++))
			return (1);
	return (0);
}

static void	test_is_str_valid_int(char *str)
{
	int	res;

	if (*str == '+')
		str++;
	if (*str == '-')
	{
		if (!*str || contains_non_numeric(str + 1))
			ft_error();
	}
	else if (!*str || contains_non_numeric(str))
		ft_error();
	res = ft_atoi(str);
	if (res == INT_MIN && ft_strncmp(str, "-2147483648", 11))
		ft_error();
	if (res == INT_MAX && ft_strncmp(str, "2147483647", 10))
		ft_error();
}

void	initialize_struct(t_push_swap *mystruct, int argc)
{
	ft_bzero(mystruct, sizeof(*mystruct));
}

void	parse_input(t_push_swap *mystruct, int argc, char **argv)
{
	while (--argc > 0)
	{
		test_is_str_valid_int(argv[argc]);
		// mystruct->a.arr[mystruct->a.n++] = ft_atoi(argv[argc]);
		mystruct->a.top = 
	}
}
