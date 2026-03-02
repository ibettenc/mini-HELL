/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:19:33 by niguilbe          #+#    #+#             */
/*   Updated: 2025/08/25 12:33:20 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printuns(unsigned int n)
{
	int		len;

	len = 0;
	if (n >= 10)
		len += ft_printuns(n / 10);
	len += ft_printchar((n % 10) + '0');
	return (len);
}
