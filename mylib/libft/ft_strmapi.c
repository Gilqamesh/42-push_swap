/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 19:31:35 by edavid            #+#    #+#             */
/*   Updated: 2021/06/18 19:31:35 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char 	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			s_len;
	char			*str;

	if (!s)
		return ((char *)0);
	s_len = ft_strlen(s);
	str = (char *)malloc(s_len + 1);
	if (!str)
		return ((char *)0);
	*(str + s_len) = '\0';
	i = 0;
	while (*(s + i))
	{
		*(str + i) = (*f)(i, *(s + i));
		i++;
	}
	return (str);
}
