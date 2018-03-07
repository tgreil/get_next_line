#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	compar;
	size_t	i;

	i = 0;
	while (s1[i])
	{
		compar = 0;
		while (s1[i + compar] && s2[compar] && i + compar < n &&
								s1[i + compar] == s2[compar])
			compar++;
		if (!s2[compar])
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
