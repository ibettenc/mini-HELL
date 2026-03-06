/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 13:32:57 by niguilbe          #+#    #+#             */
/*   Updated: 2026/03/05 15:31:36 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	sort_env_array(char **tab, int size)
{
	int		i;
	int		j;
	int		sorted;
	char	*tmp;

	i = 0;
	while (i < size - 1)
	{
		sorted = 1;
		j = 0;
		while (j < size - 1 - i)
		{
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
				sorted = 0;
			}
			j++;
		}
		if (sorted)
			break ;
		i++;
	}
}

char	**get_export_array(t_env *env, int count)
{
	char	**tab;
	int		i;

	tab = malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (env)
	{
		if (env->value)
			tab[i] = ft_strjoin_three(env->key, "=", env->value);
		else
			tab[i] = ft_strdup(env->key);
		i++;
		env = env->next;
	}
	tab[i] = NULL;
	return (tab);
}
