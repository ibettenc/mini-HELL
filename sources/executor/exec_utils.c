/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:00:50 by niguilbe          #+#    #+#             */
/*   Updated: 2026/03/05 14:16:23 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	wait_exit_code(pid_t pid)
{
	int	status;

	if (waitpid(pid, &status, 0) < 0)
		return (1);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	return (1);
}

int	check_directory_error(char *cmd_name)
{
	struct stat	path_stat;

	if (stat(cmd_name, &path_stat) == 0 && S_ISDIR(path_stat.st_mode))
	{
		if (ft_strchr(cmd_name, '/'))
		{
			print_cmd_error(cmd_name, "Is a directory");
			return (126);
		}
	}
	return (0);
}
