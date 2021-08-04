/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmallocfree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:38:19 by edavid            #+#    #+#             */
/*   Updated: 2021/08/04 20:40:50 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// Free all addresses stored in 'lst' then clears lst and sets
// it to NULL
void	ft_lstmallocfree(t_list **lst)
{
	ft_lstclear(lst, ft_lstdel);
}
