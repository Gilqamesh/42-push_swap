/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 19:31:40 by edavid            #+#    #+#             */
/*   Updated: 2021/06/18 19:31:40 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*init_str(char **str, int start, int end, char *s)
{
	*str = (char *)malloc(end - start + 2);
	if (!*str)
		return ((char *)0);
	ft_strlcpy(*str, s + start, end - start + 2);
	return (*str);
}

static char	*ft_strtrim2(size_t end_index, char const *set, char const *s1)
{
	int		i;
	size_t	start_index;
	char	*new_str;

	start_index = 0;
	i = 0;
	while (set[i] || !*s1)
	{
		if (s1[start_index] == set[i] || s1[end_index] == set[i])
		{
			if (s1[start_index] == set[i])
				start_index++;
			if (s1[end_index] == set[i])
				end_index--;
			i = 0;
		}
		else
			i++;
		if (end_index < start_index || !*s1)
			return (ft_strdup("\0"));
	}
	return (init_str(&new_str, start_index, end_index, (char *)s1));
}

char 	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end_index;

	if (!s1)
		return ((char *)0);
	end_index = ft_strlen(s1) - 1;
	return (ft_strtrim2(end_index, set, s1));
}
