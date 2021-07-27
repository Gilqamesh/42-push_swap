/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 11:39:46 by edavid            #+#    #+#             */
/*   Updated: 2021/07/27 11:40:45 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../printf/ft_printf.h"

void	ft_lstprint_int(t_list *lst, int n)
{
	if (!lst)
	{
		ft_printf("List is empty.\n");
		return ;
	}
	while (lst && n)
	{
		ft_printf("%d\n", *(int *)lst->content);
		lst = lst->next;
		if (n > 0 && !--n)
			break ;
	}
}
