/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:05:28 by ibettenc          #+#    #+#             */
/*   Updated: 2026/02/24 16:15:24 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* expansion = tranformer les tokens WORD en valeur finale usable par le shell
en remplacant kes	var(iables) d environnement comme $USER

Em gros l’expansion prend ce que l’utilisateur a tapé et
produit la chaîne que le shell doit réellement utiliser 
pour exécuter la commande.

expand_token
 └── expand_word
     ├── expand_dollar
     │   ├── expand_exit_code
     │   └── expand_env_var
     ├── append_char
     └── append_str
    */

void	expand_env_var(t_shell *shell, char *word, char **res, int *i)
{
	int		start;
	int		len;
	char	*var_name;
	char	*value;

	(*i)++;
	start = *i;
	len = 0;
	while (word[*i] && is_valid_var_char(word[*i]))
	{
		(*i)++;
		len++;
	}
	var_name = ft_substr(word, start, len);
	value = getter_var(shell, var_name);
	free(var_name);
	if (value)
		append_str(res, value);
}

void	expand_exit_code(t_shell *shell, char **res, int *i)
{
	char	*tmp;

	tmp = ft_itoa(shell->exit_code);
	if (!tmp)
		return ;
	append_str(res, tmp);
	free(tmp);
	*i += 2;
}

void	expand_dollar(t_shell *shell, char *word, char **res, int *i)
{
	if (word[*i + 1] == '?')
		expand_exit_code(shell, res, i);
	else if (is_valid_var_char(word[*i + 1]))
		expand_env_var(shell, word, res, i);
	else
	{
		append_char(res, '$');
		(*i)++;
	}
}

char	*expand_word(t_shell *shell, char *word)
{
	char	*res;
	int		i;

	if (!word || !shell)
		return (NULL);
	i = 0;
	res = ft_strdup("");
	while (word[i])
	{
		if (word[i] == '$')
			expand_dollar(shell, word, &res, &i);
		else
		{
			append_char(&res, word[i]);
			i++;
		}
	}
	return (res);
}

void	expand_token(t_shell *shell, t_token *token)
{
	char	*expanded;

	if (!token || !token->value)
		return ;
	if (token->is_single_quoted)
		return ;
	if (token->type == WORD)
	{
		expanded = expand_word(shell, token->value);
		free(token->value);
		token->value = expanded;
	}
}
