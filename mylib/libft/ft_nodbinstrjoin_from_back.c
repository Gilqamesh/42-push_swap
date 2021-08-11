/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodbinstrjoin_from_back.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:13:50 by edavid            #+#    #+#             */
/*   Updated: 2021/08/11 17:44:52 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	measure_len(t_node_binary *list, t_node_binary **cur, int *len)
{
	*len = 0;
	(*cur) = list;
	while ((*cur))
	{
		*len += ft_strlen((char *)(*cur)->content);
		if ((*cur)->next)
			(*cur) = (*cur)->next;
		else
			break ;
	}
}

// Allocates and returns a string that is the concatenation of going through
// the list's str contents
char	*ft_nodbinstrjoin_from_back(t_node_binary *list)
{
	int				len;
	t_node_binary	*cur;
	char			*result;
	t_2_int			index_res_tmp;

	if (!list)
		return (ft_strdup(""));
	measure_len(list, &cur, &len);
	result = malloc(len + 1);
	result[len] = '\0';
	index_res_tmp.a = -1;
	while (cur)
	{
		index_res_tmp.b = -1;
		while (((char *)cur->content)[++index_res_tmp.b])
			result[++index_res_tmp.a] = ((char *)cur->content)[index_res_tmp.b];
		cur = cur->prev;
	}
	return (result);
}
