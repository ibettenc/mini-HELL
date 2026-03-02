/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:23:46 by niguilbe          #+#    #+#             */
/*   Updated: 2025/08/25 12:33:07 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printptr(void *ptr)
{
	unsigned long	nbr;
	int				len;

	if (!ptr)
		return (ft_printstr("(nil)"));
	nbr = (unsigned long) ptr;
	len = 0;
	len += ft_printstr("0x");
	len += ft_printnbr_base(nbr, 'x');
	return (len);
}
