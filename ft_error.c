/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:04:26 by edavid            #+#    #+#             */
/*   Updated: 2021/07/28 10:39:29 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_push_swap.h"

static void	free_mystruct(t_push_swap *mystruct)
{
	// incorrect, the address of mystruct is a different pointer than the original
	ft_nodbinclear(&mystruct->a.head, ft_nodbindel, mystruct->a.n);
	ft_nodbinclear(&mystruct->b.head, ft_nodbindel, mystruct->b.n);
	ft_lstclear(&mystruct->sorted, ft_lstdel);
}

void	ft_error(t_push_swap *mystruct)
{
	write(2, "Error\n", 6);
	free_mystruct(mystruct);
	exit(EXIT_FAILURE);
}
