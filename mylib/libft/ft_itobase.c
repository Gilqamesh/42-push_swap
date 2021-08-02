#include "libft.h"
#include <stdlib.h>

static int	itobase_helper(char **result, int len)
{
	*result = malloc(len + 1);
	if (!*result)
		return (0);
	(*result)[len] = '\0';
	return (1);
}

char	*ft_itobase(unsigned long n, int base)
{
	int		len;
	char	*result;

	if (base < 2)
		return ((char *)0);
	len = ft_baselen(n, base);
	if (!itobase_helper(&result, len))
		return ((char *)0);
	while (len-- > 0)
	{
		if (n % base > 9)
			result[len] = n % base - 10 + 'a';
		else
			result[len] = n % base + '0';
		n /= base;
	}
	return (result);
}
