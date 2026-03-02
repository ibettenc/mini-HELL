/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:44:52 by niguilbe          #+#    #+#             */
/*   Updated: 2025/05/17 14:13:23 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dest1[10];
	const char *src = "Coucou Hibou";
	unsigned int copied = ft_strlcpy(dest1, src, sizeof(dest1));
	printf("ft_strlcpy returned: %u\n", copied);
	printf("dest1: %s\n", dest1);
	return (0);
}
*/
