#include "libft.h"

char		*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;

	if (!(new = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1)))
		return (NULL);
	ft_strcpy(new, (char *)s1);
	ft_strcat(new, (char *)s2);
	return (new);
}
