/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:17:29 by niguilbe          #+#    #+#             */
/*   Updated: 2026/01/16 17:35:04 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* --- DISPATCHER --- */
int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (ft_strncmp(cmd, "echo", 5) == 0)
		return (1);
	if (ft_strncmp(cmd, "cd", 3) == 0)
		return (1);
	if (ft_strncmp(cmd, "pwd", 4) == 0)
		return (1);
	if (ft_strncmp(cmd, "export", 7) == 0)
		return (1);
	if (ft_strncmp(cmd, "unset", 6) == 0)
		return (1);
	if (ft_strncmp(cmd, "env", 4) == 0)
		return (1);
	if (ft_strncmp(cmd, "exit", 5) == 0)
		return (1);
	return (0);
}

int	exec_builtin(t_shell *sh, t_command *cmd)
{
	if (ft_strncmp(cmd->args[0], "cd", 3) == 0)
		return (ft_cd(sh, cmd));
	if (ft_strncmp(cmd->args[0], "export", 7) == 0)
		return (ft_export(sh, cmd));
	if (ft_strncmp(cmd->args[0], "unset", 6) == 0)
		return (ft_unset(sh, cmd));
	if (ft_strncmp(cmd->args[0], "echo", 5) == 0)
		return (ft_echo(cmd));
	if (ft_strncmp(cmd->args[0], "pwd", 4) == 0)
		return (ft_pwd());
	if (ft_strncmp(cmd->args[0], "env", 4) == 0)
		return (ft_env(sh));
	if (ft_strncmp(cmd->args[0], "exit", 5) == 0)
		return (ft_exit(sh, cmd));
	return (0);
}

int	is_parent_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (ft_strncmp(cmd, "cd", 3) == 0)
		return (1);
	if (ft_strncmp(cmd, "export", 7) == 0)
		return (1);
	if (ft_strncmp(cmd, "unset", 6) == 0)
		return (1);
	if (ft_strncmp(cmd, "exit", 5) == 0)
		return (1);
	return (0);
}
