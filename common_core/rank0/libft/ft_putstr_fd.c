/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:27:12 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/13 14:53:11 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// output a string s com o fd dado

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

// int main()
// {
// 	char *str = "hello world";
// 	int fd = 1;
// 	ft_putstr_fd(str, fd);
// }