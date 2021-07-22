/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 19:31:39 by edavid            #+#    #+#             */
/*   Updated: 2021/06/18 19:31:39 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*r;
	char	*tmp;

	r = ft_strchr(s, c);
	if (!r || !*r)
		return (r);
	while (1)
	{
		tmp = ft_strchr(r + 1, c);
		if (!tmp)
			break ;
		r = tmp;
	}
	return (r);
}
