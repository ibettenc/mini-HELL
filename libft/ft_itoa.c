/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:06:15 by niguilbe          #+#    #+#             */
/*   Updated: 2025/05/16 14:27:24 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n > 0)
	{
		while (n >= 10)
		{
			n = n / 10;
			i++;
		}
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*num;
	int		is_negative;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	is_negative = 0;
	len = ft_size(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	num[len] = '\0';
	if (n < 0)
	{
		n *= -1;
		is_negative = 1;
	}
	while (len-- > 0)
	{
		num[len] = (n % 10) + 48;
		n = n / 10;
	}
	if (is_negative)
		num[0] = '-';
	return (num);
}
/*
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*res;

	res = ft_itoa(0);
	printf("itoa = \"%s\"\n", res);
	free(res);
	res = ft_itoa(-42);
	printf("itoa = \"%s\"\n", res);
	free(res);
	res = ft_itoa(132456);
	printf("itoa = \"%s\"\n", res);
	free(res);
	res = ft_itoa(-123456);
	printf("itoa = \"%s\"\n", res);
	free(res);
	res = ft_itoa(INT_MIN);
	printf("itoa = \"%s\"\n", res);
	free(res);
	res = ft_itoa(INT_MAX);
	printf("itoa = \"%s\"\n", res);
	free(res);
	return (0);
}
*/
