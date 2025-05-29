/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:04:58 by josaraiv          #+#    #+#             */
/*   Updated: 2025/05/29 15:17:54 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"




int count_map_lines(const char *path)
{
	int lines;
	char *line;
	int fd;

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

int count_map_width(const char *path)
{
	int width;
	char *line;
	int fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	
	width = 0;
	line = get_next_line(fd);
	if (line)
	{
		while (line[width] && line[width] != '\n')
			width++;
	}
	return (free(line), close(fd), width);
}



int is_retangulo(const char *path)
{
	int fd;
	char *line;
	int expected_width;
	int current_width;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	expected_width = 0;
	while (line[expected_width] && line[expected_width] != '\n')
		expected_width++;
	free(line);
	while ((line = get_next_line(fd)) != NULL)
	{
		current_width = 0;
		while (line[current_width] && line[current_width] != '\n')
			current_width++;
		if (current_width != expected_width)
			return (free(line), close(fd), 0);
		free(line);
	}
	close(fd);
	return (1);
}


int surrounded_by_walls(t_game *game)
{
	int i;

	i = 0;
	while(i < game->width)//top
	{
		if(game->map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while(i < game->width)//fundo
	{
		if(game->map[game->height-1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while(i < game->height)//laterais
	{
		if(game->map[i][0] != '1' || game->map[i][game->width-1] != '1')
			return (0);
		i++;
	}
	return (1);
}






int count_E_P_C(t_game *game, char letter)
{
	int i;
	int j;
	int temp;
	
	i = 0;
	j = 0;
	temp = 0;
	while (j < game->height)
	{
		i = 0;
		while (i < game->width)
		{
			if (game->map[j][i] == letter && letter != 'P')
				temp++;
			else if(game->map[j][i] == letter && letter == 'P')
			{
				game->player_y = j;
				game->player_x = i;
				temp++;
			}
			i++;
		}
		j++;
	}
	return (temp);
}


int is_valid_letter(char c)
{
	if (c == 'P' || c == 'E' || c == 'C' || c == '1' || c == '0')
		return(1);
	return (0);
}



int other_letters(t_game *game)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (j < game->height)
	{
		i = 0;
		while (i < game->width)
		{
			if (!is_valid_letter(game->map[j][i]))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}








int read_map(const char *path, t_game *game)
{
	// char	**map_copy;
	if (!is_retangulo(path))
		return (0);
	
	game->height = count_map_lines(path);
	game->map = malloc(sizeof(char*) * (game->height + 1));
	game->width = count_map_width(path);



	int i;
	i = 0;

	int fd;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
		
	while (i < game->height)
	{
		game->map[i] = get_next_line(fd);
		i++;	
	}
	game->map[i] = NULL;
	close(fd);
	if (!surrounded_by_walls(game))
		return (0);
	if (count_E_P_C(game, 'E') != 1 || count_E_P_C(game, 'P') != 1 || count_E_P_C(game, 'C') < 1)
		return (0);
	if (!other_letters(game))
		return (0);
	


	// map_copy = copy_map(game);
	// floodfill(map_copy, game->player_x, game->player_y);
	
	return (1);
}


