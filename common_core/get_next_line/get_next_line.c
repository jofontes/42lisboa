/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:34:44 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/26 11:35:11 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int	ft_linelen(char *str)
{
	int	ctd;

	ctd = 0;
	while (str && str[ctd] && str[ctd] != '\n')
		ctd++;
	if (str && str[ctd] == '\n')
		ctd++;
	return (ctd);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		ctd;
	int		ctd2;
	char	*str;

	ctd = 0;
	str = (char *)malloc(ft_linelen(s1) + ft_linelen(s2) + 1);
	if (!str)
		return (free(s1), NULL);
	while (s1 && s1[ctd])
	{
		str[ctd] = s1[ctd];
		ctd++;
	}
	ctd2 = 0;
	while (s2[ctd2] != '\n' && s2[ctd2])
	{
		str[ctd + ctd2] = s2[ctd2];
		ctd2++;
	}
	if (s2[ctd2] == '\n')
		str[ctd + ctd2++] = '\n';
	str[ctd + ctd2] = '\0';
	if (s1)
		free(s1);
	return (str);
}

void	buffer_clean(char *str)
{
	int	ctd;
	int	ctd2;

	ctd = 0;
	ctd2 = 0;
	while (str[ctd] != '\n' && ctd < BUFFER_SIZE)
	{
		str[ctd] = '\0';
		ctd++;
	}
	if (str[ctd] == '\n')
	{
		str[ctd] = '\0';
		ctd++;
		while (ctd < BUFFER_SIZE)
		{
			str[ctd2] = str[ctd];
			str[ctd] = '\0';
			ctd++;
			ctd2++;
		}
	}
}




char	*get_next_line(int fd)
{
	static char		buffer [BUFFER_SIZE + 1];
	char			*str;
	int				ctd;

	ctd = 0;
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{	
		while (ctd <= BUFFER_SIZE)
			buffer[ctd++] = '\0';
		return (NULL);
	}
	str = NULL;
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		str = ft_strjoin(str, buffer);
		if (!str)
			return (NULL);
		buffer_clean(buffer);
		if (str[ft_linelen(str) - 1] == '\n')
			return (str);
	}
	return (str);
}














// void buffer_clean(char *buffer)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;

// 	while(i < BUFFER_SIZE && buffer[i] != '\n')
// 	{
// 		buffer[i] = '\0';
// 		i++;
// 	}
// 	if (buffer[i] == '\n')
// 	{
// 		buffer[i] = '\0';
// 		i++;
// 		while (i < BUFFER_SIZE)
// 		{
// 			buffer[j] = buffer[i];
// 			buffer[i] = '\0';
// 			i++;
// 			j++;
// 		}
// 	}
// }

// int ft_strlen(char *str)
// {
// 	int i;

// 	i = 0;
// 	while(str && str[i] && str[i] == '\n')
// 	{
// 		i++;
// 	}
// 	if(str && str[i] == '\n')
// 		i++;
// 	return (i);
// }

// char *ft_strjoin(char *line, char *buffer)
// {
// 	int i;
// 	int j;
// 	char *dest;

// 	i = 0;
// 	j = 0;

// 	dest = malloc(sizeof(char) + (ft_strlen(line) + ft_strlen(buffer) + 1));
// 	if(!dest)
// 		return (NULL);
	
// 	while(line && line[i])
// 	{
// 		dest[i] = line[i];
// 		i++;
// 	}
// 	while(buffer[j] && buffer[j] != '\n')
// 	{
// 		dest[i] = buffer[j];
// 		i++;
// 		j++;
// 	}
// 	if(buffer[j] == '\n')
// 		dest[i] = '\n';
// 	dest[i] = '\0';
// 	if (line)
// 		free(line);
// 	return (dest);
// }

// char *get_next_line(int fd)
// {	
// 	static char buffer[BUFFER_SIZE + 1];
// 	char *line;
// 	//int chars_read;
	
// 	line = NULL;
// 	//printf("buffer antes do read: %s\n", buffer);

// 	//read(fd, buffer, BUFFER_SIZE);
// 	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) >= 0)
// 	{
// 		//chars_read = read(fd, buffer, BUFFER_SIZE);
// 		//printf("buffer depois do read: %s\n", buffer);
// 		//line = buffer;
// 		line = ft_strjoin(line, buffer);
		
// 		buffer_clean(buffer);
// 		//printf("buffer depois do buffer_clean: %s\n", buffer);
		
// 		if (line[(ft_strlen(line)-1)] == '\n')
// 			return (line);
// 	}
// 	return (line);
// }


int main()
{
	int fd;
	fd = open("text.txt", O_RDONLY);
	char *next_line;
	next_line = get_next_line(fd);
	printf("%s\n", next_line);
	next_line = get_next_line(fd);
	printf("%s\n", next_line);
}
