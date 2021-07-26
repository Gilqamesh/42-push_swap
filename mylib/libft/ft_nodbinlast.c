/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodbinlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:41:41 by edavid            #+#    #+#             */
/*   Updated: 2021/07/26 10:43:28 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node_binary	*ft_nodbinlast(t_node_binary *lst)
{
	t_node_binary	*prev;

	prev = lst;
	while (lst)
	{
		prev = lst;
		lst = lst->next;
	}
	return (prev);
}
