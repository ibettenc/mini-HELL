/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:18:31 by niguilbe          #+#    #+#             */
/*   Updated: 2025/05/17 14:21:05 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[];
	char	str2[];
	size_t	n;
	int		res_std;
	int		res_pers;

	str[] = "132";
	str2[] = "123";
	n = 0;
	res_std = strncmp(str, str2, n);
	res_pers = ft_strncmp(str, str2, n);
	
	printf(" strncmp : %d\n", res_std);
	printf(" ft_strncmp : %d\n", res_pers);
	if (res_std == res_pers)
		printf("gg");
	else
		printf("sale nul");
	return (0);
}
*/