/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:02:09 by edavid            #+#    #+#             */
/*   Updated: 2021/06/17 14:11:13 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*r;

	if (!dst && !src)
		return (dst);
	r = dst;
	while (n--)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (r);
}
