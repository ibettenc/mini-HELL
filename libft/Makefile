# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niguilbe <niguilbe@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/30 11:59:01 by niguilbe          #+#    #+#              #
#    Updated: 2025/08/25 12:35:27 by niguilbe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

# Sources de la libft
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_calloc.c \
		ft_strdup.c 

# Sources de get_next_line
SRCS_GNL = get_next_line.c

# Sources de ft_printf
SRCS_PRINTF = ft_printf.c ft_printchar.c ft_printstr.c ft_printnbr.c \
			  ft_printuns.c ft_printptr.c ft_printnbr_base.c

# Toutes les sources
SRCS_ALL = $(SRCS) $(SRCS_GNL) $(SRCS_PRINTF)

# Objets
OBJS = $(SRCS_ALL:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
