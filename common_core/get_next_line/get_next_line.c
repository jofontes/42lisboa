/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:34:44 by josaraiv          #+#    #+#             */
/*   Updated: 2024/12/18 14:29:00 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
			next_line = ft_strjoin(next_line, buffer);
			if (!next_line)
				return (NULL);
			if (next_line[ft_strlen(next_line) - 1] == '\n')
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

// int main()
// {
// 	int fd;
// 	fd = open("text2.txt", O_RDONLY);
// 	char *next_line;
// 	next_line = get_next_line(fd);
// 	printf("%s", next_line);
// 	next_line = get_next_line(fd);
// 	printf("%s", next_line);
// }
// int main()
// {
// 	int fd;
// 	fd = open("text.txt", O_RDONLY);
// 	char *next_line;
// 	next_line = get_next_line(fd);
// 	while(next_line)
// 	{
// 		printf("%s", next_line);
// 		next_line = get_next_line(fd);
// 	}
// }
