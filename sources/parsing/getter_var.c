/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:49:29 by ibettenc          #+#    #+#             */
/*   Updated: 2026/02/24 16:11:58 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*getter_var(t_shell *shell, char *path)
{
	char	*code;

	if (ft_strncmp(path, "?", 1) == 0)
	{
		code = ft_itoa(shell->exit_code);
		return (code);
	}
	return (env_get(shell->env, path));
}
