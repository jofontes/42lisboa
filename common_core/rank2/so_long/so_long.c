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

}				t_game;



void	my_mlx_pixel_put(t_game *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}




// Função para desenhar a textura em toda a janela
void put_texture(t_game *game)
{
	int x, y;
	int tex_x, tex_y;
	int color;

	// Replicar a textura pela janela
	for (y = 0; y < 480; y++) {
		for (x = 0; x < 640; x++) {
			// Calculando a posição na textura
			tex_x = x % game->texture_width;
			tex_y = y % game->texture_height;

			// Pega a cor da textura
			color = *(unsigned int *)(game->texture_img + (tex_y * game->texture_width + tex_x) * (game->bits_per_pixel / 8));

			// Coloca a cor no destino
			my_mlx_pixel_put(game, x, y, color);
		}
	}
}


int	render_next_frame(t_game *game)
{
	// Cria uma nova imagem a cada frame (opcional - pode ser otimizado)
	game->img = mlx_new_image(game->mlx, 640, 480);
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length, &game->endian);

	put_texture(game);

	// Coloca a imagem na janela
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);

	// Destrói a imagem depois de usar (opcional, só se estiver recriando toda vez)
	mlx_destroy_image(game->mlx, game->img);

	return (0);
}

int	main(void)
{
	t_game	game;
	
	// game.player_x = 320; // Centro da tela
	// game.player_y = 240;
	// game.radius = 20;


	game.mlx = mlx_init();

	game.texture_img = mlx_xpm_file_to_image(game.mlx, "texture.xpm", &game.texture_width, &game.texture_height);

	if (!game.texture_img)
	{
		printf("Erro ao carregar imagem do cursor!\n");
		exit(1);
	}
	

	game.win = mlx_new_window(game.mlx, 640, 480, "Hello world!");
	
	mlx_loop_hook(game.mlx, render_next_frame, &game);

	mlx_loop(game.mlx);
}







// int main(void)
// {
//     t_game game;
    
//     game.mlx = mlx_init();

//     // Testa o caminho do arquivo e a carga da imagem
//     printf("Tentando carregar a imagem 'texture.xpm'...\n");
//     game.texture_img = mlx_xpm_file_to_image(game.mlx, "texture.xpm", &game.texture_width, &game.texture_height);
    
//     if (!game.texture_img) {
//         printf("Erro ao carregar a imagem! Verifique o caminho de texture.xpm.\n");
//         exit(1);
//     } else {
//         printf("Imagem carregada com sucesso! Largura: %d, Altura: %d\n", game.texture_width, game.texture_height);
//     }

//     game.win = mlx_new_window(game.mlx, 640, 480, "Hello world!");

//     mlx_loop_hook(game.mlx, render_next_frame, &game);
//     mlx_loop(game.mlx);
// }
