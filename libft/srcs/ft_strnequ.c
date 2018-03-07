#include "libft.h"

int		ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (ft_tolower(s1[i]) != ft_tolower(s2[i]))
			return (0);
		i++;
	}
	return (1);
}
