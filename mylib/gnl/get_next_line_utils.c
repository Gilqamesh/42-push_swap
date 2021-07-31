/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 20:31:02 by edavid            #+#    #+#             */
/*   Updated: 2021/06/25 20:31:02 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	contains_newline(char *str, size_t n)
{
	size_t	index_of_newline;

	index_of_newline = 0;
	while (index_of_newline < n)
	{
		if (str[index_of_newline] == '\n')
			return ((int)index_of_newline);
		index_of_newline++;
	}
	return (index_of_newline);
}

static char	*strjoin_return_helper(char *s1, char *s2)
{
	if (!s1 && s2)
		return (s2);
	if (s1 && !s2)
		return (s1);
	return ((char *)0);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new;
	char	*r;
	char	*tmp;

	if (!s1 || !s2)
		return (strjoin_return_helper(s1, s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = (char *)malloc(s1_len + s2_len + 1);
	if (!new)
		return ((char *)0);
	r = new;
	tmp = s1;
	while (s1_len--)
		*r++ = *tmp++;
	free(s1);
	tmp = s2;
	while (s2_len--)
		*r++ = *tmp++;
	free(s2);
	*r = '\0';
	return (new);
}

char	*ft_strdup_v2(const char *s, int n)
{
	char	*new;
	char	*r;

	new = (char *)malloc(n + 1);
	if (!new)
		return ((char *)0);
	r = new;
	while (n--)
		*new++ = *s++;
	*new = '\0';
	return (r);
}
