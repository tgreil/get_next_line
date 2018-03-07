#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!(new = malloc(size)))
		return (NULL);
	while (i < size)
	{
		new[i] = '\0';
		i++;
	}
	return (new);
}
