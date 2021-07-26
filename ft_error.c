/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:04:26 by edavid            #+#    #+#             */
/*   Updated: 2021/07/26 10:21:12 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_push_swap.h"

static void	free_mystruct(t_push_swap *mystruct)
{
	
}

void	ft_error(t_push_swap *mystruct)
{
	write(2, "Error\n", 6);
	free_mystruct(mystruct);
	exit(EXIT_FAILURE);
}
