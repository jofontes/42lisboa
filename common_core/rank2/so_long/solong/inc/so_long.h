#ifndef SO_LONG_H
# define SO_LONG_H


#include "../minilibx-linux/mlx.h"

#include <stdio.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif


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
	// int 	cursor_width;
	// int		cursor_height;
	int		cursor_x;
	int		cursor_y;


	//mapa
	char **map;
	int map_width;
	int map_height;



	//Carregar texturas para cada tipo
	void *wall_img;
	void *floor_img;
	void *player_img;
	void *exit_img;
	void *collectible_img;



}				t_game;




int	handle_input(int keycode, t_game *game);
void	my_mlx_pixel_put(t_game *data, int x, int y, int color);
int	render_next_frame(t_game *game);
int	main(void);


char	*get_next_line(int fd);
int	count_lines(char *filename);
char	**read_map(char *filename, int *map_height);
char	*get_next_line(int fd);
int	ft_strlen(char *str);
char	*ft_strjoin(char *next_line, char *buffer);


#endif