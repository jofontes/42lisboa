/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:39:26 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/13 12:52:15 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Colocar a letra em minusculo e retorna a letra

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
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
