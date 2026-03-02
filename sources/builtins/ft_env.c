/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:31:48 by niguilbe          #+#    #+#             */
/*   Updated: 2026/01/16 17:32:11 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_env(t_shell *sh)
{
	t_env	*tmp;

	tmp = sh->env;
	while (tmp)
	{
		if (tmp->value)
		{
			ft_putstr_fd(tmp->key, 1);
			ft_putstr_fd("=", 1);
			ft_putstr_fd(tmp->value, 1);
			ft_putstr_fd("\n", 1);
		}
		tmp = tmp->next;
	}
	return (0);
}
