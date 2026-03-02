/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 19:06:30 by niguilbe          #+#    #+#             */
/*   Updated: 2026/01/16 17:29:42 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	is_valid_env_key(char *str)
{
	int	i;

	i = 0;
	if (!str || (!ft_isalpha(str[0]) && str[0] != '_'))
		return (0);
	i++;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static void	process_export_arg(t_shell *shell, char *arg)
{
	char	*key;
	char	*value;
	char	*equal_sign;

	equal_sign = ft_strchr(arg, '=');
	if (equal_sign)
	{
		key = ft_substr(arg, 0, equal_sign - arg);
		value = ft_strdup(equal_sign + 1);
		if (key && value)
			env_set(&shell->env, key, value);
		free(key);
		free(value);
	}
	else
		return ;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static void	sort_env_array(char **tab, int size)
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

static void	print_export_line(char *str)
{
	int	i;

	ft_putstr_fd("declare -x ", 1);
	i = 0;
	while (str[i] && str[i] != '=')
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	if (str[i] == '=')
	{
		ft_putchar_fd('=', 1);
		ft_putchar_fd('"', 1);
		ft_putstr_fd(str + i + 1, 1);
		ft_putchar_fd('"', 1);
	}
	ft_putchar_fd('\n', 1);
}

static int	export_display(t_shell *shell)
{
	char	**tab;
	int		i;
	int		count;

	tab = env_to_array(shell->env);
	if (!tab)
		return (1);
	count = 0;
	while (tab[count])
		count++;
	sort_env_array(tab, count);
	i = 0;
	while (tab[i])
	{
		print_export_line(tab[i]);
		i++;
	}
	free_strs(tab);
	return (0);
}

int	ft_export(t_shell *shell, t_command *cmd)
{
	int	i;
	int	exit_status;

	exit_status = 0;
	if (!cmd->args[1])
		return (export_display(shell));
	i = 1;
	while (cmd->args[i])
	{
		if (!is_valid_env_key(cmd->args[i]))
		{
			ft_putstr_fd("minishell: export: '", 2);
			ft_putstr_fd(cmd->args[i], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			exit_status = 1;
		}
		else
			process_export_arg(shell, cmd->args[i]);
		i++;
	}
	return (exit_status);
}
