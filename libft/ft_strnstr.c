/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:31:34 by niguilbe          #+#    #+#             */
/*   Updated: 2025/05/17 14:22:57 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (i + j < len && big[i + j] == little[j])
		{
			j++;
			if (little[j] == '\0')
				return ((char *)big + i);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*big;
	const char	*little;
	size_t		len;
	char		*res;

    big = "Coucou Hibou";
    little = "co";
    len = 50;
    res = ft_strnstr(big, little, len);
    if (res)
        printf("Found: %s\n", res);
    else
        printf("Not found\n returned : %s", res);
    return (0);
}
*/
