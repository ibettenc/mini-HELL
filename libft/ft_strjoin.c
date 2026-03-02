/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:04:04 by niguilbe          #+#    #+#             */
/*   Updated: 2025/09/19 11:52:56 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = '\0';
	return (res);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*s1 = "Coucou ";
	char	*s2 = NULL;
	char	*exp = NULL;
	char	*res = ft_strjoin(s1, s2);

	if (res && strcmp(exp, res) == 0)
	{
		printf("It worked\n");
	}
	else
	{
		printf("something is wrong\n");
	}
	free (res);
	return (0);
} */
