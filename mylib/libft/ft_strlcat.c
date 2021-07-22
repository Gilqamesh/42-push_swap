/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 19:31:30 by edavid            #+#    #+#             */
/*   Updated: 2021/06/18 19:31:30 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dst;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (size <= len_dst)
		return (size + len_src);
	if (size)
	{
		while (size && *dst)
		{
			dst++;
			size--;
		}
		if (size)
		{
			while (--size && *src)
				*dst++ = *src++;
			*dst = '\0';
		}
	}
	return (len_dst + len_src);
}
