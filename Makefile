NAME		:= push_swap

CC			:= cc
CFLAGS		:= -Werror -Wall -Wextra
INCLUDES	:= -I. -Ilibft

SRC_DIR		:= src
ALG_DIR		:= algorithms
OPS_DIR		:= operations
STACK_DIR	:= stack
BENCH_DIR	:= bench
LIBFT_DIR	:= libft

SRC_FILES 	:= \
		main.c \
		handle_algorithms.c \
		handle_error.c \
		parsing_helpers.c \
		parsing_helpers2.c \
		$(ALG_DIR)/simple.c \
		$(OPS_DIR)/swap.c \
		$(OPS_DIR)/push.c \
		$(OPS_DIR)/rotate.c \
		$(OPS_DIR)/reverse_rotate.c \
		$(STACK_DIR)/stack_init.c \
		$(STACK_DIR)/stack_init_two.c \
		$(ALG_DIR)/medium.c \
		$(ALG_DIR)/medium_utils.c \
		$(ALG_DIR)/medium_utils_2.c \
		$(ALG_DIR)/complex.c \
		$(ALG_DIR)/math_operations.c \
		$(BENCH_DIR)/bench.c \
		$(ALG_DIR)/adaptive.c

SRCS 		:= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS 		:= $(SRCS:.c=.o)

LIBFT       := $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
