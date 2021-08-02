#include "libft.h"

void	ft_putnstr_fd(char *s, int n, int fd)
{
	while (s && *s && n-- > 0)
		ft_putchar_fd(*s++, fd);
}
