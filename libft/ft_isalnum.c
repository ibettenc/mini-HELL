/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:04:16 by niguilbe          #+#    #+#             */
/*   Updated: 2025/05/17 13:45:13 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int	c;
	int	d;
	int	e;
	int	f;
	int	g;

	c = '1';
	d = ' ';
	e = 'q';
	f = 'Z';
	g = '\t';
	printf("%d\n", ft_isalnum(c));
	printf("%d\n", isalnum(c));
	printf("%d\n", ft_isalnum(d));
	printf("%d\n", isalnum(d));
	printf("%d\n", ft_isalnum(e));
	printf("%d\n", isalnum(e));
	printf("%d\n", ft_isalnum(f));
	printf("%d\n", isalnum(f));
	printf("%d\n", ft_isalnum(g));
	printf("%d\n", isalnum(g));
	return (0);
}
*/
