/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:00:20 by ibettenc          #+#    #+#             */
/*   Updated: 2025/12/16 12:20:55 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_exit_code(t_shell *shell, int code)
{
	shell->exit_code = code;
}

int	get_exit_code(t_shell *shell)
{
	return (shell->exit_code);
}
