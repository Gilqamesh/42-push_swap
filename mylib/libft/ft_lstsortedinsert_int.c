/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsortedinsert_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:03:47 by edavid            #+#    #+#             */
/*   Updated: 2021/07/26 14:11:58 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsortedinsert_int(t_list *lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	while (lst->next && *(int *)(lst->next->content) < *(int *)(new->content))
		lst = lst->next;
	tmp = lst->next;
	lst->next = new;
	new->next = tmp;
}
