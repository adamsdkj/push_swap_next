# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbahry <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 16:57:33 by cbahry            #+#    #+#              #
#    Updated: 2025/12/22 23:27:11 by cbahry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf

YELLOW = \033[0;33m
GREEN = \033[0;32m
BLUE = \033[0;34m
RESET = \033[0m

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	   ft_isascii.c ft_isprint.c ft_strlen.c \
	   ft_memset.c ft_bzero.c ft_memcpy.c \
	   ft_memmove.c ft_strlcpy.c ft_strlcat.c \
	   ft_toupper.c ft_tolower.c ft_strchr.c \
	   ft_strrchr.c ft_strncmp.c ft_memchr.c \
	   ft_memcmp.c ft_strnstr.c ft_atoi.c \
	   ft_calloc.c ft_strdup.c ft_substr.c \
	   ft_strjoin.c ft_strtrim.c ft_split.c \
	   ft_itoa.c ft_strmapi.c ft_striteri.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	   ft_putnbr_fd.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	   ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c \
	   ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstlast_bonus.c \
	   ft_printf.c hex_print_utils.c int_print_utils.c \
	   str_print_utils.c unsigned_int_utils.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)Creating library $(NAME)...$(RESET)"
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)Library built successfully!$(RESET)"

%.o:%.c
	@echo "$(YELLOW)Compiling $(RESET)$<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(BLUE)Cleaning object files...$(RESET)"
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	@echo "$(BLUE)Removing library $(NAME)...$(RESET)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
