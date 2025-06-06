/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map6.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:04:58 by josaraiv          #+#    #+#             */
/*   Updated: 2025/06/02 17:19:14 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	floodfill2(char **copy_map, int x, int y)
{
	if (copy_map[y][x] == '1' || copy_map[y][x] == 'F')
		return ;
	copy_map[y][x] = 'F';
	floodfill2(copy_map, x + 1, y);
	floodfill2(copy_map, x - 1, y);
	floodfill2(copy_map, x, y + 1);
	floodfill2(copy_map, x, y - 1);
}

int	check_e(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < game->height)
	{
		i = 0;
		while (i < game->width)
		{
			if (map[j][i] == 'E')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
