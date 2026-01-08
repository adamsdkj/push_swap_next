/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbahry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:59:44 by cbahry            #+#    #+#             */
/*   Updated: 2026/01/08 01:50:27 by cbahry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	pa(t_data *stack)
{
	t_stack	*first_a;
	t_stack	*first_b;

	if (!stack || !stack->b)
		return ;
	first_a = stack->a;
	first_b = stack->b;
	stack->b = stack->b->next;
	first_b->next = first_a;
	stack->a = first_b;
	stack->stats.pa_count += 1;
	stack->stats.total_ops += 1;
	write(1, "pa\n", 3);
}

void	pb(t_data *stack)
{
	t_stack	*first_a;
	t_stack	*first_b;

	if (!stack || !stack->a)
		return ;
	first_a = stack->a;
	first_b = stack->b;
	stack->a = stack->a->next;
	first_a->next = first_b;
	stack->b = first_a;
	stack->stats.pb_count += 1;
	stack->stats.total_ops += 1;
	write(1, "pb\n", 3);
}
