/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmallocwrapper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:34:21 by edavid            #+#    #+#             */
/*   Updated: 2021/08/04 22:33:15 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// Malloc instead it also adds the address into 'lst'
// Use ft_lstmallocfree to free all the saved addresses
void	*ft_lstmallocwrapper(t_list **lst, size_t size, bool is_calloc)
{
	void	*new;

	if (!lst)
		return (NULL);
	if (is_calloc)
		new = ft_calloc(1, size);
	else
		new = malloc(size);
	if (!new)
		return (NULL);
	ft_lstadd_front(lst, ft_lstnew(new));
	return (new);
}
