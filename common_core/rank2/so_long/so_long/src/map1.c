/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:04:58 by josaraiv          #+#    #+#             */
/*   Updated: 2025/06/06 11:40:22 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	check_elements(t_game *game)
{
	if (!surrounded_by_walls(game) || count_e_p_c(game, 'E') != 1
		|| count_e_p_c(game, 'P') != 1 || count_e_p_c(game, 'C') < 1
		|| !other_letters(game))
		return (0);
	return (1);
}

static int	check_paths(t_game *game)
{
	char	**map;

	map = copy_map(*game);
	floodfill(map, game->player_x, game->player_y);
	if (!winable(map, game))
		return (free_copy_map(map, game), 0);
	free_copy_map(map, game);
	map = copy_map(*game);
	floodfill2(map, game->player_x, game->player_y);
	if (!check_e(game, map))
		return (free_copy_map(map, game), 0);
	return (free_copy_map(map, game), 1);
}

int	read_map(char *path, t_game *game)
{
	game->width = is_rectangle(path);
	if (!game->width)
		return (0);
	game->height = count_map_lines(path);
	game->map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->map)
		return (0);
	create_map(path, game);
	if (!check_elements(game) || !check_paths(game))
		return (free_map(game), 0);
	return (1);
}
