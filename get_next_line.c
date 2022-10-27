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
	
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		tmp[BUFFER_SIZE + 1];
	ssize_t		i;
	ssize_t		y;

	if (fd < 0)
		return (NULL);
	i = read(fd, tmp, BUFFER_SIZE);
	tmp[i] = 0;
	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	y = 0;
	printf("tmp :\n%s\n", tmp);
	printf("========================\n");
	while (tmp[y] != '\n')
	{
		buffer[y] = tmp[y];
		printf("Char : %c\n", tmp[y]);
		y++;
	}
	printf("Print : %s\n", buffer);
	return ("s");
}

int	main(void)
{
	char	*c;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	c = get_next_line(fd);
	c = get_next_line(fd);
	c = get_next_line(fd);
}
