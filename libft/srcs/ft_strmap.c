#include "libft.h"

char		*ft_strmap(const char *s, char (*f)(char))
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
		new[i] = f(s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
