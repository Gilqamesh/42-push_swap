/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 19:31:32 by edavid            #+#    #+#             */
/*   Updated: 2021/06/18 19:31:32 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	if (!src)
		return (0);
	len = ft_strlen(src);
	if (size)
	{
		while (--size && *src)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (len);
}
