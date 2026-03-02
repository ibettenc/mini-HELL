/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:07:58 by niguilbe          #+#    #+#             */
/*   Updated: 2025/05/17 14:07:44 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

void	apply_toupper(unsigned int i, char *c)
{
	*c = ft_toupper(*c);
}

void	to_upper(unsigned int i, char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
} */
/* int	main (void)
{
	char	s[0] = "";
	char	s2[50] = "Coucou Hibou";

	ft_striteri(s, apply_toupper);
	ft_striteri(s2, to_upper);
	printf("apply_toupper: %s\n", s);
	printf("to_upper: %s\n", s2);
	return (0);
} */