/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:05:37 by niguilbe          #+#    #+#             */
/*   Updated: 2025/05/16 13:29:51 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char charset)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] != charset)
			&& (str[i + 1] == charset || str[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static char	**ft_free(char **res)
{
	size_t	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static char	*get_word(char const *s, char c)
{
	size_t	i;
	char	*res;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s, (i + 1));
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	while (s[i] && j < count_words(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		tab[j] = get_word(s + i, c);
		if (!tab[j])
			return (ft_free(tab));
		i += ft_strlen(tab[j]);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
/* #include <stdio.h>

int main(void)
{
    int i = 0;
    char *str = "Cou cou  HI nou";
    char **res = ft_split(str, ' ');

    while (res[i])
    {
        printf("%s\n", res[i]);
        free(res[i]);
    }
    free(res);
    return (0);
} */
