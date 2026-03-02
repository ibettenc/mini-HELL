/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:21:19 by niguilbe          #+#    #+#             */
/*   Updated: 2026/01/16 17:34:11 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_unset(t_shell *shell, t_command *cmd)
{
	int	i;

	i = 1;
	while (cmd->args[i])
	{
		env_unset(&shell->env, cmd->args[i]);
		i++;
	}
	return (0);
}
