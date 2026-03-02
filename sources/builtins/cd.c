/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 14:08:45 by niguilbe          #+#    #+#             */
/*   Updated: 2026/01/14 16:35:08 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//cwd = Current Working Directory
static void	update_wds(t_shell *shell, char *old_pwd)
{
	char	cwd[PATH_MAX];

	if (old_pwd && *old_pwd)
		env_set(&shell->env, "OLDPWD", old_pwd);
	if (getcwd(cwd, PATH_MAX))
		env_set(&shell->env, "PWD", cwd);
	else
		perror("minishell: cd: error retrieving current directory");
}

static char	*get_target_path(t_shell *shell, t_command *cmd)
{
	char	*path;

	if (!cmd->args[1])
	{
		path = env_get(shell->env, "HOME");
		if (!path)
			print_cmd_error("cd", "HOME not set");
		return (path);
	}
	if (ft_strncmp(cmd->args[1], "-", 2) == 0)
	{
		path = env_get(shell->env, "OLDPWD");
		if (!path)
		{
			print_cmd_error("cd", "OLDPWD not set");
			return (NULL);
		}
		printf("%s\n", path);
		return (path);
	}
	return (cmd->args[1]);
}

int	ft_cd(t_shell *shell, t_command *cmd)
{
	char	*path;
	char	old_pwd[PATH_MAX];

	if (cmd->args[1] && cmd->args[2])
	{
		print_cmd_error("cd", "too many arguments");
		return (1);
	}
	path = get_target_path(shell, cmd);
	if (!path)
		return (1);
	ft_bzero(old_pwd, PATH_MAX);
	if (getcwd(old_pwd, PATH_MAX) == NULL)
	{
		if (env_get(shell->env, "PWD"))
			ft_strlcpy(old_pwd, env_get(shell->env, "PWD"), PATH_MAX);
	}
	if (chdir(path) != 0)
	{
		print_cmd_error("cd", strerror(errno));
		return (1);
	}
	update_wds(shell, old_pwd);
	return (0);
}
