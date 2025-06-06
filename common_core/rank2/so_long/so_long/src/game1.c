/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:04:58 by josaraiv          #+#    #+#             */
/*   Updated: 2025/06/02 17:18:51 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	putnbr(int n)
{
	int		h[10];
	int		i;
	int		temp;
	char	c;

	i = 0;
	if (n == 0)
		write(1, "0", 1);
	if (n < 0)
		write(1, "-", 1);
	while (n != 0)
	{
		temp = n % 10;
		if (temp < 0)
			temp = temp * (-1);
		h[i] = temp;
		i++;
		n = n / 10;
	}
	while (--i > -1)
	{
		c = h[i] + '0';
		write(1, &c, 1);
	}
}

void	update_position(int keycode, int *new_x, int *new_y)
{
	if (keycode == 119)
		(*new_y)--;
	else if (keycode == 115)
		(*new_y)++;
	else if (keycode == 97)
		(*new_x)--;
	else if (keycode == 100)
		(*new_x)++;
}

int	process_move(t_game *game, int new_x, int new_y)
{
	int	c_count;

	if (game->map[new_y][new_x] == 'E')
	{
		c_count = count_e_p_c(game, 'C');
		if (c_count != 0)
			return (1);
		mlx_loop_end(game->mlx);
	}
	if (game->map[game->player_y][game->player_x] == 'P')
		game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_y][new_x] = 'P';
	game->move_count++;
	write(1, "Moves: ", 7);
	putnbr(game->move_count);
	write(1, "\n", 1);
	return (1);
}

int	handle_input(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == 65307)
	{
		mlx_loop_end(game->mlx);
		return (0);
	}
	if (keycode == 119 || keycode == 115 || keycode == 97 || keycode == 100)
		update_position(keycode, &new_x, &new_y);
	else
		return (1);
	if (game->map[new_y][new_x] != '1')
		return (process_move(game, new_x, new_y));
	return (1);
}

int	handle_window_close(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	mlx_loop_end(game->mlx);
	return (0);
}
