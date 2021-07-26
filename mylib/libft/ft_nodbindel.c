/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodbindel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:32:15 by edavid            #+#    #+#             */
/*   Updated: 2021/07/26 14:22:06 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_nodbindel(void *node)
{
	if (!node)
		return ;
	if (((t_node_binary *)node)->content)
		free(((t_node_binary *)node)->content);
	free(node);
}
