/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 19:31:23 by edavid            #+#    #+#             */
/*   Updated: 2021/06/26 17:46:24 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**ft_free(char ***s, int i)
{
	while (i--)
		free(*(*s + i));
	free(*s);
	return ((char **)0);
}

static int	ft_n_of_words_by_delim(char *s, char c)
{
	int	in_word;
	int	n_of_words;

	n_of_words = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!in_word)
			{
				in_word = 1;
				n_of_words++;
			}
		}
		else
			in_word = 0;
		s++;
	}
	return (n_of_words);
}

static char	**split_fn(char **splits_array, int n_of_splits,
char const *s, int c)
{
	int	i;

	i = -1;
	while (++i <= n_of_splits)
	{
		while (*s == c)
			s++;
		if (i < n_of_splits || ft_strchr(s, c))
			*(splits_array + i) = ft_substr(s, 0,
					(size_t)(ft_strchr(s, c) - s));
		else
			*(splits_array + i) = ft_strdup(s);
		if (!*(splits_array + i))
			return (ft_free(&splits_array, i));
		s = ft_strchr(s, c);
	}
	return (splits_array);
}

char	**ft_split(char const *s, char c)
{
	int		n_of_splits;
	char	**splits_array;

	if (!s)
		return ((char **)0);
	n_of_splits = ft_n_of_words_by_delim((char *)s, c) - 1;
	splits_array = (char **)malloc((n_of_splits + 2) * sizeof(*splits_array));
	if (!splits_array)
		return ((char **)0);
	*(splits_array + n_of_splits + 1) = (char *)0;
	return (split_fn(splits_array, n_of_splits, s, c));
}
