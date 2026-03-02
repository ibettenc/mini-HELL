/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:39:25 by ibettenc          #+#    #+#             */
/*   Updated: 2026/03/02 16:52:06 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_word_and_redir(
	t_token *token,
	t_command **cmd_list,
	t_command **current_cmd,
	t_shell *shell)
{
	if (token->type == WORD)
	{
		expand_token(shell, token);
		if (token->is_from_var && token->value && token->value[0] == '\0')
			return ;
		if (*current_cmd == NULL)
		{
			*current_cmd = malloc(sizeof(t_command));
			(*current_cmd)->args = NULL;
			(*current_cmd)->redirs = NULL;
			(*current_cmd)->next = NULL;
			*cmd_list = *current_cmd;
		}
		add_word_to_cmd(*current_cmd, token->value);
	}
	else if (token->type == REDIR_IN || token->type == REDIR_OUT
		|| token->type == APPEND || token->type == HEREDOC)
		add_redir_to_cmd(*current_cmd, token->type, token->next->value);
}

void	handle_pipe(t_command **current_cmd)
{
	t_command	*new_cmd;

	new_cmd = malloc(sizeof(t_command));
	new_cmd->args = NULL;
	new_cmd->redirs = NULL;
	new_cmd->next = NULL;
	(*current_cmd)->next = new_cmd;
	*current_cmd = new_cmd;
}

void	handle_token(
	t_token *token,
	t_command **cmd_list,
	t_command **current_cmd,
	t_shell *shell)
{
	if (token->type == PIPE)
		handle_pipe(current_cmd);
	else
		handle_word_and_redir(token, cmd_list, current_cmd, shell);
}

t_command	*parse_tokens(t_token *tokens, t_shell *shell)
{
	t_command	*cmd_list;
	t_command	*current_cmd;

	cmd_list = NULL;
	current_cmd = NULL;
	while (tokens)
	{
		handle_token(tokens, &cmd_list, &current_cmd, shell);
		if (tokens->type == REDIR_IN || tokens->type == REDIR_OUT
			|| tokens->type == APPEND || tokens->type == HEREDOC)
			tokens = tokens->next;
		tokens = tokens->next;
	}
	return (cmd_list);
}
