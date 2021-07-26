/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodbinmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:48:51 by edavid            #+#    #+#             */
/*   Updated: 2021/07/26 19:24:11 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node_binary	*ft_nodbinmap(t_node_binary *lst, void *(*f)(void *),
void (*del)(void *))
{
	t_node_binary	*new_lst;
	t_node_binary	*head;
	t_node_binary	*tmp;

	head = (t_node_binary *)0;
	new_lst = head;
	while (lst)
	{
		tmp = ft_nodbinnew((*f)(lst->content));
		if (!tmp)
			ft_nodbinclear(&new_lst, del, -1);
		if (!head)
		{
			head = tmp;
			new_lst = tmp;
		}
		else
		{
			head->next = tmp;
			head = head->next;
		}
		lst = lst->next;
	}
	return (new_lst);
}
