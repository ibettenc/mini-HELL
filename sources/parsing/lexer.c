/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:55:57 by ibettenc          #+#    #+#             */
/*   Updated: 2026/03/02 17:05:53 by ibettenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	add_token(t_token **list, t_token_type type, char *value, int n)
{
	t_token	*token;
	t_token	*current;

	token = malloc(sizeof(t_token));
	if (!token)
		return ;
	token->type = type;
	token->value = value;
	token->n_token = n;
	token->is_single_quoted = 0;
	token->is_from_var = 0;
	token->next = NULL;
	if (*list == NULL)
		*list = token;
	else
	{
		current = *list;
		while (current->next)
			current = current->next;
		current->next = token;
	}
}

static char	*next_part(char *line, int *i, int *is_sq)
{
	if (line[*i] == '\'')
	{
		*is_sq = 1;
		return (extract_single_quoted(line, i));
	}
	else if (line[*i] == '"')
		return (extract_double_quoted(line, i));
	return (extract_word(line, i));
}

static void	build_word(t_token **tokens, char *line, int *i, int *n)
{
	char	*value;
	char	*part;
	int		is_sq;
	int		starts_with_var;
	t_token	*last;

	value = ft_strdup("");
	is_sq = 0;
	starts_with_var = (line[*i] == '$');
	while (line[*i] && line[*i] != ' ' && line[*i] != '\t'
		&& line[*i] != '|' && line[*i] != '<' && line[*i] != '>')
	{
		part = next_part(line, i, &is_sq);
		value = ft_strjoin(value, part);
		free(part);
	}
	add_token(tokens, WORD, value, (*n)++);
	last = *tokens;
	while (last->next)
		last = last->next;
	last->is_single_quoted = is_sq;
	last->is_from_var = starts_with_var;
}

static void	process_token(t_token **tokens, char *line, int *i, int *n)
{
	if ((line[*i] == '<' && line[*i + 1] == '<')
		|| (line[*i] == '>' && line[*i + 1] == '>'))
		return (extract_double_sign(tokens, line, i, n));
	if (line[*i] == '|' || line[*i] == '<' || line[*i] == '>')
		return (extract_single_sign(tokens, line, i, n));
	build_word(tokens, line, i, n);
}

t_token	*lexer(char *line)
{
	t_token	*tokens;
	int		i;
	int		n;

	tokens = NULL;
	i = 0;
	n = 0;
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t')
			(i)++;
		if (!line[i])
			break ;
		process_token(&tokens, line, &i, &n);
	}
	return (tokens);
}
