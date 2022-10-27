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

int	read_line(char **line, int fd)
{
	char	*tmp;
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	i;

	i = 1;
	while (!ft_strchr(*line, '\n') && i)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		buffer[i] = 0;
		if (!*line)
			*line = ft_strlendup(buffer, i);
		else if (i)
		{
			tmp = *line;
			*line = ft_strlenjoin(tmp, buffer, i);
			free(tmp);
		}
		if (!*line || (!*line[0] && i))
		{
			free (*line);
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
	int i;

	if (fd < 0)
		return (NULL);
	if (!buffer)
		buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!read_line(&buffer, fd))
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	str = ft_strlendup(buffer, i);
	if (!str)
		return (NULL);
	tmp = buffer;
	buffer = ft_strlendup(tmp + i, ft_strlen(tmp) - i);
	free(tmp);
	return (str);
}

int	main(void)
{
	char	*c;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	c = get_next_line(fd);
	printf("%s\n", c);
	c = get_next_line(fd);
	printf("%s\n", c);
	c = get_next_line(fd);
	printf("%s\n", c);
	c = get_next_line(fd);
	printf("%s\n", c);
	c = get_next_line(fd);
	printf("%s\n", c);
}
