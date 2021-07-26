/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodbinnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:24:22 by edavid            #+#    #+#             */
/*   Updated: 2021/07/26 10:27:44 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_node_binary	*ft_nodbinnew(void *content)
{
	t_node_binary	*new_el;

	new_el = (t_node_binary *)malloc(sizeof(*new_el));
	if (!new_el)
		return ((t_node_binary *)0);
	new_el->content = content;
	new_el->next = (t_node_binary *)0;
	new_el->prev = (t_node_binary *)0;
	return (new_el);
}
