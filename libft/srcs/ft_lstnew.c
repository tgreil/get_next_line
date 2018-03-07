#include "libft.h"

t_list		*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	new->content = (void *)content;
	if (content)
		new->content_size = content_size;
	else
		new->content_size = 0;
	new->next = NULL;
	return (new);
}
