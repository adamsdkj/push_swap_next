# Push_swap Project Structure  
  
## Directory Layout  
  
```  
push_swap/  
├── Makefile  
├── README.md  
│  
├── includes/  
│   └── push_swap.h          # Main header file  
│  
├── libft/                   # Your libft (copied)  
│   ├── Makefile  
│   ├── libft.h  
│   └── *.c  
│  
├── srcs/  
│   ├── main.c               # Entry point, argument parsing  
│   ├── error.c              # Error handling  
│   │  
│   ├── stack/  
│   │   ├── stack_init.c     # Create/free stacks  
│   │   ├── stack_utils.c    # Stack utilities (size, is_sorted, etc.)  
│   │   └── disorder.c       # Disorder metric calculation  
│   │  
│   ├── operations/  
│   │   ├── swap.c           # sa, sb, ss  
│   │   ├── push.c           # pa, pb  
│   │   ├── rotate.c         # ra, rb, rr  
│   │   └── reverse_rotate.c # rra, rrb, rrr  
│   │  
│   ├── algorithms/  
│   │   ├── simple.c         # O(n²) algorithm  
│   │   ├── medium.c         # O(n√n) algorithm  
│   │   ├── complex.c        # O(n log n) algorithm  
│   │   └── adaptive.c       # Adaptive algorithm  
│   │  
│   └── benchmark/  
│       └── benchmark.c      # --bench mode implementation  
│  
└── bonus/  
    ├── checker_bonus.c      # Bonus checker program  
    └── checker_bonus.h  
```  
  
## Key Header File (push_swap.h)  
  
```c  
#ifndef PUSH_SWAP_H  
# define PUSH_SWAP_H  
  
# include "../libft/libft.h"  
# include <stdlib.h>  
# include <unistd.h>  
  
/* Stack structure */  
typedef struct s_stack  
{  
    int             value;  
    struct s_stack  *next;  
}   t_stack;  
  
/* Strategy type enum */  
typedef enum e_strategy  
{  
    STRATEGY_SIMPLE,  
    STRATEGY_MEDIUM,  
    STRATEGY_COMPLEX,  
    STRATEGY_ADAPTIVE  
}   t_strategy;  
  
/* Benchmark stats structure */  
typedef struct s_stats  
{  
    int     total_ops;  
    int     sa_count;  
    int     sb_count;  
    int     ss_count;  
    int     pa_count;  
    int     pb_count;  
    int     ra_count;  
    int     rb_count;  
    int     rr_count;  
    int     rra_count;  
    int     rrb_count;  
    int     rrr_count;  
    double  disorder;  
}   t_stats;  
  
/* Main program data */  
typedef struct s_data  
{  
    t_stack     *stack_a;  
    t_stack     *stack_b;  
    t_strategy  strategy;  
    int         bench_mode;  
    t_stats     stats;  
}   t_data;  
  
/* === Stack Operations === */  
/* These print the operation AND execute it */  
void    sa(t_data *data);  
void    sb(t_data *data);  
void    ss(t_data *data);  
void    pa(t_data *data);  
void    pb(t_data *data);  
void    ra(t_data *data);  
void    rb(t_data *data);  
void    rr(t_data *data);  
void    rra(t_data *data);  
void    rrb(t_data *data);  
void    rrr(t_data *data);  
  
/* === Stack Management === */  
t_stack *stack_new(int value);  
void    stack_add_front(t_stack **stack, t_stack *new);  
void    stack_add_back(t_stack **stack, t_stack *new);  
void    stack_clear(t_stack **stack);  
int     stack_size(t_stack *stack);  
int     is_sorted(t_stack *stack);  
  
/* === Parsing & Error === */  
t_stack *parse_arguments(int argc, char **argv);  
void    error_exit(char *message);  
int     has_duplicates(t_stack *stack);  
  
/* === Disorder Metric === */  
double  compute_disorder(t_stack *stack);  
  
/* === Sorting Algorithms === */  
void    sort_simple(t_data *data);      // O(n²)  
void    sort_medium(t_data *data);      // O(n√n)  
void    sort_complex(t_data *data);     // O(n log n)  
void    sort_adaptive(t_data *data);    // Adaptive  
  
/* === Benchmark === */  
void    print_benchmark(t_data *data, char *strategy_name);  
  
#endif  
```  
  
## Makefile Structure  
  
```makefile  
# Program names  
NAME        = push_swap  
BONUS       = checker  
  
# Compiler and flags  
CC          = cc  
CFLAGS      = -Wall -Wextra -Werror  
INCLUDES    = -I./includes -I./libft  
  
# Directories  
SRC_DIR     = srcs  
OBJ_DIR     = objs  
BONUS_DIR   = bonus  
  
# Libft  
LIBFT_DIR   = libft  
LIBFT       = $(LIBFT_DIR)/libft.a  
  
# Source files  
SRCS        = $(SRC_DIR)/main.c \  
              $(SRC_DIR)/error.c \  
              $(SRC_DIR)/stack/stack_init.c \  
              $(SRC_DIR)/stack/stack_utils.c \  
              $(SRC_DIR)/stack/disorder.c \  
              $(SRC_DIR)/operations/swap.c \  
              $(SRC_DIR)/operations/push.c \  
              $(SRC_DIR)/operations/rotate.c \  
              $(SRC_DIR)/operations/reverse_rotate.c \  
              $(SRC_DIR)/algorithms/simple.c \  
              $(SRC_DIR)/algorithms/medium.c \  
              $(SRC_DIR)/algorithms/complex.c \  
              $(SRC_DIR)/algorithms/adaptive.c \  
              $(SRC_DIR)/benchmark/benchmark.c  
  
BONUS_SRCS  = $(BONUS_DIR)/checker_bonus.c \  
              $(SRC_DIR)/error.c \  
              $(SRC_DIR)/stack/stack_init.c \  
              $(SRC_DIR)/stack/stack_utils.c \  
              $(SRC_DIR)/operations/swap.c \  
              $(SRC_DIR)/operations/push.c \  
              $(SRC_DIR)/operations/rotate.c \  
              $(SRC_DIR)/operations/reverse_rotate.c  
  
# Object files  
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)  
BONUS_OBJS  = $(BONUS_SRCS:%.c=$(OBJ_DIR)/%.o)  
  
# Colors  
GREEN       = \033[0;32m  
RED         = \033[0;31m  
RESET       = \033[0m  
  
# Rules  
all: $(LIBFT) $(NAME)  
  
$(LIBFT):  
@echo "$(GREEN)Compiling libft...$(RESET)"  
@make -C $(LIBFT_DIR)  
  
$(NAME): $(OBJS)  
@echo "$(GREEN)Linking $(NAME)...$(RESET)"  
@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)  
@echo "$(GREEN)$(NAME) created successfully!$(RESET)"  
  
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c  
@mkdir -p $(dir $@)  
@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@  
  
bonus: $(LIBFT) $(BONUS)  
  
$(BONUS): $(BONUS_OBJS)  
@echo "$(GREEN)Linking $(BONUS)...$(RESET)"  
@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS)  
@echo "$(GREEN)$(BONUS) created successfully!$(RESET)"  
  
clean:  
@echo "$(RED)Cleaning objects...$(RESET)"  
@rm -rf $(OBJ_DIR)  
@make -C $(LIBFT_DIR) clean  
  
fclean: clean  
@echo "$(RED)Removing executables...$(RESET)"  
@rm -f $(NAME) $(BONUS)  
@make -C $(LIBFT_DIR) fclean  
  
re: fclean all  
  
.PHONY: all clean fclean re bonus  
```  
  
## Notes  
  
1. **Separation of concerns**: Each algorithm gets its own file  
2. **Operations folder**: All 11 operations in organized files  
3. **Libft integration**: Compiled first, linked with your program  
4. **Bonus separation**: Bonus files use `_bonus` suffix as required  
5. **Stats tracking**: The `t_stats` structure tracks operation counts for --bench mode  
  
## Getting Started  
  
1. Copy your libft into the project root  
2. Create the directory structure  
3. Start with `stack_init.c` and `operations/swap.c`  
4. Implement `main.c` to parse arguments  
5. Test each operation individually before moving to algorithms