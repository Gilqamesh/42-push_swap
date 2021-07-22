/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 19:31:27 by edavid            #+#    #+#             */
/*   Updated: 2021/06/18 19:31:27 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*new;

	len = ft_strlen(s);
	new = (char *)malloc(len + 1);
	if (!new)
		return ((char *)0);
	ft_strlcpy(new, s, len + 1);
	return (new);
}
