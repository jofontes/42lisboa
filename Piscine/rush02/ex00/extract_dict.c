/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:12:30 by nsilva-n          #+#    #+#             */
/*   Updated: 2024/10/09 15:13:24 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	opening(void)
{
	int	fd;

	fd = open("numbers.dict", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error");
		return (0);
	}
	return (fd);
}

int	count_bytes(void)
{
	int				fd;
	char			temp[1];
	ssize_t			bytesread;
	int				bytes_nbr;

	bytes_nbr = 0;
	fd = opening();
	bytesread = read(fd, temp, 1);
	while (bytesread > 0)
	{
		bytes_nbr++;
		bytesread = read(fd, temp, 1);
	}
	if (bytesread == -1)
		write(1, "Error\n", 6);
	close(fd);
	return (bytes_nbr);
}

char	*dikchi(void)
{
	char	*dict;
	int		fd;
	ssize_t	bytesread;
	char	buffer[BUFFER_SIZE];
	int		i;

	fd = opening();
	dict = (char *)malloc(count_bytes() * sizeof(char));
	if (dict == NULL)
		return (0);
	bytesread = read(fd, buffer, sizeof(buffer));
	i = 0;
	while (i < count_bytes() && buffer[i] != '\0')
	{
		dict[i] = buffer[i];
		i++;
	}
	dict[i + 1] = '\0';
	bytesread = 0;
	return (dict);
}
