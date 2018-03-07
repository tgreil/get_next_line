#include "libft.h"

void		ft_bzero(void *s, size_t n)
{
	char	*c_s;
	size_t	i;

	i = 0;
	c_s = (char *)s;
	while (i < n)
	{
		c_s[i] = 0;
		i++;
	}
}
