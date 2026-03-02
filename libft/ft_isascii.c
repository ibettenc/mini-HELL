/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:06:52 by niguilbe          #+#    #+#             */
/*   Updated: 2025/05/06 16:41:06 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int	c = -1;
	int	d = ' ';
	int	e = 'q';
	int	f = 'Z';
	int	g = '\t';

	printf("%d\n", ft_isascii(c));
	printf("%d\n", isascii(c));
	printf("%d\n", ft_isascii(d));
	printf("%d\n", isascii(d));
	printf("%d\n", ft_isascii(e));
	printf("%d\n", isascii(e));
	printf("%d\n", ft_isascii(f));
	printf("%d\n", isascii(f));
	printf("%d\n", ft_isascii(g));
	printf("%d\n", isascii(g));
	return (0);
}
*/
