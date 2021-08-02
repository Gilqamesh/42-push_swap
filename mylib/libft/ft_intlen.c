#include "libft.h"

int	ft_intlen(int d)
{
	int	len;

	if (!d)
		return (1);
	len = 0;
	while (d)
	{
		d /= 10;
		len++;
	}
	return (len);
}
