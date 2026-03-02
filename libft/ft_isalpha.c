/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:07:21 by niguilbe          #+#    #+#             */
/*   Updated: 2025/05/17 13:45:26 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int	c = '1';
	int	d = ' ';
	int	e = 'q';
	int	f = 'Z';
	int	g = '\t';

	printf("%d\n", ft_isalpha(c));
	printf("%d\n", isalpha(c));
	printf("%d\n", ft_isalpha(d));
	printf("%d\n", isalpha(d));
	printf("%d\n", ft_isalpha(e));
	printf("%d\n", isalpha(e));
	printf("%d\n", ft_isalpha(f));
	printf("%d\n", isalpha(f));
	printf("%d\n", ft_isalpha(g));
	printf("%d\n", isalpha(g));
	return (0);
}
*/
