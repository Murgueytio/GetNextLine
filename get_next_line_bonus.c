/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscamurg <oscamurg@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-15 18:31:21 by oscamurg          #+#    #+#             */
/*   Updated: 2024-11-15 18:31:21 by oscamurg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[10240][BUFFER_SIZE + 1u];
	char		*lines;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	lines = NULL;
	bytes = 0;
	while (!lines || !ft_strchr(lines, '\n'))
	{
		if (!*buff[fd])
		{
			bytes = read(fd, buff[fd], BUFFER_SIZE);
			if (bytes == 0)
				return (lines);
			if (bytes < 0 && lines)
				free(lines);
			if (bytes < 0)
				return (NULL);
			buff[fd][bytes] = '\0';
		}
		lines = ft_mix(lines, buff[fd]);
	}
	return (lines);
}
