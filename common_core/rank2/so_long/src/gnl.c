#include "../inc/so_long.h"



#include <fcntl.h>
#include <unistd.h>

char	*get_next_line(int fd); // pode usar sua implementação ou uma lib

int	count_lines(char *filename)
{
	int		fd;
	int		count = 0;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((line = get_next_line(fd)))
	{
		free(line);
		count++;
	}
	close(fd);
	return (count);
}

char	**read_map(char *filename, int *map_height)
{
	int		fd;
	int		i = 0;
	char	*line;
	char	**map;

	*map_height = count_lines(filename);
	map = malloc(sizeof(char *) * (*map_height + 1));
	fd = open(filename, O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		map[i++] = line;
	}
	map[i] = NULL;
	close(fd);
	return (map);
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




int	ft_strlen(char *str)
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

char	*ft_strjoin(char *next_line, char *buffer)
{
	int		i;
	int		s1_len;
	int		s2_len;
	char	*dest;

	s1_len = ft_strlen(next_line);
	s2_len = ft_strlen(buffer);
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