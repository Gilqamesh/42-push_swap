/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodbinadd_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:43:52 by edavid            #+#    #+#             */
/*   Updated: 2021/07/26 10:44:48 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_nodbinadd_back(t_node_binary **lst, t_node_binary *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while ((*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = new;
}
