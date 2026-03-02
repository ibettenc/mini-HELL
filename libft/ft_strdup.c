/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:58:52 by niguilbe          #+#    #+#             */
/*   Updated: 2025/05/14 16:59:03 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	i;

	dest = (char *)malloc(ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str[] = "";

	char *res_std = strdup(str);
	char *res_pers = ft_strdup(str);

	printf("strdup : %s\n", res_std);
	printf("ft_strdup : %s\n", res_pers);
	return (0);
}
*/
