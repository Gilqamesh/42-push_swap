/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 19:30:51 by edavid            #+#    #+#             */
/*   Updated: 2021/06/18 19:30:52 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*head;
	t_list	*tmp;

	head = (t_list *)0;
	new_lst = head;
	while (lst)
	{
		tmp = ft_lstnew((*f)(lst->content));
		if (!tmp)
			ft_lstclear(&new_lst, del);
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
