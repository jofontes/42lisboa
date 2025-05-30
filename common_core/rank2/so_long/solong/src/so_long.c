/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:04:58 by josaraiv          #+#    #+#             */
/*   Updated: 2025/05/30 19:20:05 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	handle_input(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;
	int	c_count;

	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == 65307) // ESC
	{
		mlx_loop_end(game->mlx);
	}
	else if (keycode == 119) // W
		new_y--;
	else if (keycode == 115) // S
		new_y++;
	else if (keycode == 97) // A
		new_x--;
	else if (keycode == 100) // D
		new_x++;
	if (game->map[new_y][new_x] != '1')
	{
		if (game->map[new_y][new_x] == 'E')
		{
			c_count = count_e_p_c(game, 'C');
			if (c_count == 0)
		{
			mlx_loop_end(game->mlx);
		}

			else
				return (1);
		}
		if (game->map[game->player_y][game->player_x] == 'P')
			game->map[game->player_y][game->player_x] = '0';
		game->player_x = new_x;
		game->player_y = new_y;
		game->map[new_y][new_x] = 'P';
	}
	return (1);
}

void	init_image(t_game *game, t_image *img, char *path)
{
	img->img = mlx_xpm_file_to_image(game->mlx, (char *)path, &img->width,
			&img->height);
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
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win,
					game->floor_img.img, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->wall_img.img, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->colec_img.img, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win,
					game->player_img.img, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->exit_img.img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	return (1);
}

void	free_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player_img.img);
	mlx_destroy_image(game->mlx, game->wall_img.img);
	mlx_destroy_image(game->mlx, game->floor_img.img);
	mlx_destroy_image(game->mlx, game->colec_img.img);
	mlx_destroy_image(game->mlx, game->exit_img.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}


void	close_game(t_game *game)
{
	free_map(game);
	free_game(game);
}


int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		write(2, "Error - invalid input\n", 22);
		return (0);
	}
	if (!read_map(av[1], &game))
	{
		write(2, "Error - invalid map\n", 20);
		return (1);
	}
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.width * TILE_SIZE, game.height
			* TILE_SIZE, "so_long");
	init_image(&game, &game.player_img, "textures/cursor.xpm");
	init_image(&game, &game.colec_img, "textures/colec.xpm");
	init_image(&game, &game.wall_img, "textures/wall.xpm");
	init_image(&game, &game.exit_img, "textures/exit.xpm");
	init_image(&game, &game.floor_img, "textures/floor.xpm");
	mlx_loop_hook(game.mlx, (void *)loop, &game);
	mlx_key_hook(game.win, handle_input, &game);
	mlx_loop(game.mlx);
	close_game(&game);
}

// int	main(void)
// {
// 	t_game	game;

// 	if (read_map("maps/map.ber", &game))
// 	{
// 		printf("ok");
// 		free_map(&game);
// 	}
// 	else
// 	{
// 		printf("erro");
// 	}
// 	return (0);
// }

// int i;
// printf("Mapa (%d x %d):\n", game.height, game.width);
// for (i = 0; i < game.height; i++)
// {
// 	printf("%s", game.map[i]); // Cada linha já inclui o '\n'
// 	free(game.map[i]);
// }

//------------------

// int main()
// {
// 	t_game game;

// 	read_map("maps/map.ber", &game.map);
// 	parse_map(game.map);
// 	mlx_init(game.mlx);

// 	init_image(&game, &game.player_img, "textures/cursor.xpm");
// 	init_image(&game, &game.colec_img, "textures/colec.xpm");
// 	init_image(&game, &game.wall_img, "textures/wall.xpm");
// 	init_image(&game, &game.exit_img, "textures/exit.xpm");

// 	mlx_new_window(game.mlx, game.width, game.height, "ola");

// }






// int	handle_input(int keycode, t_game *game)
// {
// 	int	new_x;
// 	int	new_y;
// 	int	c_count;

// 	new_x = game->player_x;
// 	new_y = game->player_y;
// 	if (keycode == 65307) // ESC
// 	{
// 		mlx_destroy_window(game->mlx, game->win);
// 		free_game(game);
// 	}
// 	else if (keycode == 119) // W
// 		new_y--;
// 	else if (keycode == 115) // S
// 		new_y++;
// 	else if (keycode == 97) // A
// 		new_x--;
// 	else if (keycode == 100) // D
// 		new_x++;
// 	if (game->map[new_y][new_x] != '1')
// 	{
// 		if (game->map[new_y][new_x] == 'E')
// 		{
// 			c_count = count_e_p_c(game, 'C');
// 			if (c_count == 0)
// 			{
// 				mlx_destroy_window(game->mlx, game->win);
// 				free_game(game);
// 			}
// 			else
// 				return (1);
// 		}
// 		if (game->map[game->player_y][game->player_x] == 'P')
// 			game->map[game->player_y][game->player_x] = '0';
// 		game->player_x = new_x;
// 		game->player_y = new_y;
// 		game->map[new_y][new_x] = 'P';
// 	}
// 	return (1);
// }