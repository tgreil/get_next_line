#include "libft.h"

char		*ft_strtrim(const char *s)
{
	char	*new;
	int		size;
	int		n;
	int		i;

	i = 0;
	size = 0;
	while (s[i + size] == ' ' || s[i + size] == '\t' || s[i + size] == '\n')
		i++;
	while (s[i + size])
		size++;
	size--;
	while (size >= 0 &&
			(s[i + size] == ' ' || s[i + size] == '\t' || s[i + size] == '\n'))
		size--;
	if (!(new = malloc(++size + 1)))
		return (NULL);
	n = 0;
	while (n < size)
	{
		new[n] = s[i + n];
		n++;
	}
	new[size] = '\0';
	return (new);
}
