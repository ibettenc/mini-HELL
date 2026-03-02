/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:02:29 by niguilbe          #+#    #+#             */
/*   Updated: 2025/05/17 13:45:59 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
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

	printf("%d\n", ft_isdigit(c));
	printf("%d\n", isdigit(c));
	printf("%d\n", ft_isdigit(d));
	printf("%d\n", isdigit(d));
	printf("%d\n", ft_isdigit(e));
	printf("%d\n", isdigit(e));
	printf("%d\n", ft_isdigit(f));
	printf("%d\n", isdigit(f));
	printf("%d\n", ft_isdigit(g));
	printf("%d\n", isdigit(g));
	return (0);
}
*/