/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:55:02 by niguilbe          #+#    #+#             */
/*   Updated: 2025/05/17 14:45:43 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	if (nmemb > 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	tmp = malloc(nmemb * size);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
		tmp[i++] = 0;
	return (tmp);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	size_t	nmemb;
	size_t	ptr;
	size_t	size;
	size_t	size2;
	int		*std;
	int		*pers;

	nmemb = 0;
	ptr = 12;
	size = sizeof(NULL);
	size2 = 12;
	
	std = (int *)calloc(nmemb, size);
	pers = (int *)ft_calloc(ptr, size2);
	
	if(!std || !pers)
	{
		printf("error");
		free(std);
		free(pers);
		return (1);
	}
	if(memcmp(std, pers, nmemb * size) == 0)
		printf("nice");
	else
		printf("Bad");
	free(std);
	free(pers);
	return (0);
}
*/
