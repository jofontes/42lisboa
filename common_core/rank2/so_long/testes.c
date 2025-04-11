// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	mlx_loop(mlx);
// }

//-------------------------------------------------------------------


// // abre uma window com pixels vermelhos, para fechar tem de ser no terminal ctr+c
// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;
	

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");

// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		
// 	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	
// 	//quadrado
// 	int i = 0;
// 	int j = 0;
// 	while (i < 100)
// 	{
// 		j = 0;
// 		while (j < 100)
// 		{
// 			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
// 			j++;
// 		}
		
// 		i++;
		
// 	}

// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);


// 	mlx_loop(mlx);
// }


//-------------------------------------------------------------------



// //abre uma windoh e fecha clicando em qualquer tecla
// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// int	close(t_vars *vars)
// {
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
// 	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
// 	mlx_loop(vars.mlx);
// }


//-------------------------------------------------------------------




// //abre uma windoh e fecha clicando no esc
// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// int	close(int keycode, t_vars *vars)
// {
// 	if (keycode == 65307)
// 	{
// 		mlx_destroy_window(vars->mlx, vars->win);
// 	}
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
// 	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
// 	mlx_loop(vars.mlx);
// }





// #include <stdio.h>

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// // Função chamada quando uma tecla é pressionada
// int	close(int keycode, t_vars *vars)
// {
// 	if (keycode == 65307)  // Se a tecla for ESC
// 	{
// 		mlx_destroy_window(vars->mlx, vars->win);
// 	}
// 	return (0);
// }

// // Função chamada quando a janela é redimensionada
// int	resize(int width, int height)
// {
// 	// Imprimir a nova largura e altura da janela
// 	printf("Window resized to: %d x %d\n", width, height);
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	
// 	// Associar o evento de tecla (fechar com ESC)
// 	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	
// 	// Associar o evento de redimensionamento da janela
// 	mlx_hook(vars.win, 17, 1L<<0, resize, &vars);
	
// 	mlx_loop(vars.mlx);
// }





//-------------------------------------------------------------------



// // //abrir windoh e print no terminal o keycode quando clicamos numa tecla
// #include <stdio.h>

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// int	key_hook(int keycode)
// {
// 	if (keycode)
// 		printf("Hello from %d!\n", keycode);
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
// 	mlx_key_hook(vars.win, key_hook, &vars);
// 	mlx_loop(vars.mlx);
// }


//-------------------------------------------------------------------


//abre a windoh e imprime o keycode do teclado e rato ao ser acionado
#include <stdio.h>
typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;
int	key_hook(int keycode)
{
	if (keycode)
		printf("Hello from key_hook! || keycode:%d\n", keycode);
	return (0);
}
int	mouse_hook(int keycode)
{
	if (keycode)
		printf("Hello from mouse_hook! || keycode:%d\n", keycode);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);

	mlx_loop(vars.mlx);
}










//-----------------------------------------------------------------------------------------------

//the mouse if moved, it will print the current position of that mouse in the terminal.
typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;
// Função que captura o movimento do mouse
int	mouse_move(int x, int y)
{
	printf("Posição do mouse: x = %d, y = %d\n", x, y);
	return (0);
}
int	key_hook(int keycode)
{
	if (keycode)
		printf("Hello from key_hook! || keycode:%d\n", keycode);
	return (0);
}

int	mouse_hook(int keycode)
{
	if (keycode)
		printf("Hello from mouse_hook! || keycode:%d\n", keycode);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	
	// Configura o hook para o movimento do mouse
	mlx_hook(vars.win, 6, 1L << 6, mouse_move, &vars);
	
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);

	mlx_loop(vars.mlx);
}




//----------------------------------------------------------------------------------------------------------


//Render a moving rainbow that shifts through all colors (screen turns red, becomes green and then becomes blue, then starts all over again).



// #include "mlx/mlx.h"

// #include <stdio.h>
// #include <stdlib.h>

// typedef struct	s_game {
// 	void	*mlx;
// 	void	*win;

// 	//imagem
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// 	//cores
// 	int r;
// 	int g;
// 	int b;
// 	int phase; // 0: red -> green, 1: green -> blue, 2: blue -> red

// }				t_game;


// int	close(int keycode, t_game *game)
// {
// 	if (keycode == 65307)
// 	{
// 		mlx_destroy_window(game->mlx, game->win);
// 		exit(0);
// 	}
// 	return (0);
// }



// void	my_mlx_pixel_put(t_game *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// void put_square(t_game *game)
// {
// 	int i = 0;
// 	int j = 0;
// 	int comprimento = 640;
// 	int largura = 480;
// 	int color = (game->r << 16) | (game->g << 8) | game->b;

// 	while (i < comprimento)
// 	{
// 		j = 0;
// 		while (j < largura)
// 		{
// 			my_mlx_pixel_put(game, i, j, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }


// void	update_color(t_game *game)
// {
// 	if (game->phase == 0)
// 	{
// 		if (game->r > 0)
// 			game->r--;
// 		if (game->g < 255)
// 			game->g++;
// 		if (game->r == 0 && game->g == 255)
// 			game->phase = 1;
// 	}
// 	else if (game->phase == 1)
// 	{
// 		if (game->g > 0)
// 			game->g--;
// 		if (game->b < 255)
// 			game->b++;
// 		if (game->g == 0 && game->b == 255)
// 			game->phase = 2;
// 	}
// 	else if (game->phase == 2)
// 	{
// 		if (game->b > 0)
// 			game->b--;
// 		if (game->r < 255)
// 			game->r++;
// 		if (game->b == 0 && game->r == 255)
// 			game->phase = 0;
// 	}
// }



// int	render_next_frame(t_game *game)
// {
// 	// Cria uma nova imagem a cada frame (opcional - pode ser otimizado)
// 	game->img = mlx_new_image(game->mlx, 640, 480);
// 	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length, &game->endian);

// 	update_color(game); // <- Aqui está a mágica!
// 	// Desenha o quadrado
// 	put_square(game);

// 	// Coloca a imagem na janela
// 	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);

// 	// Destrói a imagem depois de usar (opcional, só se estiver recriando toda vez)
// 	mlx_destroy_image(game->mlx, game->img);

// 	return (0);
// }

// int	main(void)
// {
// 	t_game	game;
	
// 	game.r = 255;
// 	game.g = 0;
// 	game.b = 0;
// 	game.phase = 0;


// 	game.mlx = mlx_init();
// 	game.win = mlx_new_window(game.mlx, 640, 480, "Hello world!");
	
// 	mlx_loop_hook(game.mlx, render_next_frame, &game);

// 	mlx_hook(game.win, 2, 1L<<0, close, &game);
// 	mlx_loop(game.mlx);
// }



//----------------------------------------------------------------------------------------------------------



//Create a circle that you can move accross your screen using your WASD keys.


// #include "mlx/mlx.h"
// #include <stdio.h>
// #include <stdlib.h>


// typedef struct	s_game {
// 	void	*mlx;
// 	void	*win;

// 	//imagem
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;

// 	int player_x;
// 	int player_y;
// 	int radius;


// }				t_game;

// void	my_mlx_pixel_put(t_game *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// void put_circle(t_game *game)
// {
// 	int x, y;
// 	int cx = game->player_x;
// 	int cy = game->player_y;
// 	int r = game->radius;

// 	for (y = cy - r; y <= cy + r; y++)
// 	{
// 		for (x = cx - r; x <= cx + r; x++)
// 		{
// 			if ((x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r)
// 			{
// 				if (x >= 0 && x < 640 && y >= 0 && y < 480)
// 					my_mlx_pixel_put(game, x, y, 0x0000FF00); // Verde
// 			}
// 		}
// 	}
// }

// int	handle_input(int keycode, t_game *game)
// {
// 	if (keycode == 65307) // ESC
// 	{
// 		mlx_destroy_window(game->mlx, game->win);
// 		exit(0);
// 	}
// 	else if (keycode == 119) // W
// 		game->player_y -= 10;
// 	else if (keycode == 115) // S
// 		game->player_y += 10;
// 	else if (keycode == 97)  // A
// 		game->player_x -= 10;
// 	else if (keycode == 100) // D
// 		game->player_x += 10;

// 	return (0);
// }

// int	render_next_frame(t_game *game)
// {
// 	// Cria uma nova imagem a cada frame (opcional - pode ser otimizado)
// 	game->img = mlx_new_image(game->mlx, 640, 480);
// 	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length, &game->endian);

	
// 	// Desenha o quadrado
// 	put_circle(game);

// 	// Coloca a imagem na janela
// 	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);

// 	// Destrói a imagem depois de usar (opcional, só se estiver recriando toda vez)
// 	mlx_destroy_image(game->mlx, game->img);

// 	return (0);
// }

// int	main(void)
// {
// 	t_game	game;
	
// 	game.player_x = 320; // Centro da tela
// 	game.player_y = 240;
// 	game.radius = 20;



// 	game.mlx = mlx_init();
// 	game.win = mlx_new_window(game.mlx, 640, 480, "Hello world!");
	
// 	mlx_loop_hook(game.mlx, render_next_frame, &game);

// 	mlx_hook(game.win, 2, 1L<<0, handle_input, &game);
// 	mlx_loop(game.mlx);
// }




//--------------------------------------------------------------------------------------------------------------------------
//Import a cursor of your choice and allow it to roam within the window freely.

// #include "mlx/mlx.h"

// #include <stdio.h>
// #include <stdlib.h>




// typedef struct	s_game {
// 	void	*mlx;
// 	void	*win;

// 	//imagem my_mlx_pixel_put
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;


// 	//para xpm img
// 	void	*cursor_img;
// 	int		cursor_width;
// 	int		cursor_height;
// 	int		cursor_x;
// 	int		cursor_y;


// }				t_game;



// void	my_mlx_pixel_put(t_game *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }


// int	handle_input(int keycode, t_game *game)
// {
// 	if (keycode == 65307) // ESC
// 	{
// 		mlx_destroy_window(game->mlx, game->win);
// 		exit(0);
// 	}
// 	else if (keycode == 119) // W
// 		game->cursor_y -= 10;
// 	else if (keycode == 115) // S
// 		game->cursor_y += 10;
// 	else if (keycode == 97)  // A
// 		game->cursor_x -= 10;
// 	else if (keycode == 100) // D
// 		game->cursor_x += 10;

// 	return (0);
// }



// int	render_next_frame(t_game *game)
// {
// 	// Cria uma nova imagem a cada frame (opcional - pode ser otimizado)
// 	game->img = mlx_new_image(game->mlx, 640, 480);
// 	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length, &game->endian);

	
// 	// // Desenha o quadrado
// 	// put_circle(game);

// 	for (int y = 0; y < 480; y++)
// 		for (int x = 0; x < 640; x++)
// 			my_mlx_pixel_put(game, x, y, 0x00FFFFFF);


	
// 	// Coloca a imagem na janela
// 	// mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
// 	mlx_put_image_to_window(game->mlx, game->win, game->cursor_img, game->cursor_x, game->cursor_y);

// 	// Destrói a imagem depois de usar (opcional, só se estiver recriando toda vez)
// 	mlx_destroy_image(game->mlx, game->img);

// 	return (0);
// }

// int	main(void)
// {
// 	t_game	game;
	
// 	// game.player_x = 320; // Centro da tela
// 	// game.player_y = 240;
// 	// game.radius = 20;


// 	game.mlx = mlx_init();

// 	game.cursor_img = mlx_xpm_file_to_image(game.mlx, "cursor.xpm", &game.cursor_width, &game.cursor_height);
// 	if (!game.cursor_img)
// 	{
// 		printf("Erro ao carregar imagem do cursor!\n");
// 		exit(1);
// 	}
	
// 	game.cursor_x = 320;
// 	game.cursor_y = 240;
	
	
// 	game.win = mlx_new_window(game.mlx, 640, 480, "Hello world!");
	
// 	mlx_loop_hook(game.mlx, render_next_frame, &game);

// 	mlx_hook(game.win, 2, 1L<<0, handle_input, &game);
// 	mlx_loop(game.mlx);
// }




//--------------------------------------------------------------------------------------------------------------------------


//Import a texture and replicate it accross your entire window.   nao esta funcionar muito bem

// #include "mlx/mlx.h"

// #include <stdio.h>
// #include <stdlib.h>




// typedef struct	s_game {
// 	void	*mlx;
// 	void	*win;

// 	//imagem my_mlx_pixel_put
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;


// 	//para xpm img
// 	void	*texture_img;
// 	int 	texture_width;
// 	int		texture_height;

// }				t_game;



// void	my_mlx_pixel_put(t_game *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }




// // Função para desenhar a textura em toda a janela
// void put_texture(t_game *game)
// {
// 	int x, y;
// 	int tex_x, tex_y;
// 	int color;

// 	// Replicar a textura pela janela
// 	for (y = 0; y < 480; y++) {
// 		for (x = 0; x < 640; x++) {
// 			// Calculando a posição na textura
// 			tex_x = x % game->texture_width;
// 			tex_y = y % game->texture_height;

// 			// Pega a cor da textura
// 			color = *(unsigned int *)(game->texture_img + (tex_y * game->texture_width + tex_x) * (game->bits_per_pixel / 8));

// 			// Coloca a cor no destino
// 			my_mlx_pixel_put(game, x, y, color);
// 		}
// 	}
// }


// int	render_next_frame(t_game *game)
// {
// 	// Cria uma nova imagem a cada frame (opcional - pode ser otimizado)
// 	game->img = mlx_new_image(game->mlx, 640, 480);
// 	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_length, &game->endian);

// 	put_texture(game);

// 	// Coloca a imagem na janela
// 	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);

// 	// Destrói a imagem depois de usar (opcional, só se estiver recriando toda vez)
// 	mlx_destroy_image(game->mlx, game->img);

// 	return (0);
// }

// int	main(void)
// {
// 	t_game	game;
	



// 	game.mlx = mlx_init();

// 	game.texture_img = mlx_xpm_file_to_image(game.mlx, "cursor.xpm", &game.texture_width, &game.texture_height);

// 	if (!game.texture_img)
// 	{
// 		printf("Erro ao carregar imagem do cursor!\n");
// 		exit(1);
// 	}
	

// 	game.win = mlx_new_window(game.mlx, 640, 480, "Hello world!");
	
// 	mlx_loop_hook(game.mlx, render_next_frame, &game);

// 	mlx_loop(game.mlx);
// }




//--------------------------------------------------------------------------------------------------------------------------


//Import a texture and replicate it accross your entire window.


// #include "mlx/mlx.h"

// #include <stdio.h>
// #include <stdlib.h>


// typedef struct	s_game {
// 	void	*mlx;
// 	void	*win;

// 	//imagem my_mlx_pixel_put
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;


// 	//para xpm img
// 	void	*texture_img;
// 	int 	texture_width;
// 	int		texture_height;
// 	//cursor
// 	void	*cursor_img;
// 	int 	cursor_width;
// 	int		cursor_height;
// }				t_game;



// void	my_mlx_pixel_put(t_game *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

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

// 	mlx_put_image_to_window(game->mlx, game->win, game->cursor_img, game->cursor_width, game->cursor_height);

// 	return (0);
// }

// int	main(void)
// {
// 	t_game	game;
	
// 	game.cursor_width = 40;
// 	game.cursor_height = 30;

// 	game.mlx = mlx_init();
// 	game.texture_img = mlx_xpm_file_to_image(game.mlx, "texture_red.xpm", &game.texture_width, &game.texture_height);
// 	game.cursor_img = mlx_xpm_file_to_image(game.mlx, "cursor.xpm", &game.cursor_width, &game.cursor_height);

// 	if (!game.texture_img)
// 	{
// 		printf("Erro ao carregar imagem do cursor!\n");
// 		exit(1);
// 	}
	

// 	game.win = mlx_new_window(game.mlx, 640, 480, "Hello world!");
	
// 	mlx_loop_hook(game.mlx, render_next_frame, &game);

// 	mlx_loop(game.mlx);
// }



//------------------
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




