/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:04:58 by josaraiv          #+#    #+#             */
/*   Updated: 2025/05/30 18:46:18 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strdup(char *s)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen((char *)s);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**copy_map(t_game game)
{
	char	**copy_map;
	int		i;

	i = 0;
	copy_map = malloc(sizeof(char *) * (game.height + 1));
	while (i < game.height)
	{
		copy_map[i] = ft_strdup(game.map[i]);
		i++;
	}
	copy_map[i] = NULL;
	return (copy_map);
}

void	floodfill(char **copy_map, int x, int y)
{
	if (copy_map[y][x] == '1' || copy_map[y][x] == 'F' || copy_map[y][x] == 'E')
		return ;
	copy_map[y][x] = 'F';
	floodfill(copy_map, x + 1, y);
	floodfill(copy_map, x - 1, y);
	floodfill(copy_map, x, y + 1);
	floodfill(copy_map, x, y - 1);
}

int	winable(char **copy_map, t_game *game)
{
	int	x;
	int	y;
	int	temp;

	y = 0;
	temp = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (!(copy_map[y][x] == '1' || copy_map[y][x] == 'F'
					|| copy_map[y][x] == 'E'))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
