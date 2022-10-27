/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcamilo- <lcamilo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 00:28:43 by lcamilo-          #+#    #+#             */
/*   Updated: 2022/10/27 00:28:43 by lcamilo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((char)c == *s)
			return ((char *)s);
		s++;
	}
	if ((char)c == 0)
		return ((char *)s);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (ft_strlen(src));
}

char	*ft_strlendup(const char *s, int i)
{
	char	*string;

	string = malloc( (i + 1 )* sizeof(char) + 1);
	if (!string)
		return (0);
	ft_strlcpy(string, s, i + 1);
	return (string);
}

char	*ft_strlenjoin(char const *s1, char const *s2, int size)
{
	char	*str;
	int		i;
	int		j;

	i = ft_strlen(s1) + size;
	str = malloc(i + 1 * sizeof(char));
	if (!str)
		return (0);
	j = 0;
	while (s1[j] && size)
	{
		str[j] = s1[j];
		j++;
		size--;
	}
	i = 0;
	while (s2[i] && size)
	{
		str[j + i] = s2[i];
		i++;
		size--;
	}
	str[j + i] = 0;
	return (str);
}
