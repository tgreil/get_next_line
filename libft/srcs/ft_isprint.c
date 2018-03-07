#include "libft.h"

int		ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (c);
	return (0);
}
