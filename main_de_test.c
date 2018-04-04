#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#include "get_next_line.h"

int main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		i;
	int 	ret;

	if (ac < 2)
		return (-1);
	for (i = 1; i < ac; i++)
	{
		if ((fd = open(av[i], O_RDONLY)) < 0)
			return (-1);
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			write(1, line, ft_strlen(line));
			write(1, "\n", 1);
			free(line);
		}
		close(fd);
	}
	return (0);
}
