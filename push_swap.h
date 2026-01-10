/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbahry <cbahry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 12:55:28 by adadra            #+#    #+#             */
/*   Updated: 2026/01/09 03:36:03 by cbahry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				rank;
	struct s_stack	*next;
}	t_stack;

typedef enum e_strategy
{
	STRATEGY_SIMPLE,
	STRATEGY_MEDIUM,
	STRATEGY_COMPLEX,
	STRATEGY_ADAPTIVE
}	t_strategy;

typedef struct s_stats
{
	int		total_ops;
	int		sa_count;
	int		sb_count;
	int		ss_count;
	int		pa_count;
	int		pb_count;
	int		ra_count;
	int		rb_count;
	int		rr_count;
	int		rra_count;
	int		rrb_count;
	int		rrr_count;
	float	disorder;
}	t_stats;

typedef struct s_data
{
	t_stack		*a;
	t_stack		*b;
	t_strategy	strategy;
	int			bench;
	t_stats		stats;
}	t_data;

t_stack	*stack_new(int value);
void	stack_print(t_stack *head);
void	stack_push(t_stack **head, t_stack *node);
void	stack_free(t_stack **head);
int		stack_size(t_stack *head);
void	stack_add_last(t_stack **head, t_stack *node);
int		stack_is_sorted(t_stack *head);
void	print_error(t_stack **head);
int		handle_number(long number, int *nb);
long	ft_atol(const char *nptr);
void	print_error_split(t_stack **head, char **numbers);
void	ft_free(char **s);
int		is_number(char *str);
void	is_dublicate(t_stack **head);
int		parse_flags2(char *argv[], int *count, t_data *data);
t_data	data_init(void);
void	print_error_solo(void);
void	stack_free_all(t_data *stack);
void	pa(t_data *stack, int is_print);
void	pb(t_data *stack, int is_print);
void	rra(t_data *stack, int is_separate, int is_print);
void	rrb(t_data *stack, int is_separate, int is_print);
void	rrr(t_data *stack, int is_print);
void	ra(t_data *stack, int is_separate, int is_print);
void	rb(t_data *stack, int is_separate, int is_print);
void	rr(t_data *stack, int is_print);
void	sb(t_data *stack, int is_separate, int is_print);
void	sa(t_data *stack, int is_separate, int is_print);
void	ss(t_data *stack, int is_print);
void	selection_sort(t_data *stack, int is_print);
int		ft_sqrt(float nb);
void	assign_ranks(t_stack *stack_a);
void	push_all_chunks(t_data *stack, int chunk_size, int is_print);
void	push_back_to_a(t_data *stack, int is_print);
void	push_chunk(t_data *stack, int min_rank, int max_rank, int is_print);
void	chunk_sort(t_data *stack, int is_print);
void	bench(t_data data);
float	compute_disorder(t_stack *a);

#endif
