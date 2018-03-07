#include "libft.h"

int		ft_isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c);
	if (c >= 'A' && c <= 'Z')
		return (c);
	return (0);
}
