/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 12:20:29 by edavid            #+#    #+#             */
/*   Updated: 2021/08/10 20:17:52 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	char_copied;

	while (n--)
	{
		char_copied = *(unsigned char *)src;
		*(unsigned char *)dst++ = *(unsigned char *)src++;
		if (char_copied == (unsigned char)c)
			return (dst);
	}
	return ((void *)0);
}
