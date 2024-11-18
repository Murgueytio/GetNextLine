/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oscamurg <oscamurg@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-15 18:28:08 by oscamurg          #+#    #+#             */
/*   Updated: 2024-11-15 18:28:08 by oscamurg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*destine;
	const unsigned char	*precede;

	destine = dst;
	precede = src;
	if (destine > precede)
		while (len--)
			destine[len] = precede[len];
	else
		while (len--)
			*destine++ = *precede++;
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	const char	*s;

	if (!str)
		return (0);
	s = str;
	while (*s)
		s++;
	return (s - str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j] != '\n')
		str[i++] = s2[j++];
	if (s2[j] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if ((unsigned char)c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	i = 0;
	while (s[i] != (unsigned char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)s + i);
}

char	*ft_mix(char *str, char *buff)
{
	char	*mix;
	char	*next_line;

	mix = ft_strjoin(str, buff);
	if (str)
		free(str);
	next_line = ft_strchr(buff, '\n');
	if (next_line)
		ft_memmove(buff, next_line + 1,
			ft_strlen(next_line + 1) + 1);
	else
		*buff = '\0';
	return (mix);
}
