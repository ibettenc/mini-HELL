/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:52:47 by niguilbe          #+#    #+#             */
/*   Updated: 2025/08/25 12:32:59 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (ft_printstr("-2147483648"));
	if (n < 0)
	{
		len += ft_printchar('-');
		n = -n;
	}
	if (n >= 10)
		len += ft_printnbr(n / 10);
	len += ft_printchar((n % 10) + '0');
	return (len);
}
