/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:04:58 by josaraiv          #+#    #+#             */
/*   Updated: 2025/06/02 17:19:04 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	count_map_lines(char *path)
{
	int		lines;
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		lines++;
		line = get_next_line(fd);
	}
	return (free(line), close(fd), lines);
}

static int	get_line_width(char *line)
{
	int	width;

	width = 0;
	while (line[width] && line[width] != '\n')
		width++;
	return (width);
}

static int	check_all_lines_same_width(int fd, int expected_width)
{
	char	*line;
	int		current_width;

	line = get_next_line(fd);
	while (line)
	{
		current_width = get_line_width(line);
		if (current_width != expected_width)
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int	is_rectangle(char *path)
{
	int		fd;
	char	*line;
	int		expected_width;
	int		result;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	expected_width = get_line_width(line);
	free(line);
	result = check_all_lines_same_width(fd, expected_width);
	close(fd);
	if (result)
		return (expected_width);
	return (result);
}
