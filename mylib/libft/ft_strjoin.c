/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 19:31:28 by edavid            #+#    #+#             */
/*   Updated: 2021/06/18 19:31:28 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char 	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new;

	if (!s1 || !s2)
		return ((char *)0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = (char *)malloc(s1_len + s2_len + 1);
	if (!new)
		return ((char *)0);
	ft_strlcpy(new, s1, s1_len + 1);
	ft_strlcpy(new + s1_len, s2, s2_len + 1);
	return (new);
}
