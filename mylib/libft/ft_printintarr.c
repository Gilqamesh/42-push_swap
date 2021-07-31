/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printintarr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 17:50:40 by edavid            #+#    #+#             */
/*   Updated: 2021/07/31 17:52:34 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf/ft_printf.h"

void	ft_printintarr(int *arr, int n)
{
	int	i;

	if (!arr || !n)
		return ;
	i = -1;
	while (++i < n)
	{
		ft_printf("%d", arr[i]);
		if (i < n - 1)
			ft_printf(" ");
	}
	ft_printf("\n");
}
