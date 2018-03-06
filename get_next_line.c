#include "get_next_line.h"

int		get_next_line_init(t_gnl **p, const int fd)
{
	t_gnl_one	*new_list;
	int			i;

	i = 0;
	if (*p == NULL)
	{
		if (!((*p) = malloc(sizeof(t_gnl))))
			return (EXIT_ERROR);
		(*p)->list = NULL;
		(*p)->list_size = 0;
	}
	while (i < (*p)->list_size)
		if ((*p)->list[i++].fd == fd)
			return (i - 1);
	if (!(new_list = malloc(sizeof(t_gnl_one) * ((*p)->list_size + 1))))
		return (EXIT_ERROR);
	ft_memcpy(new_list, (*p)->list, sizeof(t_gnl_one) * (*p)->list_size);
	new_list[(*p)->list_size].fd = fd;
	new_list[(*p)->list_size].rest = NULL;
	new_list[(*p)->list_size].rest_size = 0;
	(*p)->list_size++;
	if ((*p)->list)
		free((*p)->list);
	(*p)->list = new_list;
	return ((*p)->list_size - 1);
}

int		line_is_full(char *line, int line_size)
{
	int	i;

	i = 0;
	if (!line)
		return (EXIT_ERROR);
	while (i < line_size)
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (EXIT_ERROR);
}

int		get_next_line_one2(t_gnl_one *l, char **line, int size_line)
{
	char	*new_line;
	char	*new_rest;

	if (size_line < 0)
	{
		*line = NULL;
		if (l->rest)
			free(l->rest);
		return (EXIT_SUCCESS);
	}
	if (!(new_line = malloc(size_line + 1)))
		return (EXIT_ERROR);
	*line = ft_memcpy(new_line, l->rest, size_line);
	(*line)[size_line] = 0;
	if (!(new_rest = malloc(l->rest_size - size_line)))
		return (EXIT_ERROR);
	ft_memcpy(new_rest, l->rest + size_line + 1, l->rest_size - size_line);
	free(l->rest);
	l->rest = new_rest;
	l->rest_size = l->rest_size - size_line - 1;
	return (EXIT_SUCCESS);
}

int		get_next_line_one(t_gnl_one *l, const int fd, char **line)
{
	char	buf[BUFF_SIZE];
	int		ret_read;
	char	*tmp;
	int		i;

	ret_read = 1;
	while (ret_read && (i = line_is_full(l->rest, l->rest_size)) == EXIT_ERROR)
	{
		if ((ret_read = read(fd, buf, BUFF_SIZE)) < 0)
			return (READ_ERROR);
		if (!(tmp = malloc(l->rest_size + ret_read + 1)))
			return (EXIT_ERROR);
		if (l->rest)
			ft_memcpy(tmp, l->rest, l->rest_size);
		ft_memcpy(tmp + l->rest_size, buf, ret_read);
		if (l->rest)
			free(l->rest);
		l->rest = tmp;
		l->rest_size += ret_read;
	}
	if (get_next_line_one2(l, line, i) == EXIT_ERROR)
		return (EXIT_ERROR);
	return (ret_read);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*p = NULL;
	t_gnl_one		*tmp;
	int				rank;
	int				ret_r;

	if ((rank = get_next_line_init(&p, fd)) == EXIT_ERROR)
		return (EXIT_ERROR);
	if ((ret_r = get_next_line_one(&(p->list[rank]), fd, line)) == EXIT_ERROR)
		return (EXIT_ERROR);
	if (ret_r > 0)
		return (1);
	if (!(tmp = malloc(sizeof(t_gnl_one) * (p->list_size - 1))))
		return (EXIT_ERROR);
	ft_memcpy(tmp, p->list, sizeof(t_gnl_one) * rank);
	ft_memcpy(&(tmp[rank]), &(p->list[rank + 1]),
								sizeof(t_gnl_one) * (p->list_size - rank - 1));
	free(p->list);
	p->list = tmp;
	if (--p->list_size == 0)
	{
		free(tmp);
		free(p);
		p = NULL;
	}
	return (0);
}
