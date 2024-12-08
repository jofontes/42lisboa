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


// int	ft_linelen(char *str)
// {
// 	int	ctd;

// 	ctd = 0;
// 	while (str && str[ctd] && str[ctd] != '\n')
// 		ctd++;
// 	if (str && str[ctd] == '\n')
// 		ctd++;
// 	return (ctd);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	int		ctd;
// 	int		ctd2;
// 	char	*str;

// 	ctd = 0;
// 	str = (char *)malloc(ft_linelen(s1) + ft_linelen(s2) + 1);
// 	if (!str)
// 		return (free(s1), NULL);
// 	while (s1 && s1[ctd])
// 	{
// 		str[ctd] = s1[ctd];
// 		ctd++;
// 	}
// 	ctd2 = 0;
// 	while (s2[ctd2] != '\n' && s2[ctd2])
// 	{
// 		str[ctd + ctd2] = s2[ctd2];
// 		ctd2++;
// 	}
// 	if (s2[ctd2] == '\n')
// 		str[ctd + ctd2++] = '\n';
// 	str[ctd + ctd2] = '\0';
// 	if (s1)
// 		free(s1);
// 	return (str);
// }

// void	buffer_clean(char *str)
// {
// 	int	ctd;
// 	int	ctd2;

// 	ctd = 0;
// 	ctd2 = 0;
// 	while (str[ctd] != '\n' && ctd < BUFFER_SIZE)
// 	{
// 		str[ctd] = '\0';
// 		ctd++;
// 	}
// 	if (str[ctd] == '\n')
// 	{
// 		str[ctd] = '\0';
// 		ctd++;
// 		while (ctd < BUFFER_SIZE)
// 		{
// 			str[ctd2] = str[ctd];
// 			str[ctd] = '\0';
// 			ctd++;
// 			ctd2++;
// 		}
// 	}
// }
// char	*get_next_line(int fd)
// {
// 	static char		buffer [BUFFER_SIZE + 1];
// 	char			*str;
// 	int				ctd;

// 	ctd = 0;
// 	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
// 	{	
// 		while (ctd <= BUFFER_SIZE)
// 			buffer[ctd++] = '\0';
// 		return (NULL);
// 	}
// 	str = NULL;
// 	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
// 	{
// 		str = ft_strjoin(str, buffer);
// 		if (!str)
// 			return (NULL);
// 		buffer_clean(buffer);
// 		if (str[ft_linelen(str) - 1] == '\n')
// 			return (str);
// 	}
// 	return (str);
// }

int ft_strlen(char *str, char idk)
{
	int i;
	i = 0;

	if(!str)
		return (0);
	while(str[i] && str[i] != idk)
		i++;
	if(str[i] == '\n')
		i++;
	return (i);
}


char *ft_strjoin(char *next_line, char *buffer)
{
	int i;
	int j;
	int s1_len;
	int s2_len;
	char *dest;


	s1_len = ft_strlen(next_line, 0);
	s2_len = ft_strlen(buffer, '\n');
	i = 0;
	j = 0;
	dest = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if(!dest)
		return (NULL);
	while(i < s1_len)
	{
		dest[i] = next_line[i];
		i++;
	}

	while(j < s2_len)
	{
		dest[i] = buffer[j];
		i++;
		j++;
	}
	free(next_line);
	
	dest[i] = '\0';
	
	return (dest);
	
}


void buffer_clean(char *buffer)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && i < BUFFER_SIZE)
	{
		buffer[i] = '\0';
		i++;
	}
	if (buffer[i] == '\n')
	{
		buffer[i] = '\0';
		i++;
		while (i < BUFFER_SIZE)
		{
			buffer[j] = buffer[i];
			buffer[i] = '\0';
			i++;
			j++;
		}
	}
}
char *check_buffer_newline(char *buffer)
{
	int i;
	i = 0;
	char *new_buffer;
	new_buffer = NULL;
	while(buffer[i] != '\0')
	{
		new_buffer[i] = buffer[i];
		if(buffer[i] == '\n')
			return (new_buffer);
		i++;
	}
	return buffer;
}

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char *next_line;
	int	bytes_read;
	

	char *new_buffer;


	next_line = NULL;
	//printf("next_line inicio: %s\n", next_line);
	bytes_read = 1;
	while(bytes_read > 0 || buffer[0])
	{
		//printf("buffer antes: %s\n", buffer);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';

		new_buffer = check_buffer_newline(buffer);

		//printf("buffer depois: %s\n", buffer);
		next_line = ft_strjoin(next_line, new_buffer);
		//printf("next_line depois: %s \n", next_line);
		//buffer_clean(buffer);
	}
	
	
	return (next_line);
}


int main()
{
	int fd;
	fd = open("text2.txt", O_RDONLY);
	char *next_line;
	next_line = get_next_line(fd);
	printf("%s\n", next_line);
	
}










// int ft_strlen(char *str)
// {
// 	int i;
// 	i = 0;

// 	while(str && (str[i] != '\0'))
// 		i++;
// 	return (i);
// }


// char *ft_strjoin(char *next_line, char *buffer)
// {
// 	int i;
// 	int j;
// 	char *dest;

// 	i = 0;
// 	j = 0;
// 	dest = malloc(sizeof(char) * (ft_strlen(next_line) + ft_strlen(buffer) + 1));
// 	if(!dest)
// 		return (NULL);
// 	while(next_line && next_line[i] != '\0')
// 	{
// 		dest[i] = next_line[i];
// 		i++;
// 	}

// 	while(buffer && buffer[j] != '\0' )
// 	{
// 		dest[i] = buffer[j];
// 		i++;
// 		j++;
// 	}
// 	dest[i] = '\0';
// 	free(next_line);
// 	return (dest);
	
// }



// char *get_next_line(int fd)
// {
// 	static char buffer[BUFFER_SIZE + 1];
// 	char *next_line;
// 	int	bytes_read;
	
// 	next_line = NULL;
	
// 	bytes_read = 1;
// 	while(bytes_read > 0)
// 	{
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		buffer[bytes_read] = '\0';
// 		next_line = ft_strjoin(next_line, buffer);
// 	}
	
	
// 	return (next_line);
// }