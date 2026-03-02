/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:53:03 by niguilbe          #+#    #+#             */
/*   Updated: 2026/01/16 16:35:41 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// trouver le bon binaire à exécuter

char	*joint_path(char *path, char *cmd)
{
	char	*whole;
	int		len;

	len = ft_strlen(path) + 1 + ft_strlen(cmd) + 1;
	whole = malloc(len);
	if (!whole)
		return (NULL);
	ft_strlcpy(whole, path, len);
	ft_strlcat(whole, "/", len);
	ft_strlcat(whole, cmd, len);
	return (whole);
}

char	*find_path(char *cmd, char **env_array)
{
	int		i;
	char	*whole;
	char	**path;

	i = 0;
	while (env_array[i] && ft_strncmp(env_array[i], "PATH=", 5) != 0)
		i++;
	if (!env_array[i])
		return (ft_putstr_fd("pipex: PATH not found in environment\n", 2),
			NULL);
	path = ft_split(env_array[i] + 5, ':');
	if (!path)
		return (NULL);
	i = 0;
	while (path[i])
	{
		whole = joint_path(path[i], cmd);
		if (!whole)
			break ;
		if (access(whole, X_OK) == 0)
			return (free_strs(path), whole);
		free(whole);
		i++;
	}
	return (free_strs(path), NULL);
}

char	*resolve_cmd_path(char *cmd, char **envp) // pour le cas s
{
	if (!cmd || !*cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	return (find_path(cmd, envp));
}
