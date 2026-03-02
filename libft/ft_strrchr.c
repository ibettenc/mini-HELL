/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:11:09 by niguilbe          #+#    #+#             */
/*   Updated: 2025/05/14 17:06:32 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;
	char			*last;

	i = 0;
	cc = (char)c;
	last = 0;
	while (s[i])
	{
		if (s[i] == cc)
			last = (char *)&s[i];
		i++;
	}
	if (s[i] == cc)
		last = (char *)&s[i];
	return (last);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[];
	char	chr;

	str[] = "coucou";
	chr = 'C';
	printf("strrchr : %s\n", strrchr(str, chr));
	printf("ft_strrchr : %s\n", ft_strrchr(str, chr));
	
	return (0);
}
*/
