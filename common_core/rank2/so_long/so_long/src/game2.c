/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:04:58 by josaraiv          #+#    #+#             */
/*   Updated: 2025/06/06 11:25:10 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	init_image(t_game *game, t_image *img, char *path)
{
	img->img = mlx_xpm_file_to_image(game->mlx, (char *)path, &img->width,
			&img->height);
	if (!img->img)
		return (0);
	return (1);
}

void	init_all_images(t_game *game)
{
	if (!init_image(game, &game->player_img, "textures/cursor.xpm")
		|| !init_image(game, &game->colec_img, "textures/colec.xpm")
		|| !init_image(game, &game->wall_img, "textures/wall.xpm")
		|| !init_image(game, &game->exit_img, "textures/exit.xpm")
		|| !init_image(game, &game->floor_img, "textures/floor.xpm"))
	{
		write(2, "Error - invalid texture\n", 24);
		close_game(game);
	}
}

void	free_game(t_game *game)
{
	if (game->player_img.img)
		mlx_destroy_image(game->mlx, game->player_img.img);
	if (game->wall_img.img)
		mlx_destroy_image(game->mlx, game->wall_img.img);
	if (game->floor_img.img)
		mlx_destroy_image(game->mlx, game->floor_img.img);
	if (game->colec_img.img)
		mlx_destroy_image(game->mlx, game->colec_img.img);
	if (game->exit_img.img)
		mlx_destroy_image(game->mlx, game->exit_img.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
}

void	close_game(t_game *game)
{
	free_map(game);
	free_game(game);
	exit(0);
}
