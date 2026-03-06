/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:46:36 by niguilbe          #+#    #+#             */
/*   Updated: 2026/03/05 14:11:36 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_default_pwd(t_env **env)
{
	char	cwd[PATH_MAX];

	if (!env_get(*env, "PWD"))
	{
		if (getcwd(cwd, PATH_MAX))
			env_set(env, "PWD", cwd);
	}
}
