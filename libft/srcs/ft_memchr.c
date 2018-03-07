#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*unc_s;
	size_t			i;

	i = 0;
	unc_s = (unsigned char *)s;
	while (i < n)
	{
		if (unc_s[i] == (unsigned char)c)
			return (unc_s + i);
		i++;
	}
	return (NULL);
}
