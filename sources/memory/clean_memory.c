/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:05:43 by niguilbe          #+#    #+#             */
/*   Updated: 2026/01/14 19:01:09 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	reset_loop(t_shell *shell, char *line)
{
	if (line)
		free(line);
	if (shell->tokens)
	{
		free_tokens(shell->tokens);
		shell->tokens = NULL;
	}
	if (shell->cmds)
	{
		free_commands(shell->cmds);
		shell->cmds = NULL;
	}
}

void	clean_exit(t_shell *shell, int exit_code)
{
	if (shell->cmds)
		free_commands(shell->cmds);
	if (shell->tokens)
		free_tokens(shell->tokens);
	if (shell->env)
		free_env(shell->env);
	rl_clear_history();
	exit(exit_code);
}

void	free_tokens(t_token *tokens)
{
	t_token	*tmp;

	while (tokens)
	{
		tmp = tokens;
		tokens = tokens->next;
		if (tmp->value)
			free(tmp->value);
		free(tmp);
	}
}

static void	free_redirs(t_redir *redirs)
{
	t_redir	*tmp;

	while (redirs)
	{
		tmp = redirs;
		redirs = redirs->next;
		if (tmp->file)
			free(tmp->file);
		free(tmp);
	}
}

void	free_commands(t_command *cmds)
{
	t_command	*tmp;
	int			i;

	while (cmds)
	{
		tmp = cmds;
		cmds = cmds->next;
		if (tmp->args)
		{
			i = 0;
			while (tmp->args[i])
			{
				free(tmp->args[i]);
				i++;
			}
			free(tmp->args);
		}
		if (tmp->redirs)
			free_redirs(tmp->redirs);
		free(tmp);
	}
}
