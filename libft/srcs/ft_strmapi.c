#include "libft.h"

char		*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	if (!(new = malloc(i + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
