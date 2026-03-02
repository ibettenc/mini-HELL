/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:37:10 by niguilbe          #+#    #+#             */
/*   Updated: 2025/05/14 15:22:13 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*ptr_dest;
	const char	*ptr_src;
	size_t		i;

	if (!dest && !src)
		return (NULL);
	ptr_dest = (char *)dest;
	ptr_src = (const char *)src;
	i = 0;
	if (ptr_dest > ptr_src)
	{
		while (n-- > 0)
			ptr_dest[n] = ptr_src[n];
	}
	else
	{
		while (i < n)
		{
			ptr_dest[i] = ptr_src[i];
			i++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	str[];
	char	str2[];

	str[] = "coucou Hibou";
	str2[] = "coucou Hibou";
	memmove(str + 2, str2, 6);
	ft_memmove(str2 + 2, str2, 6);
	printf("str (memmove) : %s\n", str);
	printf("str2 (ft_memmove) : %s\n", str2);
	return (0);
}
*/
