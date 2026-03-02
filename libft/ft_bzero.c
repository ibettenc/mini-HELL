/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:55:18 by niguilbe          #+#    #+#             */
/*   Updated: 2025/05/17 12:08:12 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = (char *) s;
	while (n > 0)
	{
		*(ptr++) = 0;
		n--;
	}
}
/*
#include <strings.h>
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char a[10] = "123456789";
	char b[10] = "123456789";
	
	bzero(a, 5);
	ft_bzero(b, 5);
	if (memcmp(a, b, 10) == 0)
	{
		printf("bzero = ft_bzero");
		printf("%s\n", bzero(a , 5));
		printf ("%s\n", ft_bzero (b, 5));
	}
	else
		printf("error");
	return (0);
}
*/
