/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 19:30:34 by edavid            #+#    #+#             */
/*   Updated: 2021/06/18 19:30:34 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*r;

	if (size && nmemb > (size_t)(-1) / size)
		return ((void *)0);
	size *= nmemb;
	r = malloc(size);
	if (!r)
		return ((void *)0);
	ft_bzero(r, size);
	return (r);
}
