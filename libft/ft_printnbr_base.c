/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:09:24 by niguilbe          #+#    #+#             */
/*   Updated: 2025/08/25 12:32:51 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	print_base(unsigned long num, char *base, size_t base_len)
{
	char	str[65];
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	if (num == 0)
		return (ft_printchar(base[0]));
	while (num != 0)
	{
		str[i] = base[num % base_len];
		num /= base_len;
		i++;
	}
	while (i--)
		len += ft_printchar(str[i]);
	return (len);
}

size_t	ft_printnbr_base(unsigned long nbr, char format)
{
	if (format == 'x')
		return (print_base(nbr, "0123456789abcdef", 16));
	else if (format == 'X')
		return (print_base(nbr, "0123456789ABCDEF", 16));
	return (0);
}
