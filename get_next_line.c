/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <lcamilo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:28:46 by lcamilo-          #+#    #+#             */
/*   Updated: 2022/10/27 19:39:42 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);

void	*ft_calloc(size_t n, size_t size)
{
	void	*v;

	v = malloc(n * size);
	if (!v)
		return (0);
	return (ft_memset(v, 0, n * size));
}

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
		str[i++] = c;
	return (s);
}

int	read_line(char **line, int fd)
{
	char	*tmp;
	char	buffer[BUFFER_SIZE + 1];
	int		i;

	i = 1;
	while (!ft_strchr(*line, '\n') && i)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i && !*line)
		{
			buffer[i] = 0;
			*line = ft_strlendup(buffer, i);
		}
		else if (i)
		{
			tmp = *line;
			*line = ft_strlenjoin(tmp, buffer, i);
			free(tmp);
		}
		if (!*line || (!*line[0] && !i))
		{
			free(*line);
			*line = NULL;
			return (0);
		}
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*tmp;
	char		*str;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		if (buffer)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_line(&buffer, fd))
	{
		free(buffer);
		return (NULL);
	}
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	str = ft_strlendup(buffer, i);
	if (!str)
		return (NULL);
	tmp = buffer;
	buffer = ft_strlendup(tmp + i, ft_strlen(tmp + i));
	if (!buffer)
		return (NULL);
	free(tmp);
	return (str);
}
