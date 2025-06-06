/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:04:58 by josaraiv          #+#    #+#             */
/*   Updated: 2025/06/02 17:19:07 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	surrounded_by_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->width)
	{
		if (game->map[game->height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	count_e_p_c(t_game *game, char letter)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	temp = 0;
	while (j < game->height)
	{
		i = 0;
		while (i < game->width)
		{
			if (game->map[j][i] == letter && letter != 'P')
				temp++;
			else if (game->map[j][i] == letter && letter == 'P')
			{
				game->player_y = j;
				game->player_x = i;
				temp++;
			}
			i++;
		}
		j++;
	}
	return (temp);
}
