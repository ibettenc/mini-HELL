# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibettenc <ibettenc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/08 13:24:55 by niguilbe          #+#    #+#              #
#    Updated: 2026/02/24 16:17:22 by ibettenc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := minishell

CC          := gcc
CFLAGS      := -Wall -Wextra -Werror

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

# 2. Parsing (Partie Mate)
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
SRCS_ENV    := env/env.c

# 4. Builtins (Dossier séparé)
SRCS_BUILT  := 	builtins/builtins.c \
				builtins/cd.c \
				builtins/echo.c \
				builtins/exit.c \
				builtins/export.c \
				builtins/ft_env.c \
				builtins/pwd.c \
				builtins/unset.c 

# 5. Executor

SRCS_EXEC   :=	executor/exec.c \
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