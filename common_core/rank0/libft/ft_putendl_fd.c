/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:36:50 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/13 14:53:53 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// output a string s com o fd dado seguido de uma new line

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

// int main()
// {
// 	char *str = "hello world";
// 	int fd = 1;
// 	ft_putstr_fd(str, fd);
// }