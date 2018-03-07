#include "libft.h"

int		ft_isalnum(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c);
	if (c >= 'A' && c <= 'Z')
		return (c);
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}
