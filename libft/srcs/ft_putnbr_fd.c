#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	if ((n < 0 ? -n : n) < 10 && n != INT_MIN)
	{
		if (n < 0)
			ft_putchar_fd('-', fd);
		ft_putchar_fd((n < 0 ? -n : n) + '0', fd);
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		n = n % 10;
		ft_putchar_fd((n < 0 ? -n : n) + '0', fd);
	}
}
