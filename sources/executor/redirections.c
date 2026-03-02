/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:15:14 by niguilbe          #+#    #+#             */
/*   Updated: 2026/01/16 17:37:14 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	process_redir(t_redir *redir)
{
	int	fd;
	int	flags;

	fd = -1;
	if (redir->type == REDIR_IN)
	{
		fd = open(redir->file, O_RDONLY);
		if (fd < 0)
			return (print_cmd_error(redir->file, strerror(errno)), 1);
		if (dup2(fd, STDIN_FILENO) == -1)
			return (close(fd), 1);
	}
	else if (redir->type == REDIR_OUT || redir->type == APPEND)
	{
		if (redir->type == APPEND)
			flags = O_WRONLY | O_CREAT | O_APPEND;
		else
			flags = O_WRONLY | O_CREAT | O_TRUNC;
		fd = open(redir->file, flags, 0644);
		if (fd < 0)
			return (print_cmd_error(redir->file, strerror(errno)), 1);
		if (dup2(fd, STDOUT_FILENO) == -1)
			return (close(fd), 1);
	}
	else if (redir->type == HEREDOC)
	{
		fd = handle_heredoc(redir->file);
		if (fd < 0)
			return (1);
		if (dup2(fd, STDIN_FILENO) == -1)
			return (close(fd), 1);
	}
	if (fd != -1)
		close(fd);
	return (0);
}

int	apply_redirections(t_command *cmd)
{
	t_redir	*tmp;

	if (!cmd || !cmd->redirs)
		return (0);
	tmp = cmd->redirs;
	while (tmp)
	{
		if (process_redir(tmp))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
