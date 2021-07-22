/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:43:21 by edavid            #+#    #+#             */
/*   Updated: 2021/07/01 19:28:41 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_conversions.h"
#include <stdlib.h>

int	ft_uintlen(unsigned int n)
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

char	*ft_initstr(char **str, int len, int is_zero)
{
	*str = (char *)malloc(len + 1);
	if (!*str)
		return ((char *)0);
	*(*str + len) = '\0';
	if (is_zero)
		**str = '0';
	return (*str);
}
