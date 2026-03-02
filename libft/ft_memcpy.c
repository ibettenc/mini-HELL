/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:47:47 by niguilbe          #+#    #+#             */
/*   Updated: 2025/05/14 15:22:17 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	if (!dest && !src)
		return (NULL);
	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	while (n > 0)
	{
		*(ptr_dest++) = *(ptr_src++);
		n--;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[];
	char	dest[20];
	char	dest2[20];

	src[] = "Coucou Hibou";
	
	memcpy(dest, src, 16);
	ft_memcpy(dest2, src, 10);
	printf("dest (memcpy) : %s\n", dest);
	printf("dest2 (ft_memcpy) : %s\n", dest2);
	return (0);
}
*/