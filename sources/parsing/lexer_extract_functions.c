/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_extract_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 18:33:05 by ibettenc          #+#    #+#             */
/*   Updated: 2026/03/02 17:04:33 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*extract_word(char *line, int *i)
{
	int		start;
	int		len;
	char	*value;
	int		j;

	start = *i;
	while (line[*i] && line[*i] != ' ' && line[*i] != '\t'
		&& line[*i] != '"' && line[*i] != '\''
		&& line[*i] != '|' && line[*i] != '<' && line[*i] != '>')
		(*i)++;
	len = *i - start;
	value = malloc(sizeof(char) * (len + 1));
	if (!value)
		return (NULL);
	j = 0;
	while (j < len)
	{
		value[j] = line[start + j];
		j++;
	}
	value[j] = '\0';
	return (value);
}

char	*extract_double_quoted(char *line, int *i)
{
	char	*value;
	int		start;
	int		len;
	int		j;

	(*i)++;
	start = *i;
	while (line[*i] && line[*i] != '"')
		(*i)++;
	len = *i - start;
	value = malloc(len + 1);
	if (!value)
		return (NULL);
	j = 0;
	while (j < len)
	{
		value[j] = line[start + j];
		j++;
	}
	value[len] = '\0';
	if (line[*i] == '"')
		(*i)++;
	return (value);
}

char	*extract_single_quoted(char *line, int *i)
{
	char	*value;
	int		start;
	int		len;
	int		j;

	(*i)++;
	start = *i;
	while (line[*i] && line[*i] != '\'')
		(*i)++;
	len = *i - start;
	value = malloc(len + 1);
	if (!value)
		return (NULL);
	j = 0;
	while (j < len)
	{
		value[j] = line[start + j];
		j++;
	}
	value[len] = '\0';
	if (line[*i] == '\'')
		(*i)++;
	return (value);
}

void	extract_double_sign(t_token **tokens, char *line, int *i, int *n)
{
	if (line[*i] == '<' && line[*i + 1] && line[*i + 1] == '<')
	{
		add_token(tokens, HEREDOC, NULL, (*n)++);
		*i += 2;
	}
	else if (line[*i] == '>' && line[*i + 1] && line[*i + 1] == '>')
	{
		add_token(tokens, APPEND, NULL, (*n)++);
		*i += 2;
	}
}

void	extract_single_sign(t_token **tokens, char *line, int *i, int *n)
{
	if (line[*i] == '|')
		add_token(tokens, PIPE, NULL, (*n)++);
	else if (line[*i] == '<')
		add_token(tokens, REDIR_IN, NULL, (*n)++);
	else if (line[*i] == '>')
		add_token(tokens, REDIR_OUT, NULL, (*n)++);
	(*i)++;
}
