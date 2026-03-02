/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:00:13 by niguilbe          #+#    #+#             */
/*   Updated: 2025/05/13 15:17:38 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = 0;
	while (dst_len < size && dst[dst_len])
		dst_len++;
	if (dst_len == size)
		return (size + src_len);
	i = 0;
	while ((dst_len + i + 1) < size && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len + i < size)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char		dst[50];
	char		dst2[50];
	const char	*src;
	size_t		size;
	size_t		res;
	size_t		res2;

	dst[50] = "Coucou";
	dst2[50] = "Coucou";
	src = "Hibou";
	size = 12;
	res = 0;
	res2 = 0;
	
	res = ft_strlcat(dst, src, size);
	res2 = ft_strlcat(dst2, NULL, size);
	if (res == res2 && strcmp(dst, dst2) == 0)
	{
		printf("good, it's working\n");
		printf("dst1 = %s\n", dst);
		printf("dst2 = %s\n", dst2);
	}
	else
	{
		printf("that ain't good\n");
		printf("dst1 = %s\n", dst);
		printf("dst2 = %s", dst2);
	}
	return (0);		
}
*/
