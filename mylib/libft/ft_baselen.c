#include "libft.h"

int	ft_baselen(unsigned long n, int base)
{
	int	len;

	if (!n)
		return (1);
	len = 0;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}
