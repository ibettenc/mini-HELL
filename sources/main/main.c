/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:21:34 by niguilbe          #+#    #+#             */
/*   Updated: 2026/01/16 17:23:31 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <readline/history.h>
#include <readline/readline.h>

static void	init_shell(t_shell *shell, char **envp)
{
	shell->env = env_init(envp);
	shell->exit_code = 0;
	shell->cmds = NULL;
	shell->tokens = NULL;
}

static void	process_line(char *line, t_shell *shell)
{
	if (line[0] != '\0')
		add_history(line);
	shell->tokens = lexer(line);
	if (!check_syntax(shell->tokens))
	{
		shell->cmds = parse_tokens(shell->tokens, shell);
		if (shell->cmds)
		{
			if (shell->cmds->next)
				execute_pipeline(shell, shell->cmds);
			else
				execute_single_cmd(shell, shell->cmds);
		}
	}
	else
		printf("Syntax error\n");
}

int	main(int ac, char **av, char **envp)
{
	t_shell		shell;
	char		*line;

	(void)ac;
	(void)av;
	init_shell(&shell, envp);
	while (1)
	{
		init_signals_prompt();
		line = readline("minishell$ ");
		if (!line)
		{
			printf("exit\n");
			clean_exit(&shell, shell.exit_code);
		}
		process_line(line, &shell);
		reset_loop(&shell, line);
	}
	return (0);
}
