#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*c_dest;
	char	*c_src;
	size_t	i;

	i = 0;
	c_src = (char *)src;
	c_dest = (char *)dest;
	while (i < n)
	{
		c_dest[i] = c_src[i];
		i++;
	}
	return (dest);
}
