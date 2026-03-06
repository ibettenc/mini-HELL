/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:54:34 by niguilbe          #+#    #+#             */
/*   Updated: 2026/03/05 13:49:59 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	read_heredoc_input(int write_fd, char *delimiter)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (delimiter && ft_strncmp(line, delimiter,
				ft_strlen(delimiter) + 1) == 0)
		{
			free (line);
			break ;
		}
		ft_putendl_fd(line, write_fd);
		free(line);
	}
}

static void	exec_heredoc_child(int *fd, char *delimiter)
{
	signal(SIGINT, SIG_DFL);
	close(fd[0]);
	read_heredoc_input(fd[1], delimiter);
	close(fd[1]);
	exit(0);
}

int	handle_heredoc(char *delimiter)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	if (pipe(fd) == -1)
	{
		perror("heredoc pipe");
		return (-1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("heredoc fork");
		return (-1);
	}
	if (pid == 0)
		exec_heredoc_child(fd, delimiter);
	close(fd[1]);
	waitpid(pid, &status, 0);
	return (fd[0]);
}
