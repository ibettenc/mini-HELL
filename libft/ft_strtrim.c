/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:04:56 by niguilbe          #+#    #+#             */
/*   Updated: 2025/05/16 14:42:07 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calc_start(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (!set[j])
			break ;
		i++;
	}
	return (i);
}

static int	ft_calc_end(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (!set[j])
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*res;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	start = ft_calc_start(s1, set);
	end = ft_calc_end(s1, set);
	if (start > end)
		return (ft_strdup(""));
	res = malloc(sizeof(char) * ((end - start) + 2));
	if (!res)
		return (NULL);
	while (start <= end)
		res[i++] = s1[start++];
	res[i] = '\0';
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*set;
	char	*res;

	s1 = "";
    set = "1";
    res = ft_strtrim(s1, set);
    if (res)
    {
        printf("Result: \"%s\"\n", res);
        free(res);
    }
    else
    {
        printf("Failed alloc\n");
    }
    return (0);
}
*/
