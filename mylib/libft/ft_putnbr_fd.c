/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 19:31:20 by edavid            #+#    #+#             */
/*   Updated: 2021/06/18 19:31:20 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <limits.h>

void 	ft_putnbr_fd(int n, int fd)
{
	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 10 && n > -10)
	{
		if (n < 0)
		{
			write(fd, &(char){'-'}, 1);
			n *= -1;
		}
		write(fd, &(char){n + '0'}, 1);
		return ;
	}
	ft_putnbr_fd(n / 10, fd);
	if (n < 0)
		n *= -1;
	write(fd, &(char){n % 10 + '0'}, 1);
}
