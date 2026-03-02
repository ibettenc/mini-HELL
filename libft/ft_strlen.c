/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:13:11 by niguilbe          #+#    #+#             */
/*   Updated: 2025/05/14 14:42:11 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	s[] = "Coucou Hibou";
	char	s1[] = " ";	
	char	s2[] = "";
	char	s3[] = "\t";
	printf("%zu\n", ft_strlen(s));
	printf("%lu\n", strlen(s));
	printf("%zu\n", ft_strlen(s1));
	printf("%lu\n", strlen(s1));
	printf("%zu\n", ft_strlen(s2));
	printf("%lu\n", strlen(s2));
	printf("%zu\n", ft_strlen(s3));
	printf("%lu\n", strlen(s3));
	return (0);
}
*/
