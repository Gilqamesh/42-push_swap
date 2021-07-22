/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 19:31:41 by edavid            #+#    #+#             */
/*   Updated: 2021/06/18 19:31:41 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*empty_str(void)
{
	char	*empty;

	empty = (char *)malloc(1);
	if (!empty)
		return ((char *)0);
	*empty = '\0';
	return (empty);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*new;

	if (!s)
		return ((char *)0);
	s_len = ft_strlen(s);
	if (s_len <= (size_t)start)
		return (empty_str());
	if (s_len < (size_t)start + len)
		len = s_len - (size_t)start;
	new = (char *)malloc(len + 1);
	if (!new)
		return ((char *)0);
	ft_strlcpy(new, s + start, len + 1);
	return (new);
}
