/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadra <adadra@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-31 12:55:28 by adadra            #+#    #+#             */
/*   Updated: 2025-12-31 12:55:28 by adadra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
}	t_data;

t_stack	*stack_new(int value);
void	stack_print(t_stack *head);
void	stack_push(t_stack **head, t_stack *node);
void	stack_free(t_stack **head);
int		stack_size(t_stack *head);

#endif
