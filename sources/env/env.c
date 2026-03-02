/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:12:37 by niguilbe          #+#    #+#             */
/*   Updated: 2026/01/16 17:22:42 by niguilbe         ###   ########.fr       */
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

t_env	*env_new_node(char *key, char *value)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	node->key = key;
	node->value = value;
	node->next = NULL;
	return (node);
}

void	env_add_node(t_env **env, t_env *new)
{
	t_env	*tmp;

	if (!*env)
	{
		*env = new;
		return ;
	}
	tmp = *env;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

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
	char	cwd[PATH_MAX];

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
	if (!env_get(env, "PWD"))
	{
		if (getcwd(cwd, PATH_MAX))
			env_set(&env, "PWD", cwd);
	}
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

char	**env_to_array(t_env *env)
{
	int		count;
	t_env	*tmp;
	char	**arr;
	int		i;

	count = 0;
	tmp = env;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	arr = malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (NULL);
	tmp = env;
	i = 0;
	while (tmp)
	{
		arr[i] = ft_strjoin_three(tmp->key, "=", tmp->value);
		i++;
		tmp = tmp->next;
	}
	arr[i] = NULL;
	return (arr);
}

char	*ft_strjoin_three(char *s1, char *s2, char *s3)
{
	char	*tmp;
	char	*res;

	tmp = ft_strjoin(s1, s2);
	if (!tmp)
		return (NULL);
	res = ft_strjoin(tmp, s3);
	free(tmp);
	return (res);
}

void	env_clear(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env->next;
		if (env->key)
			free(env->key);
		if (env->value)
			free(env->value);
		free (env);
		env = tmp;
	}
}
