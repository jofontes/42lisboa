/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josaraiv <josaraiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:34:44 by josaraiv          #+#    #+#             */
/*   Updated: 2024/11/29 14:46:24 by josaraiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char *str;
	int i;

	i = 0;
	
	while(buffer[0] || )
}