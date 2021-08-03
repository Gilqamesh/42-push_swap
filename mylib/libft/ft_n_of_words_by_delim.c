/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n_of_words_by_delim.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 18:16:44 by edavid            #+#    #+#             */
/*   Updated: 2021/08/03 18:16:55 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_n_of_words_by_delim(char *s, char c)
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
