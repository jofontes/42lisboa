/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:34:44 by josaraiv          #+#    #+#             */
/*   Updated: 2025/05/26 14:31:58 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	gnl_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

static char	*gnl_strjoin(char *next_line, char *buffer)
{
	int		i;
	int		s1_len;
	int		s2_len;
	char	*dest;

	s1_len = gnl_strlen(next_line);
	s2_len = gnl_strlen(buffer);
	dest = malloc(s1_len + s2_len + 1);
	if (!dest)
		return (free(next_line), NULL);
	dest[s1_len + s2_len] = '\0';
	i = -1;
	while (++i < s1_len)
		dest[i] = next_line[i];
	free(next_line);
	i = -1;
	while (++i < s2_len)
		dest[s1_len + i] = buffer[i];
	i = -1;
	while (buffer[s2_len + ++i])
		buffer[i] = buffer[s2_len + i];
	buffer[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*next_line;
	int			bytes_read;

	next_line = NULL;
	bytes_read = 1;
	while ((fd >= 0 && BUFFER_SIZE > 0) && bytes_read > 0)
	{
		if (buffer[0])
		{
			next_line = gnl_strjoin(next_line, buffer);
			if (!next_line)
				return (NULL);
			if (next_line[gnl_strlen(next_line) - 1] == '\n')
				break ;
		}
		else
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read < 0)
				return (free(next_line), NULL);
			buffer[bytes_read] = '\0';
		}
	}
	return (next_line);
}
