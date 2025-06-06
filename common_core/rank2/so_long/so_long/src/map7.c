/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map7.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:04:58 by josaraiv          #+#    #+#             */
/*   Updated: 2025/06/06 11:09:11 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_map_size(t_game *game)
{
	int	screen_w;
	int	screen_h;

	mlx_get_screen_size(game->mlx, &screen_w, &screen_h);
	if (game->width * TILE_SIZE > screen_w || game->height
		* TILE_SIZE > screen_h)
	{
		write(2, "Error - invalid map\n", 20);
		close_game(game);
		return (0);
	}
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	is_valid_ber_file(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len <= 4)
		return (0);
	if (ft_strncmp(filename + len - 4, ".ber", 4) != 0 || \
		ft_strncmp(filename + len - 5, "/.ber", 5) == 0)
		return (0);
	return (1);
}
