/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:29:42 by edavid            #+#    #+#             */
/*   Updated: 2021/07/22 14:32:19 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_realloc(void *src, size_t size)
{
	void	*new;

	new = malloc(size);
	if (!new)
		return (src);
	if (!src)
		return (new);
	ft_memmove(new, src, size);
	free(src);
	return (new);
}
