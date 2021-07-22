/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 19:30:27 by edavid            #+#    #+#             */
/*   Updated: 2021/06/18 19:30:27 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_isspace(const char c)
{
	if (c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int			is_negative;
	long int	result;

	if (ft_isspace(*nptr))
		return (ft_atoi(nptr + 1));
	is_negative = 0;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			is_negative = 1;
	result = 0;
	while (*nptr && ft_isdigit(*nptr))
	{
		if (result >= LONG_MAX / 10)
		{
			if (is_negative)
				result = LONG_MIN;
			else
				result = LONG_MAX;
			return (result);
		}
		result = result * 10 + (*nptr++ - '0');
	}
	if (is_negative)
		return (-result);
	return (result);
}
