/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodbinadd_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:33:12 by edavid            #+#    #+#             */
/*   Updated: 2021/07/29 16:49:57 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_nodbinadd_front(t_node_binary **lst, t_node_binary *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
	new->prev = *lst;
}
