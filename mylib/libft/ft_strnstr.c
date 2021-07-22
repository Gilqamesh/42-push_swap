/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 19:31:37 by edavid            #+#    #+#             */
/*   Updated: 2021/06/18 19:31:37 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	haystack_index;
	size_t	needle_index;

	if (!*needle)
		return ((char *)haystack);
	haystack_index = 0;
	while (len && haystack[haystack_index])
	{
		needle_index = 0;
		while (len - needle_index && haystack[haystack_index + needle_index]
			== needle[needle_index])
		{
			needle_index++;
			if (!needle[needle_index])
				return ((char *)haystack + haystack_index);
		}
		haystack_index++;
		len--;
	}
	return ((char *)0);
}
