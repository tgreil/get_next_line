#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	char	*c_n;

	c_n = ft_itoa(n);
	ft_putstr_fd(c_n, fd);
	free(c_n);
}
