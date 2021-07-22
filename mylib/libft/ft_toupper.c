/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 19:31:42 by edavid            #+#    #+#             */
/*   Updated: 2021/06/18 19:31:42 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(const int c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 'a' + 'A');
	return (c);
}
