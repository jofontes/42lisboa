/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:47:59 by josaraiv          #+#    #+#             */
/*   Updated: 2025/05/30 18:48:06 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef TILE_SIZE
#  define TILE_SIZE 60
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_image
{
	void	*img;
	int		width;
	int		height;
}			t_image;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_image	player_img;
	t_image	wall_img;
	t_image	colec_img;
	t_image	exit_img;
	t_image	floor_img;

	int		player_x;
	int		player_y;

	int		height;
	int		width;
	char	**map;

}			t_game;

// gnl.c
char		*get_next_line(int fd);

// map1.c
int			read_map(char *path, t_game *game);

// map2.c
int			count_map_lines(char *path);
int			count_map_width(char *path);
int			is_rectangle(char *path);

// map3.c
int			surrounded_by_walls(t_game *game);
int			count_e_p_c(t_game *game, char letter);

// map4.c
int			is_valid_letter(char c);
int			other_letters(t_game *game);
void		free_map(t_game *game);
void		create_map(char *path, t_game *game);
void		free_copy_map(char **map_copy, t_game *game);

// map5.c
char		**copy_map(t_game game);
void		floodfill(char **copy_map, int x, int y);
int			winable(char **copy_map, t_game *game);

// so_long.c
int			handle_input(int keycode, t_game *game);
void		init_image(t_game *game, t_image *img, char *path);
int			loop(t_game *game);
void		free_game(t_game *game);

#endif