/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:12:37 by niguilbe          #+#    #+#             */
/*   Updated: 2026/03/05 13:46:52 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
env_new_node     → crée un maillon d’env
env_add_node     → ajoute un maillon à la liste
split_key_value  → sépare "KEY=VALUE" en key + value
env_init         → construit la liste env depuis envp
env_get          → récupère la value d’une key
env_set          → modifie/ajoute une variable
env_unset        → supprime une variable
env_to_array     → convertit la liste en tableau pour execve
ft_strjoin_three → construit "KEY=VALUE"

*/

void	split_key_value(char *str, char **key, char **value)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	*key = ft_substr(str, 0, i);
	if (str[i] == '=')
		*value = ft_strdup(str + i + 1);
	else
		*value = ft_strdup("");
}

t_env	*env_init(char **envp)
{
	t_env	*env;
	t_env	*node;
	char	*key;
	char	*value;
	int		i;

	env = NULL;
	i = 0;
	while (envp[i])
	{
		split_key_value(envp[i], &key, &value);
		node = env_new_node(key, value);
		if (!node)
		{
			free(key);
			free(value);
			env_clear(env);
			return (NULL);
		}
		env_add_node(&env, node);
		i++;
	}
	set_default_pwd(&env);
	return (env);
}

char	*env_get(t_env *env, char *key)
{
	t_env	*tmp;

	if (!key)
		return (NULL);
	tmp = env;
	while (tmp)
	{
		if (ft_strncmp(tmp->key, key, ft_strlen(key) + 1) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void	env_set(t_env **env, char *key, char *value)
{
	t_env	*tmp;

	if (!key)
		return ;
	tmp = *env;
	while (tmp)
	{
		if (ft_strncmp(tmp->key, key, ft_strlen(key) + 1) == 0)
		{
			if (tmp->value)
				free(tmp->value);
			tmp->value = ft_strdup(value);
			return ;
		}
		tmp = tmp->next;
	}
	env_add_node(env, env_new_node(ft_strdup(key), ft_strdup(value)));
}

void	env_unset(t_env **env, char *key)
{
	t_env	*tmp;
	t_env	*prev;

	if (!env || !*env || !key)
		return ;
	tmp = *env;
	prev = NULL;
	while (tmp)
	{
		if (ft_strncmp(tmp->key, key, ft_strlen(key) + 1) == 0)
		{
			if (prev)
				prev->next = tmp->next;
			else
				*env = tmp->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
