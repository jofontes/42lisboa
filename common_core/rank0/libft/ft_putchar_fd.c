/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:13:20 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/12 13:55:07 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// faz output do caractere c para o tipo de fd

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
