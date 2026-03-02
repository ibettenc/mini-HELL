/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:14:17 by ibettenc          #+#    #+#             */
/*   Updated: 2026/02/24 16:15:02 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	append_char(char **res, char c)
{
	char	*tmp;
	char	*new_str;
	int		len;

	if (!res || !*res)
		return ;
	tmp = *res;
	len = ft_strlen(tmp);
	new_str = malloc(len + 2);
	if (!new_str)
		return ;
	ft_memcpy(new_str, tmp, len);
	new_str[len] = c;
	new_str[len + 1] = '\0';
	*res = new_str;
	free(tmp);
}

void	append_str(char **res, char *to_add)
{
	char	*tmp;

	if (!to_add)
		return ;
	tmp = *res;
	*res = ft_strjoin(tmp, to_add);
	free(tmp);
}

int	is_valid_var_char(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0'
			&& c <= '9') || c == '_')
		return (1);
	else
		return (0);
}
