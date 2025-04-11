#include "mlx/mlx.h"

#include <stdio.h>
#include <stdlib.h>







typedef struct	s_game {
	void	*mlx;
	void	*win;

	//imagem my_mlx_pixel_put
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;


	//para xpm img
	void	*texture_img;
	int 	texture_width;
	int		texture_height;
	void	*cursor_img;
	int 	cursor_width;
	int		cursor_height;
	int		cursor_x;
	int		cursor_y;
}				t_game;


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

int	render_next_frame(t_game *game)
{
	// Cria uma nova imagem a cada frame (opcional - pode ser otimizado)
	mlx_clear_window(game->mlx, game->win);
	int x = 0, y = 0;
	while (y < 480)
	{
		while (x < 640)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->texture_img, x, y);
			x += game->texture_width;
			
		}
		y += game->texture_height;
	}

	mlx_put_image_to_window(game->mlx, game->win, game->cursor_img, game->cursor_x, game->cursor_y);
	
	
	return (0);
}

int	main(void)
{
	t_game	game;
	
	game.cursor_width = 20;
	game.cursor_height = 30;

	game.mlx = mlx_init();
	game.texture_img = mlx_xpm_file_to_image(game.mlx, "textures/texture_red.xpm", &game.texture_width, &game.texture_height);
	game.cursor_img = mlx_xpm_file_to_image(game.mlx, "textures/cursor.xpm", &game.cursor_width, &game.cursor_height);

	if (!game.texture_img)
	{
		printf("Erro ao carregar imagem do cursor!\n");
		exit(1);
	}
	
	game.cursor_x = 320;
	game.cursor_y = 240;
	game.win = mlx_new_window(game.mlx, 640, 480, "Hello world!");
	
	mlx_loop_hook(game.mlx, render_next_frame, &game);
	mlx_hook(game.win, 2, 1L<<0, handle_input, &game);

	mlx_loop(game.mlx);
}




