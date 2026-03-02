/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:06:58 by niguilbe          #+#    #+#             */
/*   Updated: 2025/05/16 14:28:57 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		i;
	size_t		len;
	char		*res;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
#include <stdio.h>
#include <stdlib.h>

char	apply_toupper (unsigned int i, char c)
{
	return (ft_toupper(c));
}
char	to_upper(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
int	main (void)
{
	char	*s;
	char	*res_strmapi;
	char	*res_manual;

	s = "1";
	
	res_strmapi = ft_strmapi(s, apply_toupper);
	if (!res_strmapi)
	{
		printf("Mlloc failed\n");
		return (1);
	}
	res_manual = ft_strmapi(s, to_upper);
	if (!res_manual)
	{
		printf("Malloc failed\n");
		free(res_manual);
		return (1);
	}
	printf("Original : %s\n", s);
	printf("ft_strmapi: %s\n", res_strmapi);
	printf("Manual : %s\n", res_manual);
	if(ft_strncmp(res_strmapi, res_manual, ft_strlen(s)) == 0)
		printf("Everythign good\n");
	else
		printf("Nop not working");
	free(res_manual);
	free(res_strmapi);
	return (0);
}
*/
