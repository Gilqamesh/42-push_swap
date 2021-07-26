/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodbinprint_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 11:32:11 by edavid            #+#    #+#             */
/*   Updated: 2021/07/26 13:45:37 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../printf/ft_printf.h"

void	ft_nodbinprint_int(t_node_binary *lst, int n)
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
