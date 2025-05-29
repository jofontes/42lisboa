/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:04:58 by josaraiv          #+#    #+#             */
/*   Updated: 2025/05/29 13:20:43 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// int	handle_input(int keycode, t_game *game)
// {
// 	if (keycode == 65307) // ESC
// 	{
// 		mlx_destroy_window(game->mlx, game->win);
// 		exit(0);
// 	}
// 	else if (keycode == 119) // W
// 		game->player_y -= 60;
// 	else if (keycode == 115) // S
// 		game->player_y += 60;
// 	else if (keycode == 97)  // A
// 		game->player_x -= 60;
// 	else if (keycode == 100) // D
// 		game->player_x += 60;

// 	return (0);
// }

// void	init_image(t_game *game, t_image *img, const char *path)
// {
// 	img->img = mlx_xpm_file_to_image(game->mlx, path, &img->width, &img->height);
// }

// int count_map_lines(const char *path)
// {
// 	int lines;
// 	char *line;
// 	int fd;

// 	fd = open(path, O_RDONLY);
// 	if (fd < 0)
// 		return (-1);
	
// 	lines = 0;
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		free(line);
// 		lines++;	
// 		line = get_next_line(fd);
// 	}
// 	return (free(line), close(fd), lines);
// }

// int count_map_width(const char *path)
// {
// 	int width;
// 	char *line;
// 	int fd;

// 	fd = open(path, O_RDONLY);
// 	if (fd < 0)
// 		return (-1);
	
// 	width = 0;
// 	line = get_next_line(fd);
// 	if (line)
// 	{
// 		while (*line)
// 			width++;
// 	}
// 	return (free(line), close(fd), width);
// }

// void read_map(const char *path, t_game *game)
// {
// 	game->height = count_map_lines(path);
// 	game->map = malloc(sizeof(char*) * (game->height + 1));
// 	game->width = count_map_width(path);
	
// 	int i;
// 	i = 0;

// 	int fd;
// 	fd = open(path, O_RDONLY);
// 	if (fd < 0)
// 		return (-1);
		
// 	while (i < game->height)
// 	{
// 		game->map[i] = get_next_line(fd);
// 		i++;	
// 	}
// 	game->map[i] = NULL;
// 	close(fd);
// }








int main(void)
{
	t_game game;
	

	if(read_map("maps/map.ber", &game))
	{		
		printf("ok");
		free(game.map);
	}
	else
	{
		printf("erro");
		
	}
	
	

	return 0;
}



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

