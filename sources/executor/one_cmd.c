/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:47:28 by niguilbe          #+#    #+#             */
/*   Updated: 2026/03/05 14:17:20 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exec_external_child(t_shell *sh, t_command *cmd)
{
	char			**envp;
	char			*path;

	if (check_directory_error(cmd->args[0]) == 126)
		return (126);
	envp = env_to_array(sh->env);
	if (!envp)
		return (1);
	path = resolve_cmd_path(cmd->args[0], envp);
	if (!path)
	{
		print_cmd_error(cmd->args[0], "command not found");
		free_strs(envp);
		return (127);
	}
	execve(path, cmd->args, envp);
	print_cmd_error(cmd->args[0], strerror(errno));
	free(path);
	free_strs(envp);
	if (errno == ENOENT)
		return (127);
	return (126);
}

static void	child_process(t_shell *sh, t_command *cmd)
{
	int	code;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (apply_redirections(cmd))
		exit(1);
	if (is_builtin(cmd->args[0]))
	{
		code = exec_builtin(sh, cmd);
		exit(code);
	}
	code = exec_external_child(sh, cmd);
	exit(code);
}

static void	execute_forked_cmd(t_shell *sh, t_command *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		print_cmd_error("fork", "failed");
		sh->exit_code = 1;
		return ;
	}
	if (pid == 0)
		child_process(sh, cmd);
	sh->exit_code = wait_exit_code(pid);
}

void	execute_single_cmd(t_shell *sh, t_command *cmd)
{
	if (!cmd || !cmd->args || !cmd->args[0] || cmd->args[0][0] == '\0')
		return ;
	if (is_parent_builtin(cmd->args[0]))
	{
		if (apply_redirections(cmd))
		{
			sh->exit_code = 1;
			return ;
		}
		sh->exit_code = exec_builtin(sh, cmd);
		return ;
	}
	execute_forked_cmd(sh, cmd);
}
