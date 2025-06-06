/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:04:58 by josaraiv          #+#    #+#             */
/*   Updated: 2025/06/06 10:39:40 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	init_game(t_game *game, char *map_path)
{
	if (!read_map(map_path, game))
		return (write(2, "Error - invalid map\n", 20), 0);
	game->mlx = mlx_init();
	if (!check_map_size(game))
		return (0);
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE, game->height
			* TILE_SIZE, "so_long");
	init_all_images(game);
	return (1);
}

int	main(int ac, char **av)
{
	static t_game	game;

	if (ac != 2 || !is_valid_ber_file(av[1]))
		return (write(2, "Error - invalid input\n", 22), 0);
	if (!init_game(&game, av[1]))
		return (0);
	mlx_loop_hook(game.mlx, (void *)loop, &game);
	mlx_key_hook(game.win, handle_input, &game);
	mlx_hook(game.win, 17, 0L, handle_window_close, &game);
	mlx_loop(game.mlx);
	close_game(&game);
	return (0);
}
