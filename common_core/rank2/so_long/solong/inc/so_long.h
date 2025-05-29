#ifndef SO_LONG_H
# define SO_LONG_H


#include "../minilibx-linux/mlx.h"

#include <stdio.h>
#include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct	s_image
{
	void	*img;
	int		width;
	int		height;
}	t_image;

typedef struct	s_game {
	void	*mlx;
	void	*win;
	t_image	player_img;
	t_image	wall_img;
	t_image	colec_img;
	t_image	exit_img;
	int		player_x;
	int		player_y;
	int 	height;
	int		width;
	char 	**map;
}	t_game;


char	*get_next_line(int fd);

//map
int count_map_lines(const char *path);
int count_map_width(const char *path);
int is_retangulo(const char *path);
int read_map(const char *path, t_game *game);
int surrounded_by_walls(t_game *game);
int count_E_P_C(t_game *game, char letter);
int other_letters(t_game *game);

#endif