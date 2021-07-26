/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodbinclear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:46:48 by edavid            #+#    #+#             */
/*   Updated: 2021/07/26 10:47:11 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_nodbinclear(t_node_binary **lst, void (*del)(void *))
{
	t_node_binary	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_nodbindelone(*lst, del);
		*lst = tmp;
	}
}
