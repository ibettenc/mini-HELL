/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 12:39:25 by ibettenc          #+#    #+#             */
/*   Updated: 2026/01/16 17:28:51 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	check_syntax_bis(t_token *current)
{
	if (current->type == HEREDOC || current->type == APPEND
		|| current->type == REDIR_IN || current->type == REDIR_OUT)
	{
		if (current->next == NULL)
			return (1);
		if (current->next->type != WORD)
			return (1);
	}
	return (0);
}

int	check_syntax(t_token *tokens)
{
	t_token	*current;

	if (!tokens)
		return (0);
	if (tokens->type == PIPE)
		return (1);
	current = tokens;
	while (current)
	{
		if (current->type == PIPE)
		{
			if (current->next == NULL)
				return (1);
			if (current->next->type == PIPE)
				return (1);
		}
		if (check_syntax_bis(current))
			return (1);
		if (current->type == WORD && current->value == NULL)
			return (1);
		current = current->next;
	}
	return (0);
}
