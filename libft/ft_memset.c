/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:41:05 by niguilbe          #+#    #+#             */
/*   Updated: 2025/05/14 15:22:04 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*(ptr++) = (unsigned char)c;
		n--;
	}
	return (s);
}
/*

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[13];
	char	str1[13];

	str[13] = "Coucou Hibou";
	str1[13] = "coucou Hibou";
	memset(str, 'X', 3);
	ft_memset(str1, 'X', 3);
	printf("str (memset): %s\n", str);
	printf("str1 (ft_memset): %s\n", str1);
	return (0);
}
*/
