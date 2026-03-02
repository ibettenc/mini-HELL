/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:08:43 by niguilbe          #+#    #+#             */
/*   Updated: 2025/05/14 15:21:34 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
#include "libft.h"

int	main(void)
{
	int i = 0;
	while ( i <= 127)
	{
		int std = isprint(i);
		int pers = ft_isprint(i);
		if (std != pers)
		{
			printf("BIG MISTAKE at i = %d: isprint = %d, 
				ft_isprint = %d\n", i, std, pers);
		}
		i++;
	}
	return (0);
}
*/
