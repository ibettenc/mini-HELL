/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:22:29 by niguilbe          #+#    #+#             */
/*   Updated: 2025/05/14 15:21:59 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	size_t				i;

	str = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[50];
	int		c;
	size_t	n;
	void	*res_std;
	void	*res_pers;

	str[50] = "Coucou Hibou";
	
	c = '4';
	n = 10;
	res_std = memchr(str, c, n);
	res_pers = ft_memchr(str, c , n);
	if (res_std == res_pers)
		printf("Good");
	else
		printf("bad");
	return (0);
}
*/
