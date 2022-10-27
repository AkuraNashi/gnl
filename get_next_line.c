/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <lcamilo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:28:46 by lcamilo-          #+#    #+#             */
/*   Updated: 2022/10/27 02:37:48 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		tmp[BUFFER_SIZE + 1];
	ssize_t		i;

	i = read(fd, tmp, BUFFER_SIZE);
	//while (tmp[i] == "\n")
	tmp[i] = 0;
	buffer = tmp;
	printf("%s", buffer);
	return ("s");
}

int	main(void)
{
	char	*c;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	c = get_next_line(fd);
}
