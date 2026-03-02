/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:02:56 by niguilbe          #+#    #+#             */
/*   Updated: 2025/05/16 14:49:51 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	str_len;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len || len == 0)
		return (ft_strdup(""));
	if (start + len > str_len)
		str = malloc(sizeof(char) * (str_len - start + 1));
	else
		str = malloc(sizeof(char) * (len +1));
	if (!str)
		return (NULL);
	while (i < len && s[start])
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    const char *s = "Coucou Hibou";
    unsigned int start = 13;
    size_t len = 3;
    char *res = ft_substr(s, start, len);
    const char *exp = "u Hibo";

    if (res && strcmp(res, exp) == 0)
    {
        printf("Woop woop ass ass 1 \n");
		printf("We expected : \"%s\"\n", exp);
        printf("& We Got      : \"%s\"\n", res);
    }
    else
    {
        printf("WRONG\n");
        printf("We expected : \"%s\"\n", exp);
        printf("& We Got      : \"%s\"\n", res);
    }

    free(res);
    return 0;
}
*/
