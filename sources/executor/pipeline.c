/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:06:00 by niguilbe          #+#    #+#             */
/*   Updated: 2026/01/16 17:38:40 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	redirect_pipes(int prev_pipe, int pipe_fd[2], t_command *cmd)
{
	if (prev_pipe != -1)
	{
		dup2(prev_pipe, STDIN_FILENO);
		close(prev_pipe);
	}
	if (cmd->next)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
	}
}

static void	wait_for_pipeline(t_shell *shell, pid_t last_pid)
{
	int	status;

	if (last_pid != -1)
	{
		waitpid(last_pid, &status, 0);
		if (WIFEXITED(status))
			shell->exit_code = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			shell->exit_code = 128 + WTERMSIG(status);
	}
	while (wait(NULL) > 0)
		;
}

static void	exec_in_pipe(t_shell *shell, t_command *cmd, int prev_pipe,
							int pipe_fd[2])
{
	int	exit_code;

	redirect_pipes(prev_pipe, pipe_fd, cmd);
	if (apply_redirections(cmd) == 1)
		exit(1);
	if (is_builtin(cmd->args[0]))
	{
		shell->exit_code = exec_builtin(shell, cmd);
		exit(shell->exit_code);
	}
	else
	{
		exit_code = exec_external_child(shell, cmd);
		exit(exit_code);
	}
}

void	execute_pipeline(t_shell *shell, t_command *cmd)
{
	int		pipe_fd[2];
	int		prev_pipe;
	pid_t	last_pid;

	prev_pipe = -1;
	last_pid = -1;
	while (cmd)
	{
		if (cmd->next && pipe(pipe_fd) == -1)
		{
			perror("pipe");
			return ;
		}
		last_pid = fork();
		if (last_pid == -1)
			perror("fork");
		if (last_pid == 0)
			exec_in_pipe(shell, cmd, prev_pipe, pipe_fd);
		if (prev_pipe != -1)
			close(prev_pipe);
		if (cmd->next)
		{
			close(pipe_fd[1]);
			prev_pipe = pipe_fd[0];
		}
		cmd = cmd->next;
	}
	wait_for_pipeline(shell, last_pid);
}
