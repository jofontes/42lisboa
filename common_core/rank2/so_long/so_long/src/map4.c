/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:04:58 by josaraiv          #+#    #+#             */
/*   Updated: 2025/06/02 17:19:10 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	is_valid_letter(char c)
{
	if (c == 'P' || c == 'E' || c == 'C' || c == '1' || c == '0')
		return (1);
	return (0);
}

int	other_letters(t_game *game)
{
	int	i;
	int	j;

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

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map)
		return ;
	while (i < game->height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}

void	free_copy_map(char **map_copy, t_game *game)
{
	int	i;

	i = 0;
	if (!map_copy)
		return ;
	while (i < game->height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

void	create_map(char *path, t_game *game)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return ;
	while (i < game->height)
	{
		game->map[i] = get_next_line(fd);
		i++;
	}
	game->map[i] = NULL;
	close(fd);
}
