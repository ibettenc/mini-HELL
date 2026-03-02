/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:35:11 by niguilbe          #+#    #+#             */
/*   Updated: 2025/05/17 11:57:25 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(int num, int neg_count, int pos_count)
{
	if (neg_count == 1)
		num = -num;
	if ((neg_count > 0 && pos_count > 0) || neg_count > 1 || pos_count > 1)
		num = 0;
	return (num);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg_count;
	int	pos_count;
	int	num;

	i = 0;
	neg_count = 0;
	pos_count = 0;
	num = 0;
	while ((nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13)) && nptr[i])
		i++;
	while ((nptr[i] == '+' || nptr[i] == '-') && nptr[i])
	{
		if (nptr[i] == '-')
			neg_count++;
		if (nptr[i] == '+')
			pos_count++;
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9') && nptr[i])
		num = (num * 10) + (nptr[i++] - 48);
	num = ft_sign(num, neg_count, pos_count);
	return (num);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int			i;
	const char	*input;
	int			std;
	int			custom;

	const char *tests[] = 
	{
		"-42",
		"+42",
		"--++42",
		"1",
		"12-23",
		"   -+321",
		"   +++--321",
		"abc",
		"   ",
		"",
		"999999999999999999",
		"-888888888888888888",
		"\t\v-23",
		NULL
	};
	i = 0;
	while(tests[i])
	{
		input = tests[i];
		std = atoi(input);
		custom = ft_atoi(input);
		printf("input: \"%s\"\n", input);
		printf(" atoi = %d\n", std);
		printf(" ft_atoi = %d\n", custom);
		if (std == custom)
			printf("OK\n");
		else
			printf("NOT OK\n");
		i++;
	}
	return (0);
}
*/
