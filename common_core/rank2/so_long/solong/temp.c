// int	read_map(char *path, t_game *game)
// {
// 	char	**map_copy;

// 	if (!is_retangulo(path))
// 	{
// 		printf("Erro: mapa não é retangular\n");
// 		return (0);
// 	}

// 	game->height = count_map_lines(path);
// 	game->map = malloc(sizeof(char *) * (game->height + 1));
// 	game->width = count_map_width(path);
// 	create_map(path, game);

// 	if (!surrounded_by_walls(game))
// 	{
// 		printf("Erro: mapa não está cercado por paredes\n");
// 		free_map(game);
// 		return (0);
// 	}

// 	if (count_e_p_c(game, 'E') != 1)
// 	{
// 		printf("Erro: mapa precisa de 1 'E'\n");
// 		free_map(game);
// 		return (0);
// 	}

// 	if (count_e_p_c(game, 'P') != 1)
// 	{
// 		printf("Erro: mapa precisa de 1 'P'\n");
// 		free_map(game);
// 		return (0);
// 	}

// 	if (count_e_p_c(game, 'C') < 1)
// 	{
// 		printf("Erro: mapa precisa de pelo menos 1 'C'\n");
// 		free_map(game);
// 		return (0);
// 	}

// 	if (!other_letters(game))
// 	{
// 		printf("Erro: mapa tem letras inválidas\n");
// 		free_map(game);
// 		return (0);
// 	}

// 	map_copy = copy_map(*game);
// 	floodfill(map_copy, game->player_x, game->player_y);

// 	if (!winable(map_copy, game))
// 	{
// 		printf("Erro: mapa não é completável (floodfill falhou)\n");
// 		free_map(game);
// 		free_copy_map(map_copy, game);
// 		return (0);
// 	}

// 	free_copy_map(map_copy, game);
// 	return (1);
// }





// int	is_retangulo(char *path)
// {
// 	int		fd;
// 	char	*line;
// 	int		expected_width;
// 	int		current_width;

// 	fd = open(path, O_RDONLY);
// 	if (fd < 0)
// 		return (0);
// 	line = get_next_line(fd);
// 	if (!line)
// 		return (close(fd), 0);
// 	expected_width = 0;
// 	while (line[expected_width] && line[expected_width] != '\n')
// 		expected_width++;
// 	free(line);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		current_width = 0;
// 		while (line[current_width] && line[current_width] != '\n')
// 			current_width++;
// 		if (current_width != expected_width)
// 			return (free(line), close(fd), 0);
// 		free(line);
// 	}
// 	close(fd);
// 	return (1);
// }





//penso que seja lixo
// int count_map_lines(char *path)
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

// int count_map_width(char *path)
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
// void read_map(char *path, t_game *game)
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













//main de teste durante o map parsing
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



















// int	handle_input(int keycode, t_game *game)
// {
// 	int new_x;
// 	int new_y;

// 	int c_count;

// 	new_x = game->player_x;
// 	new_y = game->player_y;
// 	if (keycode == 65307) // ESC
// 	{
// 		mlx_destroy_window(game->mlx, game->win);
// 		exit(0);
// 	}
// 	else if (keycode == 119) // W
// 		new_y--;
// 	else if (keycode == 115) // S
// 		new_y++;
// 	else if (keycode == 97)  // A
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
// 				exit(0);
// 			}
// 		}

// 		if (game->map[game->player_y][game->player_x] == 'P')
// 			game->map[game->player_y][game->player_x] = '0';
// 		game->player_x = new_x;
// 		game->player_y = new_y;
// 		game->map[new_y][new_x] = 'P';
// 	}
	
	
	
	
// 	return (1);
// }








// int	handle_input(int keycode, t_game *game)
// {
// 	int new_x;
// 	int new_y;
	
// 	int last_pos_e;
	
// 	int c_count;

// 	// last_pos_e = 0;
// 	new_x = game->player_x;
// 	new_y = game->player_y;
// 	if (keycode == 65307) // ESC
// 	{
// 		mlx_destroy_window(game->mlx, game->win);
// 		exit(0);
// 	}
// 	else if (keycode == 119) // W
// 		new_y--;
// 	else if (keycode == 115) // S
// 		new_y++;
// 	else if (keycode == 97)  // A
// 		new_x--;
// 	else if (keycode == 100) // D
// 		new_x++;
// 	if (game->map[new_y][new_x] != '1')
// 	{
// 		if (game->map[new_y][new_x] == 'E')
// 		{
// 			last_pos_e = 1;
// 			c_count = count_e_p_c(game, 'C');
// 			if (c_count == 0)
// 			{
// 				mlx_destroy_window(game->mlx, game->win);
// 				exit(0);
// 			}
// 		}
// 		if (game->map[game->player_y][game->player_x] == 'P')
// 		{
// 			if (last_pos_e)
// 			{
// 				last_pos_e = 0;
// 				game->map[game->player_y][game->player_x] = 'E';
// 			}
// 			else
// 				game->map[game->player_y][game->player_x] = '0';
// 		}
// 		game->player_x = new_x;
// 		game->player_y = new_y;
// 		game->map[new_y][new_x] = 'P';
// 	}
	
	
	
	
// 	return (1);
// }
















// int	handle_input(int keycode, t_game *game)
// {
// 	int new_x;
// 	int new_y;
	
// 	static int last_pos_e;
	
// 	int c_count;

// 	//last_pos_e = 0;
// 	new_x = game->player_x;
// 	new_y = game->player_y;
// 	if (keycode == 65307) // ESC
// 	{
// 		mlx_destroy_window(game->mlx, game->win);
// 		exit(0);
// 	}
// 	else if (keycode == 119) // W
// 		new_y--;
// 	else if (keycode == 115) // S
// 		new_y++;
// 	else if (keycode == 97)  // A
// 		new_x--;
// 	else if (keycode == 100) // D
// 		new_x++;
// 	if (game->map[new_y][new_x] != '1')
// 	{
// 		if (game->map[new_y][new_x] == 'E')
// 		{
// 			last_pos_e = 1;
// 			c_count = count_e_p_c(game, 'C');
// 			if (c_count == 0)
// 			{
// 				mlx_destroy_window(game->mlx, game->win);
// 				exit(0);
// 			}
// 		}
// 		if (game->map[game->player_y][game->player_x] == 'P')
// 		{
// 			if (last_pos_e == 1)
// 			{
// 				game->map[game->player_y][game->player_x] = 'E';
// 				last_pos_e = 0;
// 			}
// 			else
// 				game->map[game->player_y][game->player_x] = '0';
// 		}
// 		game->player_x = new_x;
// 		game->player_y = new_y;
// 		game->map[new_y][new_x] = 'P';
// 	}
	






// int main(int ac, char *av)
// {
// 	t_game game;

// 	if(!read_map("maps/map.ber", &game))
// 	{
// 		printf("erro");
// 		return (1);
// 	}


// 	game.mlx = mlx_init();
// 	game.win = mlx_new_window(game.mlx, game.width * TILE_SIZE, game.height * TILE_SIZE, "so_long");
	
// 	init_image(&game, &game.player_img, "textures/cursor.xpm");
// 	init_image(&game, &game.colec_img, "textures/colec.xpm");
// 	init_image(&game, &game.wall_img, "textures/wall.xpm");
// 	init_image(&game, &game.exit_img, "textures/exit.xpm");	
// 	init_image(&game, &game.floor_img, "textures/floor.xpm");
	


	
// 	mlx_loop_hook(game.mlx, (void *)loop, &game);
// 	mlx_key_hook(game.win, handle_input, &game);

// 	mlx_loop(game.mlx);



// 	free_map(&game);

// }





















// void	floodfill(char **copy_map, int x, int y)
// {
// 	if (copy_map[y][x] == '1' || copy_map[y][x] == 'F')
// 		return ;
// 	copy_map[y][x] = 'F';
// 	floodfill(copy_map, x + 1, y);
// 	floodfill(copy_map, x - 1, y);
// 	floodfill(copy_map, x, y + 1);
// 	floodfill(copy_map, x, y - 1);
// }

// int	winable(char **copy_map, t_game *game)
// {
// 	int	x;
// 	int	y;
// 	int	temp;

// 	y = 0;
// 	temp = 0;
// 	while (y < game->height)
// 	{
// 		x = 0;
// 		while (x < game->width)
// 		{
// 			if (!(copy_map[y][x] == '1' || copy_map[y][x] == 'F'))
// 				return (0);
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (1);
// }