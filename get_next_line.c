#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1u];
	char		*lines;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lines = NULL;
	bytes = 0;
	while (!lines || !ft_strchr(lines, '\n'))
	{
		if (!*buff)
		{
			bytes = read(fd, buff, BUFFER_SIZE);
			if (bytes == 0)
				return (lines);
			if (bytes < 0 && lines)
				free(lines);
			if (bytes < 0)
				return (NULL);
			buff[bytes] = '\0';
		}
		lines = ft_mix(lines, buff);
	}
	return (lines);
}
