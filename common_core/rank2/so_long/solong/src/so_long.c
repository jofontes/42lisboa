
#include "../inc/so_long.h"






int	handle_input(int keycode, t_game *game)
{
	if (keycode == 65307) // ESC
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	else if (keycode == 119) // W
		game->cursor_y -= 10;
	else if (keycode == 115) // S
		game->cursor_y += 10;
	else if (keycode == 97)  // A
		game->cursor_x -= 10;
	else if (keycode == 100) // D
		game->cursor_x += 10;

	return (0);
}



void	my_mlx_pixel_put(t_game *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// int	render_next_frame(t_game *game)
// {
// 	// Cria uma nova imagem a cada frame (opcional - pode ser otimizado)
// 	mlx_clear_window(game->mlx, game->win);
// 	int x = 0, y = 0;
// 	while (y < 480)
// 	{
// 		while (x < 640)
// 		{
// 			mlx_put_image_to_window(game->mlx, game->win, game->texture_img, x, y);
// 			x += game->texture_width;
			
// 		}
// 		y += game->texture_height;
// 	}

// 	mlx_put_image_to_window(game->mlx, game->win, game->cursor_img, game->cursor_x, game->cursor_y);
	
	
// 	return (0);
// }

int render_next_frame(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);

	for (int y = 0; y < game->map_height; y++)
	{
		for (int x = 0; x < game->map_width; x++)
		{
			char tile = game->map[y][x];
			void *img_to_draw = NULL;

			if (tile == '1')
				img_to_draw = game->wall_img;
			else if (tile == '0')
				img_to_draw = game->floor_img;
			else if (tile == 'P')
				img_to_draw = game->player_img;
			else if (tile == 'E')
				img_to_draw = game->exit_img;
			else if (tile == 'C')
				img_to_draw = game->collectible_img;

			if (img_to_draw)
				mlx_put_image_to_window(game->mlx, game->win, img_to_draw, x * 32, y * 32);
		}
	}

	return (0);
}





int	main(void)
{
	t_game	game;
	
	

	game.mlx = mlx_init();
	game.texture_img = mlx_xpm_file_to_image(game.mlx, "textures/texture_red.xpm", &game.texture_width, &game.texture_height);
	game.cursor_img = mlx_xpm_file_to_image(game.mlx, "textures/cursor.xpm", &game.cursor_x, &game.cursor_y);

	if (!game.texture_img)
	{
		printf("Erro ao carregar imagem do cursor!\n");
		exit(1);
	}
	

	game.map = read_map("maps/map.ber", &game.map_height);
	game.map_width = ft_strlen(game.map[0]); // ou sua própria função strlen

	int w, h;
	game.wall_img = mlx_xpm_file_to_image(game.mlx, "textures/texture_blue.xpm", &w, &h);
	game.floor_img = mlx_xpm_file_to_image(game.mlx, "textures/texture_red", &w, &h);
	game.player_img = mlx_xpm_file_to_image(game.mlx, "textures/cursor.xpm", &w, &h);
	game.exit_img = mlx_xpm_file_to_image(game.mlx, "textures/exit.xpm", &w, &h);
	game.collectible_img = mlx_xpm_file_to_image(game.mlx, "textures/coin.xpm", &w, &h);

	

	game.cursor_x = 320;
	game.cursor_y = 240;
	game.win = mlx_new_window(game.mlx, 640, 480, "Hello world!");
	
	mlx_loop_hook(game.mlx, render_next_frame, &game);
	mlx_hook(game.win, 2, 1L<<0, handle_input, &game);

	mlx_loop(game.mlx);
}




