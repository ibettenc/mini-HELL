/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:37:23 by niguilbe          #+#    #+#             */
/*   Updated: 2026/03/05 15:32:02 by niguilbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* --- INCLUDES --- */
# include "../libft/libft.h" // Verifie que le chemin est bon
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/stat.h>

/* =============================== STRUCTURES ============================ */

/* 3. Enum Tokens */
typedef enum e_token_type
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	HEREDOC,
	APPEND
}	t_token_type;

/* 1. Environnement */
typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

/* 6. Tokens (Lexer Result) */
typedef struct s_token
{
	t_token_type	type;
	int				n_token;
	int				is_single_quoted;
	int				is_from_var;
	char			*value;
	struct s_token	*next;
}					t_token;

/* 4. Redirections (Liste Chainée) */
typedef struct s_redir
{
	t_token_type	type;// REDIR_IN, REDIR_OUT, HEREDOC, APPEND
	char			*file;// Nom du fichier OU terminateur heredoc (EOF)
	struct s_redir	*next;
}					t_redir;

/* 5. Commandes (Parsing Result) */
typedef struct s_command
{
	char				**args;// Ancien "argv"
	t_redir				*redirs;// Liste des redirections
	struct s_command	*next;// Prochaine commande (Pipe)
}					t_command;

/* 2. Shell Global */
typedef struct s_shell
{
	t_env		*env;
	t_token		*tokens; //pour stocker les tokens et pouvoir free pdt exit
	t_command	*cmds; //tete de liste des commandes pour pouvoir free pdt exit
	int			exit_code;
}	t_shell;

/* =============================== FUNCTIONS =============================== */

// ------------------------ /* --- BUILTINS --- */ ------------------------- //
// Builtins.c
int					is_builtin(char *cmd);
int					is_parent_builtin(char *cmd);
int					exec_builtin(t_shell *sh, t_command *cmd);
int					ft_echo(t_command *cmd);
int					ft_pwd(void);
int					ft_env(t_shell *sh);
int					ft_exit(t_shell *shell, t_command *cmd);

// cd.c
int					ft_cd(t_shell *shell, t_command *cmd);

// export.c
int					ft_export(t_shell *shell, t_command *cmd);

// export_utils.c

void				sort_env_array(char **tab, int size);
int					ft_strcmp(char *s1, char *s2);
char				**get_export_array(t_env *env, int count);

// unset.c
int					ft_unset(t_shell *shell, t_command *cmd);

// ------------------------ // --- ENV --- // ------------------------------ //

// Env.c
t_env				*env_init(char **envp);
char				*env_get(t_env *env, char *key);
void				env_set(t_env **env, char *key, char *value);
void				env_unset(t_env **env, char *key);
void				split_key_value(char *str, char **key, char **value);

// Env_utils.c
struct s_env		*env_new_node(char *key, char *value);
void				env_add_node(t_env **env, t_env *new);
char				**env_to_array(t_env *env);
char				*ft_strjoin_three(char *s1, char *s2, char *s3);
void				env_clear(t_env *env);

//Env_utils_2.c 
void				set_default_pwd(t_env **env);

// ------------------------ // --- EXECUTOR  --- // ------------------------ //

// Exec.c
char				*find_path(char *cmd, char **env_array);
char				*joint_path(char *path, char *cmd);
char				*resolve_cmd_path(char *cmd, char **envp);

// One_cmd.c
int					exec_external_child(t_shell *sh, t_command *cmd);
void				execute_single_cmd(t_shell *sh, t_command *cmd);

// Pipeline.c
void				execute_pipeline(t_shell *shell, t_command *cmd);

// Redirections.c
int					apply_redirections(t_command *cmd);

// Heredoc.c
int					handle_heredoc(char *delimiter);

// exec_utils.c
int					wait_exit_code(pid_t pid);
int					check_directory_error(char *cmd_name);

// ------------------------ // --- MEMORY --- // --------------------------- //

// clean_memory.c
void				reset_loop(t_shell *shell, char *line);
void				clean_exit(t_shell *shell, int exit_code);
void				free_tokens(t_token *tokens);
void				free_commands(t_command *cmds);

// ------------------------ // --- SIGNAL --- // --------------------------- //

// signal.c
void				handle_sigint_at_prompt(int sig);
void				init_signals_prompt(void);
void				init_signals_execution(void);

// ------------------------ // --- PARSING --- // -------------------------- //

// check_syntax.c
int					check_syntax(t_token *tokens);

// exit_code.c
void				set_exit_code(t_shell *shell, int code);
int					get_exit_code(t_shell *shell);

// expansion.c
void				expand_env_var(t_shell *shell, char *word, char **res,
						int *i);
void				expand_exit_code(t_shell *shell, char **res, int *i);
void				expand_dollar(t_shell *shell, char *word, char **res,
						int *i);
char				*expand_word(t_shell *shell, char *word);
void				expand_token(t_shell *shell, t_token *token);

// expansion_utils.c
void				append_char(char **res, char c);
void				append_str(char **res, char *to_add);
int					is_valid_var_char(char c);

// getter_var.c
char				*getter_var(t_shell *shell, char *path);

// lexer_extract_functions.c
char				*extract_single_quoted(char *line, int *i);
char				*extract_double_quoted(char *line, int *i);
char				*extract_word(char *line, int *i);
void				extract_double_sign(t_token **tokens, char *line, int *i,
						int *n);
void				extract_single_sign(t_token **tokens, char *line, int *i,
						int *n);

// lexer.c
void				add_token(t_token **list, t_token_type type, char *value,
						int n);
t_token				*lexer(char *line);

// parser_utils.c
void				expand_token(t_shell *shell, t_token *token);
void				add_word_to_cmd(t_command *cmd, char *word);
void				add_redir_to_cmd(t_command *cmd, t_token_type type,
						char *file);
void				print_commands(t_command *cmds);

// parser.c
void				handle_word_and_redir(t_token *token, t_command **cmd_list,
						t_command **current_cmd, t_shell *shell);
void				handle_pipe(t_command **current_cmd);
void				handle_token(t_token *token, t_command **cmd_list,
						t_command **current_cmd, t_shell *shell);
t_command			*parse_tokens(t_token *tokens, t_shell *shell);

// cleanup.c
void				free_commands(t_command *cmds);
void				free_tokens(t_token *tokens);

// ------------------------- // --- UTILS --- // --------------------------- //

// exec_utils.c
void				free_strs(char **strs);
void				free_env(t_env *env);
void				free_commands(t_command *cmd);
void				print_cmd_error(char *cmd, char *msg);

#endif