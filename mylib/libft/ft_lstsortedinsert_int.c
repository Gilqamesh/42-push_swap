/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsortedinsert_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:03:47 by edavid            #+#    #+#             */
/*   Updated: 2021/07/27 11:47:17 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsortedinsert_int(t_list **lst, t_list *new)
{
	t_list	*tmp;
	t_list	*cur;

	if (!new || !lst)
		return ;
	if (!*lst)
		*lst = new;
	cur = *lst;
	while (cur->next && *(int *)cur->next->content < *(int *)new->content)
		cur = cur->next;
	tmp = cur->next;
	cur->next = new;
	new->next = tmp;
}
