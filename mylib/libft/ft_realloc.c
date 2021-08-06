/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:29:42 by edavid            #+#    #+#             */
/*   Updated: 2021/08/06 21:26:53 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_realloc(void *src, size_t size)
{
	void	*new;

	new = ft_calloc(1, size);
	if (!new)
	{
		if (src)
			free(src);
		return ((void *)0);
	}
	if (!src)
		return (new);
	// Wrong
	ft_memmove(new, src, size);
	free(src);
	return (new);
}
