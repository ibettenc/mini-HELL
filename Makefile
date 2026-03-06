# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/08 13:24:55 by niguilbe          #+#    #+#              #
#    Updated: 2026/03/05 14:25:09 by niguilbe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := minishell

CC          := gcc
CFLAGS      := -Wall -Wextra -Werror -fPIC

# === Paths ===
SRC_DIR     := sources
OBJ_DIR     := obj
INC_DIR     := sources/includes
LIBFT_DIR   := libft

# === Libraries ===
LIBFT       := $(LIBFT_DIR)/libft.a

# === Includes ===
INCLUDES    := -I$(INC_DIR) -I$(LIBFT_DIR)

# === Sources ===

# 1. Main
SRCS_MAIN   := main/main.c

# 2. Parsing
SRCS_PARS   := 	parsing/lexer.c \
               	parsing/lexer_extract_functions.c \
            	parsing/check_syntax.c \
        		parsing/expansion.c \
				parsing/expansion_utils.c \
            	parsing/getter_var.c \
            	parsing/parser.c \
            	parsing/parser_utils.c \
            	parsing/exit_code.c

# 3. Environment
SRCS_ENV    :=	env/env.c \
				env/env_utils.c \
				env/env_utils_2.c

# 4. Builtins
SRCS_BUILT  := 	builtins/builtins.c \
				builtins/cd.c \
				builtins/echo.c \
				builtins/exit.c \
				builtins/export.c \
				builtins/ft_env.c \
				builtins/pwd.c \
				builtins/export_utils.c \
				builtins/unset.c 

# 5. Executor

SRCS_EXEC   :=	executor/exec.c \
				executor/exec_utils.c \
            	executor/one_cmd.c \
            	executor/redirections.c \
				executor/pipeline.c \
				executor/heredoc.c \
				memory/clean_memory.c \
				signal/signal.c \
            	utils/exec_utils.c

# Fusion des sources
SRCS        := $(addprefix $(SRC_DIR)/, \
                $(SRCS_MAIN) \
                $(SRCS_PARS) \
                $(SRCS_ENV) \
                $(SRCS_BUILT) \
                $(SRCS_EXEC))

# Objets
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# === Rules ===

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lreadline -o $(NAME)
	@echo "✅ Minishell compiled successfully!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo "🧹 Objects cleaned"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "🗑️  Executable removed"

re: fclean all

.PHONY: all clean fclean re