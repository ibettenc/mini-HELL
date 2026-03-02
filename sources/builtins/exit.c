/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:32:22 by niguilbe          #+#    #+#             */
/*   Updated: 2026/01/16 17:34:00 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_exit(t_shell *shell, t_command *cmd)
{
	int	exit_code;

	ft_putendl_fd("exit", 2);
	if (!cmd->args[1])
		clean_exit(shell, shell->exit_code);
	if (!is_numeric(cmd->args[1]))
	{
		print_cmd_error("exit", "numeric argument required");
		clean_exit(shell, 2);
	}
	if (cmd->args[2])
	{
		print_cmd_error("exit", "too many arguments");
		return (1);
	}
	exit_code = ft_atoi(cmd->args[1]);
	clean_exit(shell, exit_code);
	return (0);
}
