/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:04:58 by josaraiv          #+#    #+#             */
/*   Updated: 2025/06/02 17:18:56 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	render_tile(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map[y][x];
	if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->floor_img.img, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall_img.img, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->colec_img.img, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player_img.img, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit_img.img, x
			* TILE_SIZE, y * TILE_SIZE);
}

int	loop(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
	return (1);
}
