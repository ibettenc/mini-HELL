/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:10:57 by niguilbe          #+#    #+#             */
/*   Updated: 2025/05/16 14:44:24 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	nbr;

	if (!fd || fd < 0)
		return ;
	nbr = n + 48;
	if (n == -2147483648)
	{
		write(fd, "-", 1);
		write(fd, "2", 1);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putnbr_fd((n % 10), fd);
	}
	else
		write(fd, &nbr, 1);
}
/*
int	main (void)
{
	size_t	i;

	int	nbrs [6] = {0, -23, 23, 2147483647, -2147483648, - 0};
	nbrs[0] = 0;
	nbrs[1] = -0;
	nbrs[2] = -23;
	nbrs[3] = 23;
	nbrs[4] = 2147483647;
	nbrs[5] = -2147483648;
	i = 0;
	while (i < 6)
	{
		ft_putnbr_fd(nbrs[i], 1);
		write(1, "\n", 1);
		i++;
	}
}
*/
