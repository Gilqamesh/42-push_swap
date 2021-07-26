/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 14:18:48 by edavid            #+#    #+#             */
/*   Updated: 2021/07/26 14:20:22 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(void *node)
{
	if (!node)
		return ;
	if (((t_list *)node)->content)
		free(((t_list *)node)->content);
	free(node);
}
