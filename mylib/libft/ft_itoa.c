/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 19:30:41 by edavid            #+#    #+#             */
/*   Updated: 2021/06/18 19:30:41 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

static char	*ft_initstr(char **str, int len, int is_negative, int is_zero)
{
	*str = (char *)malloc(len + 1);
	if (!*str)
		return ((char *)0);
	*(*str + len) = '\0';
	if (is_negative)
		**str = '-';
	if (is_zero)
		**str = '0';
	return (*str);
}

static int	ft_intlen(int n)
{
	int	len;

	if (!n)
		return (1);
	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		negative;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(n);
	negative = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
		negative = 1;
	}
	if (!ft_initstr(&str, len, negative, !n))
		return ((char *)0);
	while (n)
	{
		*(str + --len) = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
