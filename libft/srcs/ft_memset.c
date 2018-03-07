#include "libft.h"

void		*ft_memset(void *s, int c, size_t n)
{
	char	*c_s;
	size_t	i;

	i = 0;
	c_s = (char *)s;
	while (i < n)
	{
		c_s[i] = c;
		i++;
	}
	return (s);
}
