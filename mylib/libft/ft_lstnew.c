/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 19:30:53 by edavid            #+#    #+#             */
/*   Updated: 2021/06/18 19:30:53 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list 	*ft_lstnew(void *content)
{
	t_list	*new_el;

	new_el = (t_list *)malloc(sizeof(*new_el));
	if (!new_el)
		return ((t_list *)0);
	new_el->content = content;
	new_el->next = (t_list *)0;
	return (new_el);
}
