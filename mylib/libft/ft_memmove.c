/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 19:31:15 by edavid            #+#    #+#             */
/*   Updated: 2021/06/18 19:31:15 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*r;

	if (!dest && !src)
		return (dest);
	r = dest;
	while (n--)
	{
		if (src > dest)
			*(unsigned char *)dest++ = *(unsigned char *)src++;
		else
			*((unsigned char *)dest + n) = *((unsigned char *)src + n);
	}
	return (r);
}
