/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:04:58 by josaraiv          #+#    #+#             */
/*   Updated: 2025/05/30 18:53:31 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	read_map(char *path, t_game *game)
{
	char	**map_copy;

	if (!is_rectangle(path))
		return (0);
	game->height = count_map_lines(path);
	game->map = malloc(sizeof(char *) * (game->height + 1));
	game->width = count_map_width(path);
	create_map(path, game);
	if (!surrounded_by_walls(game) || (count_e_p_c(game, 'E') != 1
			|| count_e_p_c(game, 'P') != 1 || count_e_p_c(game, 'C') < 1)
		|| !other_letters(game))
	{
		free_map(game);
		return (0);
	}
	map_copy = copy_map(*game);
	floodfill(map_copy, game->player_x, game->player_y);
	if (!winable(map_copy, game))
	{
		free_map(game);
		free_copy_map(map_copy, game);
		return (0);
	}
	free_copy_map(map_copy, game);
	return (1);
}
