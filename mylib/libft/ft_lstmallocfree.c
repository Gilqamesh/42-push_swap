/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmallocfree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:38:19 by edavid            #+#    #+#             */
/*   Updated: 2021/08/04 21:59:52 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
// Free all addresses stored in 'lst' then clears lst and sets
// it to NULL
void	ft_lstmallocfree(t_list **lst)
{
	printf("Hey\n");	
	ft_lstclear(lst, ft_lstdel);
	printf("Hey\n");
}
