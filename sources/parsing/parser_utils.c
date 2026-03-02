/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:42:30 by niguilbe          #+#    #+#             */
/*   Updated: 2026/01/16 17:24:06 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	args_len(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return (0);
	while (args[i])
		i++;
	return (i);
}

void	add_word_to_cmd(t_command *cmd, char *word)
{
	char	**new_args;
	int		i;
	int		len;

	if (!cmd || !word)
		return ;
	len = args_len(cmd->args);
	new_args = malloc(sizeof(char *) * (len + 2));
	if (!new_args)
		return ;
	i = 0;
	while (i < len)
	{
		new_args[i] = cmd->args[i];
		i++;
	}
	new_args[i] = ft_strdup(word);
	new_args[i + 1] = NULL;
	if (cmd->args)
		free(cmd->args);
	cmd->args = new_args;
}

void	add_redir_to_cmd(t_command *cmd, t_token_type type, char *file)
{
	t_redir	*new_redir;
	t_redir	*tmp;

	new_redir = malloc(sizeof(t_redir));
	if (!new_redir)
		return ;
	new_redir->type = type;
	new_redir->file = ft_strdup(file);
	new_redir->next = NULL;
	if (!cmd->redirs)
		cmd->redirs = new_redir;
	else
	{
		tmp = cmd->redirs;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = new_redir;
	}
}

void	print_commands(t_command *cmds)
{
	int	i;

	while (cmds)
	{
		printf("=== COMMAND ===\n");
		i = 0;
		if (cmds->args)
		{
			while (cmds->args[i])
			{
				printf("arg[%d]: %s\n", i, cmds->args[i]);
				i++;
			}
		}
		else
			printf("no args\n");
		if (!cmds->redirs)
			printf("no redirs\n");
		printf("next: %p\n", (void *)cmds->next);
		printf("\n");
		cmds = cmds->next;
	}
}
