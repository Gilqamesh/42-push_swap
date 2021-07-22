/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edavid <edavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:34:46 by edavid            #+#    #+#             */
/*   Updated: 2021/07/22 14:06:45 by edavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_conversions.h"
#include "../libft/libft.h"

void	print_ultoh(unsigned long n, char check_casing)
{
	static char	hexa[] = "0123456789abcdef";

	if (n < 16)
	{
		if (check_casing >= 'a' && check_casing <= 'z')
			write(1, &hexa[n % 16], 1);
		else
			write(1, &(char){ft_toupper(hexa[n % 16])}, 1);
		return ;
	}
	print_ultoh(n / 16, check_casing);
	if (check_casing >= 'a' && check_casing <= 'z')
		write(1, &hexa[n % 16], 1);
	else
		write(1, &(char){ft_toupper(hexa[n % 16])}, 1);
}

int	digits_in_hexa(unsigned long n)
{
	int	digits;

	if (n == 0)
		return (1);
	digits = 0;
	while (n)
	{
		n /= 16;
		digits++;
	}
	return (digits);
}

void	shift_str(char **str)
{
	int		str_len;
	char	*trunc_str;

	if (!str || !*str)
		return ;
	str_len = ft_strlen(*str);
	if (str_len < 2)
	{
		trunc_str = malloc(1);
		*trunc_str = '\0';
	}
	else
		trunc_str = ft_strdup(*str + 1);
	free(*str);
	*str = trunc_str;
}

char	*ft_utox(unsigned int n, char check_casing)
{
	int			len;
	char		*str;
	static char	hexa[] = "0123456789abcdef";

	len = digits_in_hexa(n);
	if (!ft_initstr(&str, len, !n))
		return ((char *)0);
	while (n)
	{
		if (check_casing >= 'a' && check_casing <= 'z')
			*(str + --len) = hexa[n % 16];
		else
			*(str + --len) = ft_toupper(hexa[n % 16]);
		n /= 16;
	}
	return (str);
}

char	*ft_utoa(unsigned int n)
{
	int		len;
	char	*str;

	len = ft_uintlen(n);
	if (!ft_initstr(&str, len, !n))
		return ((char *)0);
	while (n)
	{
		*(str + --len) = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
