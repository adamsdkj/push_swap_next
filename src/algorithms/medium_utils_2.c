/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbahry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 01:40:14 by cbahry            #+#    #+#             */
/*   Updated: 2026/01/09 01:40:14 by cbahry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	find_max_pos(t_stack *b)
{
	int	max;
	int	pos;
	int i;

	max = b->rank;
	pos = 0;
	i = 0;
	while (b)
	{
		if (b->rank > max)
		{
			max = b->rank;
			pos = i;
		}
		b = b->next;
		i++;
	}
	return (pos);
}

int	find_max_rank(t_stack *b)
{
	int		max_rank;
	t_stack	*current;

	if (!b)
		return (-1);
	max_rank = b->rank;
	current = b->next;
	while (current)
	{
		if (current->rank > max_rank)
			max_rank = current->rank;
		current = current->next;
	}
	return (max_rank);
}

void	push_back_to_a(t_data *stack)
{
	int	pos;
	int	size;
	int	max_rank;

	while (stack->b)
	{
		size = stack_size(stack->b);
		pos = find_max_pos(stack->b);
		max_rank = find_max_rank(stack->b);
		if (pos <= size / 2)
		{
			while (stack->b->rank != max_rank)
				rb(stack, 1);
		}
		else
		{
			while (stack->b->rank != max_rank)
				rrb(stack, 1);
		}
		pa(stack);
	}
}
