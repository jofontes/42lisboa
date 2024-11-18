/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:39:33 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/13 12:51:47 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Colocar a letra em maisculo e retorna a letra

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/*
int main()
{
	printf("%d", ft_toupper('A'));
	printf("\n%c", ft_toupper('A'));
	printf("\n%d", ft_toupper('a'));
	printf("\n%c", ft_toupper('a'));	
}
*/
